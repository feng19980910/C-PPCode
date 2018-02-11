// operator.cpp -- basic overload operator and translate function
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class Myclass {
	public:
		int a, b;
		operator int() const;
		Myclass operator+(const Myclass & t) const;
		void show() const;
};

Myclass::operator int() const {
	return a + b;
}

Myclass Myclass::operator+(const Myclass & t) const {
	Myclass result;
	result.a = a + t.a;
	result.b = b + t.b;
	return result;
}

Myclass operator+(int i, const Myclass & t) {
	Myclass result;
	result.a = i + t.a;
	result.b = i + t.b;
	return result;
}

void Myclass::show() const {
	cout << "a = " << a << ", b = " << b << endl;
}

int main() {
	Myclass x, y, z;
	int i = 1;
	x.a = 1, x.b = 2;
	y.a = 0, y.b = 4;
	z = x + y;

	cout << "x: ";
	x.show();	
	cout << "y: ";
	y.show();
	cout << "z: ";
	z.show();
	cout << endl << "i = " << i << endl;
	z = 1 + z;
	cout << "z: ";
	z.show();
	cout << "int(x) = " << int(x) << endl;

	return 0;
}
