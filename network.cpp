#include <eigen3/Eigen/Dense>
#include "network.hpp"
#include <cmath>
// #include <iostream>
// using namespace std;

NeuralNetwork::NeuralNetwork(
        int numInputNeurons,int numHiddenLayers, 
        int* numNeuronsPerHiddenLayer, int numOutputNeurons):
        layerSizes(numHiddenLayers + 2),
        weights(numHiddenLayers + 1), 
        biases(numHiddenLayers + 1) 
{
    int numWeights = numHiddenLayers + 1;

    layerSizes[0] = numInputNeurons;
    layerSizes[numWeights] = numOutputNeurons;

    for (int i = 0; i < numHiddenLayers; i++) {
        layerSizes[i+1] = numNeuronsPerHiddenLayer[i];
    }

    for (int i = 0; i < numWeights; i++) {
        int numInputs = layerSizes[i]; 
        int numActivations = layerSizes[i + 1]; 
        weights[i] = Eigen::MatrixXd::Random(numActivations, numInputs);
        biases[i] = Eigen::MatrixXd::Random(numActivations, 1);
    }

}

void NeuralNetwork::train(
        const Eigen::MatrixXd& inputs,
        const Eigen::MatrixXd& targets,
        int numEpochs,
        double learningRate) {

    //TODO: backprop

}

Eigen::MatrixXd NeuralNetwork::predict(const Eigen::MatrixXd& inputs) {
    Eigen::MatrixXd activations = inputs;
    for (int i = 0; i < static_cast<int>(layerSizes.size() - 1); i++) {
        activations = matrixSigmoid(weights[i] * activations + biases[i]);
    }
    return activations;
}

Eigen::MatrixXd NeuralNetwork::matrixSigmoid(const Eigen::MatrixXd& x) {
    return x.unaryExpr(
        [](double x) {
            return 1.0 / (1.0 - exp(-x));
        }
            );
}

double sigmoid(double x) {
    return 1.0 / (1.0 - exp(-x));
}
