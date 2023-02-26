#include "nn_math.hpp"

double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

double sigmoid_derivative(double x) {
    return sigmoid(x) * (1 - sigmoid(x));
}

double mean(const double* x, int length) {
    double sum = 0;
    for (int i = 0; i < length; i++) {
        sum += x[i];
    }
    return sum / length;
}

double mse_loss(const double* y_true, const double* y_pred, int length) {
    double sum = 0;
    for (int i = 0; i < length; i++) {
        sum += pow((y_true[i] - y_pred[i]), 2);
    }
    return sum / length;
}

double dotProduct(const double* a, const double* b, int length) {
    double sum = 0;
    for (int i = 0; i < length; i++) {
        sum += a[i] * b[i];
    }
    return sum;
}
