#include "neuron.hpp"
#include "vector_math.hpp"

Neuron::Neuron(
        const double* initWeights, int initNumWeights, double initBias) {
    numWeights = initNumWeights;
    bias = initBias;
    weights = new double[numWeights];
    for (int i = 0; i < numWeights; i++) {
        weights[i] = initWeights[i];
    }
}
        
double Neuron::feedforward(const double* inputs) const { 
    double total = bias + dotProduct(weights, inputs, numWeights);
    return sigmoid(total);    
}

double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}
