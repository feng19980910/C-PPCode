// copy_constructor -- to see use copy constructor or constructor
#include <iostream>

class my {
	private:
		int m;
	public:
		my(int i = 0) {
			m = i;
			std::cout << "Constructor" << std::endl;
		}
		my(const my & t) {
			m = t.m;
			std::cout << "Copy Constructor" << std::endl;
		}
		my & operator=(const my & t) {
			m = t.m;
			std::cout << "Overload= function" << std::endl;
		}

};

int main() {
	std::cout << "my a(5) is : ";
	my a(5);
	std::cout << "my b = a is : ";
	my b = a;
	std::cout << "my c = my(8) is : ";
	my c = my(8);
	std::cout << "my d(a) is : ";
	my d(a);
	std::cout << "a = c is : ";
	a = c;
	std::cout << "a = 4 is : ";
	a = 4;

	return 0;
}
