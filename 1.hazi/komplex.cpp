#include "komplex.h"

#include <bits/stdc++.h>
#include <math.h>

komplex::komplex(double x, double y) : real(x), imag(y) {    
}

komplex::komplex(const komplex &r) : komplex(r.getReal(), r.getImag()) {}

void komplex::setReal(double x) {
    real = x;
}

void komplex::setImag(double y) {
    imag = y;
}

double komplex::getReal() const {  
    return real;
}

double komplex::getImag() const {
    return imag;
}

void komplex::add(const komplex &q) const {
    double x = q.getReal();
    double y = q.getImag();
    std::cout << real + x << "+" << imag + y << "i" << std::endl;
}

void komplex::mul(const komplex &q) const {
    double x = q.getReal(),
           y = q.getImag();
    std::cout << real *x - imag * y << "+" << x * imag + y * real << "i" << std::endl;
}

void komplex::div(const komplex &q) const {
    double x = q.getReal(),
        y = q.getImag();
        std::cout <<(((real)*(x))+((imag)*(y)))/(pow(x,2)+pow(y,2)) << "+" << (((x)*(imag))-((real)*(y)))/(pow(x,2)+pow(y,2)) << "i" << std::endl;
}