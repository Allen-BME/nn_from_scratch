#ifndef VECTOR_MATH_H
#define VECTOR_MATH_H

#include <cmath>

double sigmoid(double x);
double sigmoid_derivative(double x, int length);
double mean(const double* x);
double mse_loss(const double* y_true, const double* y_pred, int length);
double dotProduct(const double* a, const double* b, int length);

#endif
