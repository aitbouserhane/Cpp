#ifndef COMPLEXE_H
#define COMPLEXE_H

class Complex2D {
private:
    double reel;
    double img;

public:
    Complex2D();
    Complex2D(double r, double i);
    Complex2D(double v);
    Complex2D(const Complex2D &cmp);

    double getReal() const;
    double getImaginary() const;

    void setReal(double value);
    void setImaginary(double value);

    Complex2D operator+(const Complex2D &cmplx);
    Complex2D operator-(const Complex2D &cmplx);
    Complex2D operator*(const Complex2D &cmplx);
    Complex2D operator/(const Complex2D &cmplx);
    Complex2D operator<(const Complex2D &cmplx2);
    Complex2D operator>(const Complex2D &cmplx2);

    Complex2D conjugate() const;
    Complex2D inverse() const;
};

#endif // COMPLEXE_H

