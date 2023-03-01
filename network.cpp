#include <eigen3/Eigen/Dense>
#include "network.hpp"
#include <cmath>
// #include <iostream>
// using namespace std;

NeuralNetwork::NeuralNetwork(
        //int numInputNeurons,int numHiddenLayers, 
        //int* numNeuronsPerHiddenLayer, int numOutputNeurons,
        Eigen::RowVectorXd initTopology,
        double (*initErrorMetric)(Eigen::MatrixXd, Eigen::MatrixXd)):
        topology(initTopology.size()),
        weights(initTopology.size() - 1), 
        biases(initTopology.size() - 1)
{
    errorMetric = initErrorMetric;
    int numWeights = initTopology.size() - 1;

    topology = initTopology;
    /*
    layerSizes[0] = numInputNeurons;
    layerSizes[numWeights] = numOutputNeurons;

    for (int i = 0; i < numHiddenLayers; i++) {
        layerSizes[i+1] = numNeuronsPerHiddenLayer[i];
    } */

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

    for (int i = 0; i < inputs.cols(); i++) {

        // feed sample forward
        Eigen::MatrixXd inputSample = inputs.col(i);
        Eigen::MatrixXd sampleTarget = targets.col(i);
        Eigen::MatrixXd sampleOutput = predict(inputs);

        // calculate error
        double error = errorMetric(sampleOutput, sampleTarget);

        // backpropogate

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
