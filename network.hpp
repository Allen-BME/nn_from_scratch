#ifndef NETWORK_H
#define NETWORK_H

#include "neuron.hpp"
#include <list>

class NeuralNetwork {
    public:
        NeuralNetwork();
        void addLayer(int numNeurons);
        double feedforward(const double* x) const;
        void train(const double** data, const double* y_true);
    private:
        int numLayers;
        list<Neuron*> layers;
        list<int> layerLengths;
};

/* Example neural network:
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
