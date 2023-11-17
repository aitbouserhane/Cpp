#include "Complex2D.h"

Complex2D::Complex2D() {
    reel = 0;
    img = 0;
}

Complex2D::Complex2D(double r, double i) {
    reel = r;
    img = i;
}

Complex2D::Complex2D(double v) {
    reel = v;
    img = v;
}

Complex2D::Complex2D(const Complex2D &cmp) {
    reel = cmp.reel;
    img = cmp.img;
}

double Complex2D::getReal() const {
    return reel;
}

double Complex2D::getImaginary() const {
    return img;
}

void Complex2D::setReal(double value) {
    reel = value;
}

void Complex2D::setImaginary(double value) {
    img = value;
}

Complex2D Complex2D::operator+(const Complex2D &cmplx) {
    return Complex2D(reel + cmplx.reel, img + cmplx.img);
}

Complex2D Complex2D::operator-(const Complex2D &cmplx) {
    return Complex2D(reel - cmplx.reel, img - cmplx.img);
}

Complex2D Complex2D::operator*(const Complex2D &cmplx) {
    return Complex2D(reel * cmplx.reel - img * cmplx.img, reel * cmplx.img + img * cmplx.reel);
}

Complex2D Complex2D::operator/(const Complex2D &cmplx) {
    double denominator = cmplx.reel * cmplx.reel + cmplx.img * cmplx.img;
    return Complex2D((reel * cmplx.reel + img * cmplx.img) / denominator,
                     (img * cmplx.reel - reel * cmplx.img) / denominator);
}

Complex2D Complex2D::operator<(const Complex2D &cmplx2) {
    return (reel < cmplx2.reel || (reel == cmplx2.reel && img < cmplx2.img)) ? *this : cmplx2;
}

Complex2D Complex2D::operator>(const Complex2D &cmplx2) {
    return (reel > cmplx2.reel || (reel == cmplx2.reel && img > cmplx2.img)) ? *this : cmplx2;
}

Complex2D Complex2D::conjugate() const {
    return Complex2D(reel, -img);
}

Complex2D Complex2D::inverse() const {
    double denominator = reel * reel + img * img;
    return Complex2D(reel / denominator, -img / denominator);
}

