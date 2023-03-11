#include <eigen3/Eigen/Dense>
#include <vector>
#include <cmath>

class NeuralNetwork {
public:
    NeuralNetwork(
            Eigen::RowVectorXd initTopology,
            double (*initErrorMetric)(Eigen::MatrixXd, Eigen::MatrixXd)
        );
    void train(
            const Eigen::MatrixXd& inputs,
            const Eigen::MatrixXd& targets,
            int numEpochs, 
            double learningRate
        );
    Eigen::MatrixXd predict(const Eigen::MatrixXd& inputs);

private:
    Eigen::VectorXd topology; 
    std::vector<Eigen::MatrixXd> weights; 
    std::vector<Eigen::MatrixXd> biases; 
    Eigen::MatrixXd sigmoid(const Eigen::MatrixXd& x); 
    Eigen::MatrixXd sigmoidDerivative(const Eigen::MatrixXd& x);
    double (*errorMetric)(Eigen::MatrixXd, Eigen::MatrixXd);
};

double meanSquaredError(Eigen::MatrixXd predictions, Eigen::MatrixXd targets);
