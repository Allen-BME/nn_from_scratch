#ifndef NETWORK_H
#define NETWORK_H

#include "neuron.hpp"
#include <vector>
#include <eigen3/Eigen/Dense>

class Layer {
    public:
        Layer(int numNeurons, int numInputs);
    private:
        int numNeurons;
        Matrix<double> layer;
}

class NeuralNetwork {
    public:
        NeuralNetwork();
        void addLayer(int numNeurons);
        double feedforward( x) const;
        void train(const double** data, const double* y_true);
    private:
        int numLayers;
        vector<Matrix<double>> layers; // vector of matrices, 1 matrix = 1 layer
        list<int> layerLengths;
};



/* Example neural network:
 * !! this is obviously a pretty terrible implementation
 * - 2 inputs
 * - 1 hidden layer (h1, h2)
 * - output layer (o1)
 *
 * each neuron has:
 * - w = [0, 1]
 * - b = 0
*/
class ExampleNetwork {
    public: 
        ExampleNetwork();
        double feedforward(const double* inputs);
    private:
        Neuron h1;
        Neuron h2;
        Neuron o1;
};

#endif
