#include "num_matrix.h"

template<typename T>
MatrixNumerical<T> getCoFactor(const MatrixNumerical<T>& matrix, std::size_t row, std::size_t col) {
    std::size_t size = matrix.getRows();
    MatrixNumerical<T> cofactor(size - 1, size - 1);

    for (std::size_t i = 0, newRow = 0; i < size; ++i) {
        if (i == row) continue;

        for (std::size_t j = 0, newCol = 0; j < size; ++j) {
            if (j == col) continue;

            cofactor.addElement(newRow, newCol, matrix.getElement(i, j));
            ++newCol;
        }

        ++newRow;
    }

    return cofactor;
}

template<typename T>
T MatrixNumerical<T>::getDeterminant() const {
    std::size_t size = this->getRows();

    if (size != this->getCols()) {
        throw std::invalid_argument("La matrice doit être carrée pour avoir un déterminant.");
    }

    if (size == 1) {
        return this->getElement(0, 0);
    }

    T determinant = 0;

    for (std::size_t i = 0; i < size; ++i) {
        T sign = (i % 2 == 0) ? 1 : -1;

        determinant += sign * this->getElement(0, i) * getCoFactor(*this, 0, i).getDeterminant();
    }

    return determinant;
}

template<typename T>
MatrixNumerical<T> MatrixNumerical<T>::getInverse() const {
    std::size_t size = this->getRows();

    if (size != this->getCols()) {
        throw std::invalid_argument("La matrice doit être carrée pour avoir une inverse.");
    }

    T determinant = this->getDeterminant();

    if (determinant == 0) {
        throw std::invalid_argument("La matrice n'est pas inversible (déterminant = 0).");
    }

    MatrixNumerical<T> inverse(size, size);

    for (std::size_t i = 0; i < size; ++i) {
        for (std::size_t j = 0; j < size; ++j) {
            T sign = ((i + j) % 2 == 0) ? 1 : -1;

            inverse.addElement(j, i, sign * getCoFactor(*this, i, j).getDeterminant() / determinant);
        }
    }

    return inverse;
}

template<typename T>
MatrixNumerical<T> MatrixNumerical<T>::getIdentity(int size) {
    MatrixNumerical<T> identity(size, size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (i == j) {
                identity.addElement(i, j, T(1));
            }
            else {
                identity.addElement(i, j, T(0));
            }
        }
    }
    return identity;
}

