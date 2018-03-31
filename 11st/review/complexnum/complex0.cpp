#include "complex0.h"
#include <iostream>

complex::complex(double r, double i) {
	real = r;
	imag = i;
}

complex complex::operator+(const complex & t) const {
	return complex(real + t.real, imag + t.imag);
}
complex complex::operator-(const complex & t) const {
	return complex(real - t.real, imag - t.imag);
}
complex complex::operator*(const complex & t) const {
	return complex(real * t.real - imag * t.imag, real * t.imag + imag * t.real);
}
complex complex::operator-() const {
	return complex(-real, -imag);
}

complex operator+(double d, const complex & t) {
	return complex(d + t.real, t.imag);
}
complex operator-(double d, const complex & t) {
	return complex(d - t.real, -t.imag);
}
complex operator*(double d, const complex & t) {
	return complex(d * t.real, d * t.imag);
}

std::ostream & operator<<(std::ostream & os, const complex & t) {
	os << '(' << t.real << ", " << t.imag << "i)";
	return os;
}

std::istream & operator>>(std::istream & is, complex & t) {
	std::cout << "real: ";
	is >> t.real;
	if (is) {
		std::cout << "imaginary: ";
		is >> t.imag;
	}
	return is;
}
