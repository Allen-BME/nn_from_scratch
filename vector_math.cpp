#include "vector_math.hpp"

double dotProduct(const double* a, const double* b, int length) {
    double sum = 0;
    for (int i = 0; i < length; i++) {
        sum += a[i] * b[i];
    }
    return sum;
}
