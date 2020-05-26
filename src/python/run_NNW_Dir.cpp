#include <iostream>
#include <fstream>
#include <string>

#include "../../includes.hpp"

namespace NNWDir {
    using HypersType = HypersFixedNNW;
    using MixtureType = DirichletMixture;
    template <class HypersType> using HierarchyType = HierarchyNNW<HypersType>;

    using Builder = std::function< std::unique_ptr<Algorithm<HierarchyType,
        HypersType, MixtureType>>(HypersType,MixtureType, Eigen::MatrixXd)>;
}


int run_NNW_Dir(const Eigen::Matrix<double, 1, Eigen::Dynamic> &mu0,
    double lambda, const Eigen::MatrixXd &tau0, double nu, double totalmass,
    const std::string &datafile, const std::string &algo,
    const std::string &colltype,
    const std::string &collfile = "collector.recordio",
    unsigned int rng = 0, unsigned int maxit = 0, unsigned int burn = 0){

    std::cout << "Running run_NNW_Dir.cpp" << std::endl;
    using namespace NNWDir;

    // Build model components
    HypersType hy(mu0, lambda, tau0, nu);
    MixtureType mix(totalmass);

    // Read data from file
    Eigen::MatrixXd data = read_eigen_matrix(datafile);

    // Load algorithm factory
    Builder neal2builder = [](HypersType hy, MixtureType mix,
        Eigen::MatrixXd data){
        return std::make_unique< Neal2<HierarchyType,HypersType,
                MixtureType> >(hy, mix, data);
        };
    
    Builder neal8builder = [](HypersType hy, MixtureType mix,
        Eigen::MatrixXd data){
        return std::make_unique< Neal8<HierarchyType,HypersType,
                MixtureType> >(hy, mix, data);
        };

    auto &algoFactory = Factory<
        Algorithm<HierarchyType, HypersType, MixtureType>, HypersType,
        MixtureType>::Instance();

    algoFactory.add_builder("neal2",neal2builder);
    algoFactory.add_builder("neal8",neal8builder);

    // Create algorithm and set algorithm parameters
    auto sampler = algoFactory.create_object(algo, hy, mix, data);

    if(rng != 0)   (*sampler).set_rng_seed(rng);
    if(maxit != 0) (*sampler).set_maxiter(maxit);
    if(burn != 0)  (*sampler).set_burnin(burn);

    // Choose memory collector
    BaseCollector *coll;
    if(colltype == "file"){
        coll = new FileCollector(collfile);
    }
    else if(colltype == "memory"){
        coll = new MemoryCollector();
    }
    else {
        std::cerr << "Error: collector type arg must be \"file\" or \"memory\""
            << std::endl;
        return 1;
    }

    // Run algorithm
    (*sampler).run(coll);

    std::cout << "End of run_NNW_Dir.cpp" << std::endl;
    return 0;
}
