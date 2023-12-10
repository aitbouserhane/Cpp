#ifndef NUM_MATRIX_H
#define NUM_MATRIX_H

#include "matrix.h"

template<typename T>
class MatrixNumerical : public MatrixBase<T> {
public:
    MatrixNumerical(std::size_t rows, std::size_t cols);

    T getDeterminant() const;
    MatrixNumerical<T> getInverse() const;

    static MatrixNumerical<T> getIdentity(int size);
};

template<typename T>
MatrixNumerical<T>::MatrixNumerical(std::size_t rows, std::size_t cols)
    : MatrixBase<T>(rows, cols) {}

template<typename T>
MatrixNumerical<T> getCoFactor(const MatrixNumerical<T>& matrix, std::size_t row, std::size_t col);

#include "num_matrix.cpp" 

#endif

