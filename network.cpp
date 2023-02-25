#include "network.hpp"
#include "neuron.hpp"

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
