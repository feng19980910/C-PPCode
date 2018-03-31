#include "vector.h"
#include <iostream>
namespace VECTOR {
	Vector::Vector() {
		y = x = length = angle = 0;
	}

	Vector::Vector(double n1, double n2, Mode mo) {
		switch(mo) {
			case RECTANGULAR:
				y = n2;
				x = n1;
				angle = atan2(y, x);
				length = sqrt(x * x + y * y);
				break;
			case POLAR:
				length = n1;
				angle = n2;
				y = length * sin(angle);
				x = length * cos(angle);
				break;
		}
		mode = mo;
	}

	void Vector::translate(Mode mo) {
		if (mode != mo) {
			switch(mode) {
				case RECTANGULAR:
					mode = POLAR;
					length = sqrt(x * x + y * y);
					angle = atan2(y, x);
					break;
				case POLAR:
					mode = RECTANGULAR;
					y = length * sin(angle);
					x = length * cos(angle);
					break;
			}
		}
	}

	void Vector::showdegree() {
		std::cout << '(' <<  length << ", " << Rad_to_degree * angle << ')';
	}

	Vector Vector::operator+(const Vector & v2) {
		return Vector(x + v2.x, y + v2.y);
	}

	ostream & operator<<(ostream & os, const Vector & vec) {
		os << '(' << vec.x << ", " << vec.y << ')';
		return os;
	}
}
