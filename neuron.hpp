#ifndef NEURON_H
#define NEURON_H

#include <cmath>
#include "vector_math.hpp"
using namespace std;

double sigmoid(double x);

class Neuron {
    public:
        Neuron(const double* initWeights, int initNumWeights, double initBias);
        double feedforward(const double* inputs) const;
    private:
        int numWeights;
        double* weights;
        double bias;
};

#endif 
