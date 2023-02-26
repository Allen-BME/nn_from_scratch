#ifndef NEURON_H
#define NEURON_H

#include "nn_math.hpp"
using namespace std;

class Neuron {
    public:
        Neuron(): weights(nullptr), numWeights(0), bias(0) {};
        Neuron(const double* initWeights, int initNumWeights, double initBias);
        double feedforward(const double* inputs) const;
        void setWeights(const double* newWeights, int newNumWeights);
        void setBias(double newBias);
    private:
        double* weights;
        int numWeights;
        double bias;
};

#endif 
