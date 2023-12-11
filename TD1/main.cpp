#include <iostream>
#include "complex2D.h"
#include "complex2D.cpp"

int main() {
    Complex2D a(3, 4);
    Complex2D b(1, -2);

    std::cout << "a = " << a.getReal() << " + " << a.getImaginary() << "i" << std::endl;
    std::cout << "b = " << b.getReal() << " + " << b.getImaginary() << "i" << std::endl;

    Complex2D sum = a + b;
    Complex2D diff = a - b;
    Complex2D product = a * b;
    Complex2D quotient = a / b;

    std::cout << "Sum: " << sum.getReal() << " + " << sum.getImaginary() << "i" << std::endl;
    std::cout << "Difference: " << diff.getReal() << " + " << diff.getImaginary() << "i" << std::endl;
    std::cout << "Product: " << product.getReal() << " + " << product.getImaginary() << "i" << std::endl;
    std::cout << "Quotient: " << quotient.getReal() << " + " << quotient.getImaginary() << "i" << std::endl;

    Complex2D max = a > b;
    Complex2D min = a < b;

    std::cout << "Max: " << max.getReal() << " + " << max.getImaginary() << "i" << std::endl;
    std::cout << "Min: " << min.getReal() << " + " << min.getImaginary() << "i" << std::endl;

    Complex2D conjugateA = a.conjugate();
    Complex2D inverseA = a.inverse();

    std::cout << "Conjugate of a: " << conjugateA.getReal() << " + " << conjugateA.getImaginary() << "i" << std::endl;
    std::cout << "Inverse of a: " << inverseA.getReal() << " + " << inverseA.getImaginary() << "i" << std::endl;

    return 0;
}

