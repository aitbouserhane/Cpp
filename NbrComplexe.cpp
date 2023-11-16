#include <iostream>

class Complex2D {
private:
    double reel;
    double img;

public:
    Complex2D() {
        reel = 0;
        img = 0;
    }

    Complex2D(double r, double i) {
        reel = r;
        img = i;
    }

    Complex2D(double v) {
        reel = v;
        img = v;
    }

    Complex2D(const Complex2D &cmp) {
        reel = cmp.reel;
        img = cmp.img;
    }

    // Getters
    double getReal() const {
        return reel;
    }

    double getImaginary() const {
        return img;
    }

    // Setters
    void setReal(double value) {
        reel = value;
    }

    void setImaginary(double value) {
        img = value;
    }

    Complex2D operator+(const Complex2D &cmplx) {
        return Complex2D(reel + cmplx.reel, img + cmplx.img);
    }

    Complex2D operator-(const Complex2D &cmplx) {
        return Complex2D(reel - cmplx.reel, img - cmplx.img);
    }

    Complex2D operator*(const Complex2D &cmplx) {
        return Complex2D(reel * cmplx.reel - img * cmplx.img, reel * cmplx.img + img * cmplx.reel);
    }

    Complex2D operator/(const Complex2D &cmplx) {
        double denominator = cmplx.reel * cmplx.reel + cmplx.img * cmplx.img;
        return Complex2D((reel * cmplx.reel + img * cmplx.img) / denominator,
                         (img * cmplx.reel - reel * cmplx.img) / denominator);
    }

    Complex2D operator<(const Complex2D &cmplx2) {
        return (reel < cmplx2.reel || (reel == cmplx2.reel && img < cmplx2.img)) ? *this : cmplx2;
    }

    Complex2D operator>(const Complex2D &cmplx2) {
        return (reel > cmplx2.reel || (reel == cmplx2.reel && img > cmplx2.img)) ? *this : cmplx2;
    }

    Complex2D conjugate() const {
        return Complex2D(reel, -img);
    }

    Complex2D inverse() const {
        double denominator = reel * reel + img * img;
        return Complex2D(reel / denominator, -img / denominator);
    }
};

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

