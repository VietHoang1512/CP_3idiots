#include <iostream>
#include <ostream>
#include <math.h>
#include <iomanip> 

using namespace std;

struct Complex {
    double real;
    double imag;
};

Complex operator + (Complex a, Complex b) {
    Complex sum;
    sum.real = a.real + b.real;
    sum.imag = a.imag + b.imag;
    return sum;
}

Complex operator - (Complex a, Complex b) {
    Complex dif;
    dif.real = a.real - b.real;
    dif.imag = a.imag - b.imag;
    return dif;
}

Complex operator * (Complex a, Complex b) {
    Complex pro;
    pro.real = a.real*b.real - a.imag*b.imag;
    pro.imag = a.real*b.imag + a.imag*b.real;
    return pro;
}

Complex operator / (Complex a, Complex b) {
    Complex quo;
    quo.real = (a.real*b.real + a.imag*b.imag) / (b.real*b.real + b.imag*b.imag);
    quo.imag = (- a.real*b.imag + a.imag*b.real) / (b.real*b.real + b.imag*b.imag);
    return quo;
}

ostream& operator << (ostream& out, const Complex &a) {
    out << '(' << std::setprecision(2) << a.real << (a.imag >= 0 ? '+' : '-') << std::setprecision(2) << fabs(a.imag) << 'i' << ')';
    return out;
}

int main() {
    double real_a, real_b, img_a, img_b;
    cin >> real_a >> img_a;
    cin >> real_b >> img_b;
    
    Complex a{real_a, img_a};
    Complex b{real_b, img_b};
    
    cout << a << " + " << b << " = " << a + b << endl;
    cout << a << " - " << b << " = " << a - b << endl;
    cout << a << " * " << b << " = " << a * b << endl;
    cout << a << " / " << b << " = " << a / b << endl;
    
    return 0;
}