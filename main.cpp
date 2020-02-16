#include <iostream>
#include  <fstream>

//#include <boost/random/random_number_generator.hpp>
//#include <boost/random/detail/qrng_base.hpp>

#include "includes_main.hpp"
#include "math.h"

int main(){
    unsigned int n = 100;
    std::vector<double> data(n);
    unsigned int half = data.size()/2;

    double mean1 = 4.0;
    double mean2 = 7.0;
    double sd1   = 1.0;
    double sd2   = 1.0;

    std::default_random_engine generator;
    std::normal_distribution<double> N1(mean1,sd1);
    std::normal_distribution<double> N2(mean2,sd2);

    for(int i = 0; i < half; i++){
        data[i]      = N1(generator);
        data[i+half] = N2(generator);
    }

    //std::ofstream file;
    //file.open("data.csv");
    //for(auto &d : data){
    //    file << d << ",";
    //}
    //file << std::endl;
    //file.close();

    std::vector<double> mass;
	std::vector<double> num_clust_best;
    double tempm = -1.0;
    double stepm = 0.1;
    double upp_bndm = 2.3;
    while(tempm <= upp_bndm){
        mass.push_back(exp(tempm));
        tempm += stepm;
    }
	
    HypersFixedNNIG hy(5.0, 1.0, 2.0, 2.0); // mu0, lambda, alpha0, beta0

    for (int i=0; i<mass.size(); i++){
    SimpleMixture mix(mass[i]); // total mass
    //Neal2<HierarchyNNIG, HypersFixedNNIG, SimpleMixture> sampler2(
    //    data, mix, hy);
    Neal8<HierarchyNNIG, HypersFixedNNIG, SimpleMixture> sampler8(
        data, 3, mix, hy);
	
    // Run samplers
    //sampler2.run();
    sampler8.run();

    unsigned int i_cap = sampler8.cluster_estimate();
    std::cout << "Best clustering: at iteration " << i_cap << std::endl;
    num_clust_best.push_back(sampler8.get_num_clusters_best());
    }
	

    std::ofstream file;
    file.open("num_clust_best.csv");
    for(auto &d : num_clust_best){
        file << d << ",";
    }
    file << std::endl;
    file.close();


    // Density stuff
    std::vector<double> grid;
    double temp = 0.0;
    double step = 0.05;
    double upp_bnd = 10.0;
    while(temp <= upp_bnd){
        grid.push_back(temp);
        temp += step;
    }
    //sampler8.eval_density(grid);
    //sampler8.write_density_to_file();

    //sampler2.eval_density(grid);
    //sampler2.write_density_to_file();
	//unsigned int i_cap = sampler2.cluster_estimate();
    //std::cout << "Best clustering: at iteration " << i_cap << std::endl;
    //sampler2.write_final_clustering_to_file();
    //sampler2.write_best_clustering_to_file();

    // Clustering stuff
    //unsigned int i_cap = sampler8.cluster_estimate();
    //std::cout << "Best clustering: at iteration " << i_cap << std::endl;
    //sampler8.write_final_clustering_to_file();
    //sampler8.write_best_clustering_to_file();
    //sampler8.write_chain_to_file();

    return 0;
}
