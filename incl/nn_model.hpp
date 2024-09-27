#pragma once

#include "Eigen/Core"
#include <vector>
class NN_Model {
    typedef  std::vector<Eigen::MatrixX<double>> MatArr;
    typedef  std::vector<Eigen::VectorX<double>> VecArr;
    private:
        MatArr weights;
        VecArr bias;
        VecArr neurons;

    NN_Model();
    ~NN_Model();

    int fit();
    int predict();
    int reset();
    int save();

};
