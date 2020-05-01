#ifndef HIERARCHYNNW_HPP
#define HIERARCHYNNW_HPP

#include "HierarchyBase.hpp"

// Normal-Wishart multivariate distribution
//
// state  = mu, tau (vector, matrix)
// hypers = mu0, lambda, tau0, nu (vector, scalar, matrix, scalar)

template<class Hypers>
class HierarchyNNW : public HierarchyBase<Hypers> {
protected:
    using HierarchyBase<Hypers>::state;
    using HierarchyBase<Hypers>::hypers;
    using EigenRowVec = Eigen::Matrix<double, 1, Eigen::Dynamic>;
    
    std::vector<Eigen::MatrixXd> normal_wishart_update(
    const Eigen::MatrixXd &data, const EigenRowVec &mu0, const double lambda,
    const Eigen::MatrixXd &tau0, const double nu);

    void check_state_validity() override;

public:
    bool is_multivariate() const override {return true;}

    // Destructor and constructor
    ~HierarchyNNW() = default;
    HierarchyNNW() = default;
    HierarchyNNW(std::shared_ptr<Hypers> hypers_) {
        hypers = hypers_;

        unsigned int dim = hypers->get_mu0().size();
        state.push_back( hypers->get_mu0() );
        state.push_back( hypers->get_lambda() *
            Eigen::MatrixXd::Identity(dim, dim) );
    }

    Eigen::VectorXd eval_marg(const Eigen::MatrixXd &data) override;
    Eigen::VectorXd like(const Eigen::MatrixXd &data) override;

    void draw() override;

    void sample_given_data(const Eigen::MatrixXd &data) override;
};

#include "HierarchyNNW.imp.hpp"

#endif // HIERARCHYNNW_HPP
