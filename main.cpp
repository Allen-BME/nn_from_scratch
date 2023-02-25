#include <iostream>
#include "network.hpp"
using namespace std;

int main(int argc, char* argv[]) {

    ExampleNetwork network;
    double x[2] = {2, 3};
    cout << network.feedforward(x) << endl;

    return 0;
}
