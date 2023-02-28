#include <eigen3/Eigen/Dense>
#include "network.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
    int hiddenLayerSizes[5] = {5, 5, 4, 4, 3};
    NeuralNetwork nn(5, 5, hiddenLayerSizes, 2);
}
