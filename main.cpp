#include <eigen3/Eigen/Dense>
#include "network.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
    int hiddenLayerSizes[5] = {5, 5, 4, 4, 3};
    NeuralNetwork nn(5, 5, hiddenLayerSizes, 2);

    Eigen::MatrixXd inputs(5, 1);
    inputs << 1, 2, 3, 4, 5;
    nn.predict(inputs);
}
