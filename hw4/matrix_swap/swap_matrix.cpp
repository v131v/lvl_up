#include "swap_matrix.h"

void swapMatrix(int size, int* matrix, int k) {

    for (int i = 0; i < size; i++) {

        if (i == k) continue;

        // swap
        matrix[i * size + k] += matrix[k * size + i];
        matrix[k * size + i] = matrix[i * size + k] - matrix[k * size + i];
        matrix[i * size + k] -= matrix[k * size + i];
    }
}
