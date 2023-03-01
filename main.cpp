#include <eigen3/Eigen/Dense>
#include "network.hpp"
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
/*
    int hiddenLayerSizes[2] = {4, 3};
    NeuralNetwork nn(5, 2, hiddenLayerSizes, 2, &meanSquaredError);
*/
    Eigen::RowVectorXd topology(4);
    topology << 5, 4, 3, 2;
    NeuralNetwork nn(topology, &meanSquaredError);

    Eigen::MatrixXd inputs(5, 1);
    inputs << 1, 2, 3, 4, 5;
    cout << nn.predict(inputs) << endl;
}
