// copycons_OPoverload.cpp -- to see when copy constructor will be called in OP overload funciton
#include <iostream>
using std::cout;
using std::endl;
class my {
	private:
		int m;
	public:
		my(int i = 0);
		my(const my & t);
		my operator+(const my & t) const;
		friend std::ostream & operator<<(std::ostream & os, const my & t);
};
my::my(int i) {
	m = i;
	cout << "normal constructor ";
}
my::my(const my & t) {
	m = t.m;
	cout << "copy constructor ";
}
std::ostream & operator<<(std::ostream & os, const my & t) {
	os << t.m;
	return os;
}
my my::operator+(const my & t) const {
	return my(m + t.m);
}

int main() {
	cout << "my a(1) : ";
	my a(1);
	cout << endl;
	cout << "my b(2) : ";
	my b(2);
	cout << endl;
	cout << "my c : ";
	my c;
	cout << endl;

	cout << "a + b : ";
	a + b;			// will copy constructor be called at there,
	cout << endl;

	cout << "c = a + b : ";
	c = a + b;		// or be called at there?
	cout << endl;

	cout << "c = 1 : ";
	c = 1;			// guess: will call normal constructor and copy constructor		// wrong, only call normal constructor
	cout << endl;
	return 0;
}
