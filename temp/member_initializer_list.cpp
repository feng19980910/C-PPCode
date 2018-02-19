// member_initializer_list.cpp -- initialize class by member initializer list
// in-class initializer
// normal object by type_name name(data) form
#include <iostream>
class my {
	private:
		int m;
		// could not with const, because construct function could initializer 
		// const member only buy member_initializer_list
		char c;
	public:
		my(int i = 0, char ch = ' ');
		friend std::ostream & operator<<(std::ostream & os, const my & t);
};
my::my(int i, char ch) : m(i) {
	c = ch;
}	// initialize class by member initializer list
std::ostream & operator<<(std::ostream & os, const my & t) {
	os << '(' << t.m << ", " << t.c << ')';
	return os;
}

int main() {
	my t = 1;
	// there is a warning as "initializer in constructor function 
	// are available in C++11 or gun11
	const my z(2, 'a');  // const object with contructor function
	int m(2);
	std::cout << "t = " << t << std::endl;
	std::cout << "z = " << z << std::endl;
	std::cout << "m = " << m << std::endl;
	return 0;
}
