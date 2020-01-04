#include <Eigen/Dense>
// typedef Matrix<double, Dynamic, 1> VectorXd

#include "stanlib/stan/math.hpp"
#include "statslib/stats.hpp"
#include <arma.cpp>

namespace bnplib{
    using data_t = double;
    using par_t = double;
    using parvec_t = std::vector<param_t>;
    // using Normal = std::normal_distribution<data_t>;
}

using namespace bnplib;
