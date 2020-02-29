#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP

#include <fstream>
#include <tuple>
#include <vector>
#include <math.h>
#include <Eigen/Dense> 
#include <stan/math/prim/mat.hpp>
#include <math.h>
#include "../hierarchies/HierarchyNNIG.hpp"
#include "../mixtures/DirichletMixture.hpp"
#include "../hyperparameters/HypersFixedNNIG.hpp"
#include "../../output.pb.h"

template<template <class> class Hierarchy, class Hypers, class Mixture>
class Algorithm{

private:
    // Mehtods parameters
    unsigned int maxiter = 20000;
    unsigned int burnin = 5000;
    int num_clusters;

    // Data and values containers
    std::vector<double> data;
    std::vector<unsigned int> allocations;
    std::vector<Hierarchy<Hypers>> unique_values;
    std::pair< std::vector<double>, Eigen::VectorXd > density; // TODO w/ Eigen
    Mixture mixture;
    ChainOutput chain;
    IterationOutput best_clust;

    // Random engine
    std::mt19937 rng;

    // Algorithm functions
    virtual void print_startup_message() = 0;

    virtual void initialize() = 0;

    void step(){ // TODO is it virtual?
        sample_allocations();
        sample_unique_values();
        // TODO sample_weights() etc?
    }

    virtual void sample_allocations() = 0;

    virtual void sample_unique_values() = 0;

    void save_iteration(unsigned int iter);

    void print_ending_message();

    // Auxiliary tools
    void print_state();    

public:
    // Running tool
    void run(){
        print_startup_message();
        initialize();
        unsigned int iter = 0;
        while(iter < maxiter){
            step();    
            if(iter >= burnin){
              save_iteration(iter);
            }
            iter++;
        }
        print_ending_message();
    }

    void run_and_save_cards(){} // TODO la blastiamo? (vedi Neal8)

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

    // Constructors and destructors:
    virtual ~Algorithms() = default;
    Algorithm(const std::vector<double> & data, const int num_clusters,
        const Mixture &mix, const Hypers &hy):
        data(data), num_clusters(num_clusters), mixture(mix) {
            Hierarchy<Hypers> hierarchy(std::make_shared<Hypers> (hy));
            for(int h = 0; h < num_clusters; h++) {
                unique_values.push_back(hierarchy);
            }
            
    }
    // If no # initial clusters is given, it will be set equal to the data size:
    Algorithm(std::vector<double> &data, const Mixture & mix, const Hypers &hy):
        Algorithm(data, data.size(), mix, hy) {}

};

#include "Algorithm.imp.hpp"

#endif // ALGORITHM_HPP