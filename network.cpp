#include <eigen3/Eigen/Dense>
#include "network.hpp"

NeuralNetwork::NeuralNetwork(
        int numInputNeurons,int numHiddenLayers, 
        int* numNeuronsPerHiddenLayer, int numOutputNeurons):
        layerSizes(numHiddenLayers + 2),
        weights(numHiddenLayers + 1),
        biases(numHiddenLayers + 1) 
{
    layerSizes[0] = numInputNeurons;
    layerSizes[numHiddenLayers + 1] = numOutputNeurons;
    for (int i = 1; i <= numHiddenLayers; i++) {
        layerSizes[i] = numNeuronsPerHiddenLayer[i];
    }

    for (int i = 0; i < numHiddenLayers + 1; i++) {
        int rows = layerSizes[i]; // num rows = num input neurons
        int cols = layerSizes[i + 1]; // num weights = num neurons next layer
        weights[i] = Eigen::MatrixXd::Random(rows, cols);
        biases[i] = Eigen::MatrixXd::Random(1, cols);
    }

}

void NeuralNetwork::train(
        const Eigen::MatrixXd& inputs,
        const Eigen::MatrixXd& targets,
        int numEpochs,
        double learningRate) {

    // backprop

}

Eigen::MatrixXd NeuralNetwork::predict(const Eigen::MatrixXd& inputs) {
    Eigen::MatrixXd activations = inputs;
    for (int i = 0; i < (layerSizes.size() - 1; i++) {
        activations = sigmoid(weights[i] * activations + biases[i]);
    }
    return activations;
}

Eigen::MatrixXd NeuralNetwork::uj[

sigmoid(const Eigen::MatrixXd& x) {
    return x.unaryExpr(
}
