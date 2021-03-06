#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP

#include <fstream>
#include <math.h>
#include <random>
#include <vector>

#include <Eigen/Dense>
#include <Eigen/SparseCore>
#include <stan/math/prim/fun.hpp>
#include <stan/math/prim/prob.hpp>

#include "../collectors/chain_state.pb.h"
#include "../collectors/FileCollector.hpp"
#include "../collectors/MemoryCollector.hpp"


//! Abstract template class for a Gibbs sampling iterative BNP algorithm.

//! This template class implements a generic algorithm that generates a Markov
//! chain on the clustering of the provided data.
//!
//! An algorithm that inherits from this abstract class will have multiple
//! iterations of the same step. Steps are further split into substeps, each of
//! which updates specific values of the state of the Markov chain, which is
//! composed of the allocations vector and the unique values vector (see below).
//! This is known as a Gibbs sampling structure, where a set of values is
//! updated according to a conditional distribution given all other values.
//! The underlying model for the data is assumed to be a so-called hierarchical
//! model, where each datum is independently drawn from a common likelihood
//! function, whose parameters are specific to each unit and are iid generated
//! from a random probability measure, called the mixture. Different data points
//! may have the same parameters as each other, and thus a clustering structure
//! on data emerges, with each cluster being identified by its own parameters,
//! called unique values. These will often be generated from the centering
//! distribution, which is the expected value of the mixture, or from its
//! posterior update. The allocation of a datum is instead the label that
//! indicates the cluster it is currently assigned to. The probability
//! distribution for data from each cluster is called a hierarchy and it can
//! have its own hyperparameters, either random themselves or fixed. The model
//! therefore is:
//!   x_i ~ f(x_i|phi_(c_i))  (data likelihood);
//! phi_c ~ G                 (unique values distribution);
//!     G ~ MM                (mixture model);
//!  E[G] = G0                (centering distribution),
//! where c_i is the allocation of the i-th datum.
//!
//! This class is templatized over the types of the elements of this model: the
//! hierarchies of cluster, their hyperparameters, and the mixture.

//! \param Hierarchy Name of the hierarchy template class
//! \param Hypers    Name of the hyperparameters class
//! \param Mixture   Name of the mixture class

template<template <class> class Hierarchy, class Hypers, class Mixture>
class Algorithm{
protected:
    // METHOD PARAMETERS
    //! Iterations of the algorithm
    unsigned int maxiter = 1000;
    //! Number of burn-in iterations, which will be discarded
    unsigned int burnin = 100;

    // DATA AND VALUES CONTAINERS
    //! Matrix of row-vectorial data points
    Eigen::MatrixXd data;
    //! Prescribed number of clusters for the algorithm initialization
    unsigned int init_num_clusters;
    //! Cardinalities of clusters
    std::vector<unsigned int> cardinalities;
    //! Allocation for each datum, i.e. label of the cluster it belongs to
    std::vector<unsigned int> allocations;
    //! Hierarchy of the unique values that identify each cluster
    std::vector< Hierarchy<Hypers> > unique_values;
    //! Grid of points and evaluation of density on it
    std::pair< Eigen::MatrixXd, Eigen::VectorXd > density;
    //! Mixture object
    Mixture mixture;
    //! Protobuf object that contains the best clustering
    State best_clust;
    //! Random engine
    std::mt19937 rng;

    // FLAGS
    //! Flag to check validity of density write function
    bool density_was_computed = false;
    //! Flag to check validity of clustering write function
    bool clustering_was_computed = false;

    // AUXILIARY TOOLS
    //! Returns the values of an algo iteration as a Protobuf object
    State get_state_as_proto(unsigned int iter);
    //! Turns a single unique value from Protobuf object form into a matrix
    Eigen::MatrixXd proto_param_to_matrix(const Param &par) const;
    //! Computes marginal contribution of a given iteration & cluster
    virtual Eigen::VectorXd density_marginal_component(
        Hierarchy<Hypers> &temp_hier) = 0;

