#ifndef COMPLEX0_H_
#define COMPLEX0_H_
#include <iostream>
class complex {
	private:
		double real;
		double imag;
	public:
		complex(double r = 0, double i = 0);		// constructor function
		// operator overload in member function
		complex operator+(const complex & t) const;
		complex operator-(const complex & t) const;
		complex operator*(const complex & t) const;
		complex operator-() const;
		// operator overload in friend function
		friend complex operator+(double d, const complex & t);
		friend complex operator-(double d, const complex & t);
		friend complex operator*(double d, const complex & t);
		friend std::ostream & operator<<(std::ostream & os, const complex & t);
		friend std::istream & operator>>(std::istream & is, complex & t);
};

#endif
