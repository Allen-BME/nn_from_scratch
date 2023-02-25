#include <iostream>
#include "neuron.hpp"
using namespace std;

int main(int argc, char* argv[]) {

    int numWeights = 2;
    double weights[2] = {0, 1};
    double bias = 4.0;

    Neuron n(weights, numWeights, bias);

    double x[2] = {2, 3};
    cout << n.feedforward(x) << endl;

    return 0;
}
