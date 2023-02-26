#include "network.hpp"
#include "neuron.hpp"
#include <list>

NeuralNetwork::NeuralNetwork() {
   numLayers = 0;
   /* layers = list<Neuron*>;
   layerLengths = list<int>; */
}

void NeuralNetwork::addLayer(int numNeurons) {
    numLayers++;
    layers.push_back(new Neuron[numNeurons]);
    layerLengths.push_back(numNeurons);
}

double NeuralNetwork::feedforward(const double* x) const {
    // 1. the first hidden layer takes the input x
    // 2. each following layer (including output) 
    //    takes the previous layer's output

    

    int i = 0;
    list<Neuron*>::iterator it;
    for (it = layers.begin(); it != layers.end(); ++it) {
        for (int j = 0; j < layerLengths[i]; j++) {
            (*it)[j] = (*it)->feedforward(x);
        }
        i++;
    }
}

// simple example from tutorial
ExampleNetwork::ExampleNetwork() {
   double weights[2] = {0, 1};
   h1.setWeights(weights, 2);
   h1.setBias(0);
   h2.setWeights(weights, 2);
   h2.setBias(0);
   o1.setWeights(weights, 2);
   o1.setBias(0);
}

double ExampleNetwork::feedforward(const double* inputs) {
    double out_h1 = h1.feedforward(inputs);
    double out_h2 = h2.feedforward(inputs);
    double hiddenLayerOutputs[2] = {out_h1, out_h2};
    return o1.feedforward(hiddenLayerOutputs);
}
