#ifndef NETWORK_H
#define NETWORK_H

#include "neuron.hpp"
    
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
