#include <eigen3/Eigen/Dense>
#include "network.hpp"
#include <cmath>
#include <vector>
// #include <iostream>
// using namespace std;

NeuralNetwork::NeuralNetwork(
        Eigen::RowVectorXd initTopology,
        double (*initErrorMetric)(Eigen::MatrixXd, Eigen::MatrixXd)):
        topology(initTopology.size()),
        weights(initTopology.size() - 1), 
        biases(initTopology.size() - 1)
{
    errorMetric = initErrorMetric;
    int numWeights = initTopology.size() - 1;

    topology = initTopology;

    for (int i = 0; i < numWeights; i++) {
        int numInputs = topology[i]; 
        int numActivations = topology[i + 1]; 
        weights[i] = Eigen::MatrixXd::Random(numActivations, numInputs);
        biases[i] = Eigen::MatrixXd::Random(numActivations, 1);
    }

}

void NeuralNetwork::train(
        const Eigen::MatrixXd& inputs,
        const Eigen::MatrixXd& targets,
        int numEpochs,
        double learningRate) {

    // for each epoch
    for (int epoch = 0; epoch < numEpochs; epoch++) {
        double totalError = 0.0;
    
        // for each sample
        for (int i = 0; i < inputs.cols(); i++) {

            // forward propogate
            Eigen::MatrixXd input = inputs.col(i);
            std::vector<Eigen::MatrixXd> activations = {input};
            std::vector<Eigen::MatrixXd> zs;

            int numLayers = topology.size() - 1;
            int numHiddenLayers = numLayers - 1;

            // track z and activations for each layer
            for (int layer = 0; layer < numLayers; i++) {
                Eigen::MatrixXd z = weights[layer] * activation + biases[layer];
                zs.push_back(z);
                activation = sigmoid(z);
                activations.push_back(activation);
            }

            // backpropogate
            Eigen::MatrixXd error = errorMetric(
                    activations.back(), targets.col(i));
            totalError += error.sum();

            // delta for output layer
            std::vector<Eigen::MatrixXd> deltas;
            deltas.push_back(error.cwiseProduct(sigmoidDerivative(zs.back())));

            // delta for each layer
            for (int layer = numHiddenLayers; layer > 0; layer--) {
                Eigen::MatrixXd delta =
                    weights[layer].transpose() * deltas.back();
                deltas.push_back(
                        delta.cwiseProduct(sigmoidDerivative(za[layer-1])));

            }
            
        }
    }
}

Eigen::MatrixXd NeuralNetwork::predict(const Eigen::MatrixXd& inputs) {
    Eigen::MatrixXd activations = inputs;
    for (int i = 0; i < static_cast<int>(topology.size() - 1); i++) {
        activations = sigmoid(weights[i] * activations + biases[i]);
    }
    return activations;
}

Eigen::MatrixXd NeuralNetwork::sigmoid(const Eigen::MatrixXd& x) {
    return x.unaryExpr(
        [](double x) {
            return 1.0 / (1.0 - exp(-x));
        }
            );
}

Eigen::MatrixXd NeuralNetwork::sigmoidDerivative(const Eigen::MatrixXd& x) {
   return x.unaryExpr(
        [](double x) {
            double sigmoid = (1.0 / (1.0 - exp(-x)));
            return sigmoid * (1.0 - sigmoid);
        }
           );
}

double meanSquaredError(Eigen::MatrixXd predictions, Eigen::MatrixXd targets) {
    // apply coefficient-wise square and take mean
    return (predictions - targets).array().square().mean();
}
