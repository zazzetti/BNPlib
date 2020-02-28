#ifndef NEAL8_HPP
#define NEAL8_HPP

#include <fstream>
#include <math.h>
#include <tuple>
#include <vector>

#include <Eigen/Dense>
#include <stan/math/prim/mat.hpp>

#include "../hyperparameters/HypersFixedNNIG.hpp"
#include "../hierarchies/HierarchyNNIG.hpp"
#include "../../output.pb.h"
#include "../mixtures/DirichletMixture.hpp"

// Normal likelihoood, Normal-InverseGamma hierarchy, that is:
// f ~ N(mu,sig^2)
// (mu,sig^2) ~ G
// G ~ DP(M, G0)  with G0 = N-IG

template<template <class> class Hierarchy, class Hypers, class Mixture>
class Neal8{
private:
    // Mehtods parameters
    unsigned int n_aux = 3;
    unsigned int maxiter = 20000;
    unsigned int burnin = 5000;
    unsigned int num_clusters;

    // Data and values containers
    std::vector<double> data;
    std::vector<unsigned int> allocations;
    std::vector<Hierarchy<Hypers>> unique_values;
    std::vector<Hierarchy<Hypers>> aux_unique_values;
    std::pair< std::vector<double>, Eigen::VectorXd > density;
    Mixture mixture;
    ChainOutput chain;
    IterationOutput best_clust;

    // Random engine
    std::mt19937 rng;

    // Algorithm functions
    void initialize();

    void step(){
        sample_allocations();
        sample_unique_values();
    }

    void sample_allocations();

    void sample_unique_values();

    void save_iteration(unsigned int iter);

    const void print_state();

public:
    // Running tool
    void run(){
        std::cout << "Running Neal8" << std::endl;
        initialize();
        unsigned int iter = 0;
        while(iter < maxiter){
            step();
            if(iter >= burnin){
              save_iteration(iter);
            }
            iter++;
        }
        std::cout << "Done" << std::endl;
    }

    void run_and_save_cards(){
    std::ofstream file;
    file.open("clust_cardinalities.csv");
        std::cout << "Running Neal8" << std::endl;
        initialize();
        unsigned int iter = 0;
        while(iter < maxiter){
            std::cout << "Iteration # " << iter << " / " <<
                maxiter << std::endl; // DEBUG
            step();
            if(iter >= burnin){
              save_iteration(iter);
              file << unique_values.size() << ",";
            }
            iter++;
        }
        std::cout << "Done" << std::endl;
        file << std::endl;
        file.close();
    }

    // Other tools
    unsigned int cluster_estimate();

    void eval_density(const std::vector<double> grid);

    const void write_final_clustering_to_file(
        std::string filename = "clust_final.csv");

    const void write_best_clustering_to_file(
        std::string filename = "clust_best.csv");

    const void write_chain_to_file(
        std::string filename = "chain.csv");

    const void write_density_to_file(
        std::string filename = "density.csv");

    // Constructors and destructors
    ~Neal8() = default;
    Neal8(const std::vector<double> &data, int num_clusters, int n_aux,
        const Mixture &mix, const Hypers &hy):
        data(data), num_clusters(num_clusters), n_aux(n_aux), mixture(mix) {
            Hierarchy<Hypers> hierarchy(std::make_shared<Hypers> (hy));
            for(int h = 0; h < num_clusters; h++){
                unique_values.push_back(hierarchy);
            }
            for(int h = 0; h < n_aux; h++){
                aux_unique_values.push_back(hierarchy);
            }
    }

    // If no # initial clusters is given, it will be set equal to the data size
    Neal8(std::vector<double> &data, int n_aux, const Mixture &mix,
        const Hypers &hy): Neal8(data, data.size(), n_aux, mix, hy) {}

    // Getters
    const unsigned int get_n_aux(){return n_aux;}
    const unsigned int get_maxiter(){return maxiter;}
    const unsigned int get_burnin(){return burnin;}
    const unsigned int get_num_clusters(){return num_clusters;}
    const unsigned int get_num_clusters_best(){return best_clust.phi_size();}
    // Setters
    void set_n_aux(const unsigned int n_aux){n_aux = n_aux;}
    void set_maxiter(const unsigned int maxiter){maxiter = maxiter;}
    void set_burnin(const unsigned int burnin){burnin = burnin;}
    void set_num_clusters(const unsigned int num_clusters){
        num_clusters = num_clusters;
    }

}; // end of Class Neal8

#include "Neal8.imp.hpp"

#endif // NEAL8_HPP