    // ALGORITHM FUNCTIONS
    virtual void print_startup_message() const = 0;
    virtual void initialize() = 0;
    virtual void sample_allocations() = 0;
    virtual void sample_unique_values() = 0;
    virtual void sample_weights() = 0;
    virtual void update_hypers() = 0;
    virtual void print_ending_message() const;
    //! Saves the current iteration's state in Protobuf form to a collector
    void save_state(BaseCollector* collector, unsigned int iter){
        collector->collect( get_state_as_proto(iter) );
    }

    //! Single step of algorithm
    void step(){
        sample_allocations();
        sample_unique_values();
        sample_weights();
        update_hypers();
    }

public:
    //! Runs the algorithm and saves the whole chain to a collector
    void run(BaseCollector* collector){
        print_startup_message();
        initialize();
        unsigned int iter = 0;
        collector->start();
        while(iter < maxiter){
            step();
            if(iter >= burnin){
              save_state(collector, iter);
            }
            iter++;
        }
        collector->finish();
        print_ending_message();
    }

    // ESTIMATE FUNCTIONS
    //! Evaluates the overall data pdf on a gived grid of points
    virtual void eval_density(const Eigen::MatrixXd &grid,
        BaseCollector* const collector);
    //! Estimates the clustering structure of the data via LS minimization
    virtual unsigned int cluster_estimate(BaseCollector* collector);
    //! Writes unique values of each datum in csv form
    void write_clustering_to_file(const std::string &filename =
        "csv/clust_best.csv") const;
    //! Writes grid and density evaluation on it in csv form
    void write_density_to_file(const std::string &filename =
        "csv/density.csv") const;

    // DESTRUCTOR AND CONSTRUCTORS
    virtual ~Algorithm() = default;
    //! \param hypers_  Hyperparameters object for the model
    //! \param mixture_ Mixture object for the model
    //! \param data_    Matrix of row-vectorial data points
    //! \param init     Prescribed n. of clusters for the algorithm initializ.
    Algorithm(const Hypers &hypers_, const Mixture &mixture_,
        const Eigen::MatrixXd &data_, const unsigned int init = 0) :
        mixture(mixture_), data(data_), init_num_clusters(init) {
        Hierarchy<Hypers> hierarchy( std::make_shared<Hypers>(hypers_) );

            if(hierarchy.is_multivariate() == false && data.cols() > 1){
                std::cout << "Warning: multivariate data supplied to " <<
                    "univariate hierarchy. The algorithm will run " <<
                    "correctly, but all data rows other than the first" <<
                    "one will be ignored" << std::endl;
            }
            if(data.rows() == 0){
                init_num_clusters = 1;            
            }
            if(init_num_clusters == 0){
                // If not provided, standard initializ.: one datum per cluster
                std::cout << "Warning: initial number of clusters will be " <<
                    "set equal to the data size (" << data.rows() << ")" <<
                    std::endl;
                init_num_clusters = data.rows();
            }

            // Initialize hierarchies for starting clusters
            for(size_t i = 0; i < init_num_clusters; i++){
                unique_values.push_back(hierarchy);
            }
    }

    // GETTERS AND SETTERS
    unsigned int get_maxiter() const {return maxiter;}
    unsigned int get_burnin() const {return burnin;}
    unsigned int get_init_num_clusters() const {return init_num_clusters;}
    std::pair< Eigen::MatrixXd, Eigen::VectorXd > get_density() const {
        if(!density_was_computed){
            std::domain_error("Error calling get_density(): not computed yet");
        }
        return density;
    }

    void set_maxiter(const unsigned int maxiter_){maxiter = maxiter_;}
    void set_burnin(const unsigned int burnin_){burnin = burnin_;}
    void set_init_num_clusters(const unsigned int init){
        init_num_clusters = init;
    }
    void set_rng_seed(const unsigned int seed){rng.seed(seed);}
    //! Does nothing except for Neal8
    virtual void set_n_aux(const unsigned int n_aux_){return;}
};

#include "Algorithm.imp.hpp"

#endif // ALGORITHM_HPP
