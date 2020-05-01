#ifndef HIERARCHYNNIG_HPP
#define HIERARCHYNNIG_HPP

#include "HierarchyBase.hpp"

// Normal likelihoood, Normal-InverseGamma hierarchy, that is:
// f ~ N(mu,sig^2)
// (mu,sig^2) ~ G
// G ~ DP(M, G0)  with G0 = N-IG
//
// state  = mu, sigma
// hypers = mu_0,Lambda0, alpha, beta

template<class Hypers>
class HierarchyNNIG : public HierarchyBase<Hypers> {
protected:
    using HierarchyBase<Hypers>::state;
    using HierarchyBase<Hypers>::hypers;

    std::vector<double> normal_gamma_update(const Eigen::VectorXd &data,
        const double mu0, const double alpha0, const double beta0,
        const double lambda0);

    void check_state_validity() override;

public:
    bool is_multivariate() const override {return false;}
    
    // Destructor and constructor
    ~HierarchyNNIG() = default;
    HierarchyNNIG() = default;
    HierarchyNNIG(std::shared_ptr<Hypers> hypers_) {
        hypers = hypers_;
        state = std::vector<Eigen::MatrixXd>(2,Eigen::MatrixXd(1,1));
        state[0](0,0) = hypers->get_mu0();
        state[1](0,0) = 1;
    }

    Eigen::VectorXd eval_marg(const Eigen::MatrixXd &data) override;
    Eigen::VectorXd like(const Eigen::MatrixXd &data) override;

    void draw() override;

    void sample_given_data(const Eigen::MatrixXd &data) override;
};


#include "HierarchyNNIG.imp.hpp"

#endif // HIERARCHYNNIG_HPP
