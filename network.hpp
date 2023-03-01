#include <eigen3/Eigen/Dense>
#include <vector>
#include <cmath>

class NeuralNetwork {
public:
    NeuralNetwork(
            int numInputNeurons, 
            int numHiddenLayers,
            int* numNeuronsPerHiddenLayer,
            int numOutputNeurons
        );
    void train(
            const Eigen::MatrixXd& inputs,
            const Eigen::MatrixXd& targets,
            int numEpochs, 
            double learningRate
        );
    Eigen::MatrixXd predict(const Eigen::MatrixXd& inputs);

private:
    std::vector<int> layerSizes; 
    std::vector<Eigen::MatrixXd> weights; 
    std::vector<Eigen::MatrixXd> biases; 
    Eigen::MatrixXd matrixSigmoid(const Eigen::MatrixXd& x); 
    Eigen::MatrixXd matrixSigmoidDerivative(const Eigen::MatrixXd& x);
};

double sigmoid(double x);
