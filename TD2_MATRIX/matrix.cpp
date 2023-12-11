#include "matrix.h"

template<typename T>
MatrixBase<T>::MatrixBase(std::size_t rows, std::size_t cols)
    : rows(rows), cols(cols), data(rows, std::vector<T>(cols, T())) {}

template<typename T>
void MatrixBase<T>::addElement(std::size_t row, std::size_t col, T value) {
    if (row < rows && col < cols) {
        data[row][col] = value;
    }
}

template<typename T>
T MatrixBase<T>::getElement(std::size_t row, std::size_t col) const {
    if (row < rows && col < cols) {
        return data[row][col];
    }
    return T();
}

template<typename T>
std::size_t MatrixBase<T>::getRows() const {
    return rows;
}

template<typename T>
std::size_t MatrixBase<T>::getCols() const {
    return cols;
}

template<typename T>
void MatrixBase<T>::Display() const {
    for (std::size_t i = 0; i < rows; ++i) {
        for (std::size_t j = 0; j < cols; ++j) {
            std::cout << data[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

template<typename T>
MatrixBase<T> MatrixBase<T>::operator+(const MatrixBase<T>& other) const {
    if (rows == other.rows && cols == other.cols) {
        MatrixBase<T> result(rows, cols);
        for (std::size_t i = 0; i < rows; ++i) {
            for (std::size_t j = 0; j < cols; ++j) {
                result.addElement(i, j, data[i][j] + other.getElement(i, j));
            }
        }
        return result;
    }
    else {
        return MatrixBase<T>(0, 0);
    }
}

template<typename T>
MatrixBase<T> MatrixBase<T>::operator-(const MatrixBase<T>& other) const {
    if (rows == other.rows && cols == other.cols) {
        MatrixBase<T> result(rows, cols);
        for (std::size_t i = 0; i < rows; ++i) {
            for (std::size_t j = 0; j < cols; ++j) {
                result.addElement(i, j, data[i][j] - other.getElement(i, j));
            }
        }
        return result;
    }
    else {
        return MatrixBase<T>(0, 0);
    }
}

template<typename T>
MatrixBase<T> MatrixBase<T>::operator*(const MatrixBase<T>& other) const {
    if (cols == other.rows) {
        MatrixBase<T> result(rows, other.cols);
        for (std::size_t i = 0; i < rows; ++i) {
            for (std::size_t j = 0; j < other.cols; ++j) {
                T sum = 0;
                for (std::size_t k = 0; k < cols; ++k) {
                    sum += data[i][k] * other.data[k][j];
                }
                result.addElement(i, j, sum);
            }
        }
        return result;
    }
    else {
        return MatrixBase<T>(0, 0);
    }
}

template<typename T>
MatrixBase<T> MatrixBase<T>::operator/(const MatrixBase<T>& other) const {
    if (cols != other.rows) {
        return MatrixBase<T>(0, 0);
    }

    MatrixBase<T> inverseOther = other.getInverse();

    if (inverseOther.getRows() == 0 || inverseOther.getCols() == 0) {
        return MatrixBase<T>(0, 0);
    }

    return (*this) * inverseOther;
}

