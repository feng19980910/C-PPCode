// member_initializer_list.cpp -- initialize class by member initializer list
// in-class initializer
// normal object by type_name name(data) form
#include <iostream>
class my {
	private:
		int m;
		char c = 'a';
	public:
		my(int i);
		friend std::ostream & operator<<(std::ostream & os, const my & t);
};
my::my(int i) : m(i) {}	// initialize class by member initializer list
std::ostream & operator<<(std::ostream & os, const my & t) {
	os << '(' << t.m << ", " << t.c << ')';
	return os;
}

int main() {
	my t = 1;
	int m(2);
	std::cout << "t = " << t << std::endl;
	std::cout << "m = " << m << std::endl;
	return 0;
}

