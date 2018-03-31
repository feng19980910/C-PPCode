// const_feature.cpp -- for those const object
#include <iostream>
#include <cstring>
using std::cout;
class my {
	private:
		char * str;
		int len;
	public:
		my(const char * s);
		char & operator[](int i) { return str[i]; }
		// !! pay attention to the "const" between delcaration and definition
		const char & operator[](int i) const { return str[i]; }	
		friend std::ostream & operator<<(std::ostream & os, const my & t);
};

my::my(const char * s) {
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
}
std::ostream & operator<<(std::ostream & os, const my & t) {
	os << t.str;
	return os;
}

int main() {
	my a("abc");
	const my b("const");
	cout << "cout << a is : " << a << '\n';
	cout << "cout << b is : " << b << '\n';
	cout << "a[0] is : " << a[0] << '\n';		// use char & operator
	cout << "b[0] is : " << b[0] << '\n';		// use const char & operator
	return 0;
}
