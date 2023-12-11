#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <iostream>

template<typename T>
class MatrixBase {
protected:
    std::vector<std::vector<T>> data;
    std::size_t rows;
    std::size_t cols;

public:
    MatrixBase(std::size_t rows, std::size_t cols);
    void addElement(std::size_t row, std::size_t col, T value);
    T getElement(std::size_t row, std::size_t col) const;
    std::size_t getRows() const;
    std::size_t getCols() const;
    void Display() const;

    MatrixBase<T> operator+(const MatrixBase<T>& other) const;
    MatrixBase<T> operator-(const MatrixBase<T>& other) const;
    MatrixBase<T> operator*(const MatrixBase<T>& other) const;
    MatrixBase<T> operator/(const MatrixBase<T>& other) const;
};

#include "matrix.cpp"

#endif

