// explicit_specific_class.cpp -- explicit specific class
#include <iostream>
#include <cstring>
using std::endl;
using std::cout;
template <class T1, class T2>
class classtp
{
	private:
		T1 a;
		T2 b;
	public:
		classtp(T1 x, T2 y);
		T1 first() { return a; }
		T2 second() { return b; }
};
template <class T1, class T2>
classtp<T1, T2>::classtp(T1 x, T2 y)
{
	a = x;
	b = y;
}
template <> class classtp<char *, char>
{
	private:
		char * a;
		char b;
	public:
		classtp(const char *, char);
		char * first();
		char second() { return b; }
};
// you needn't to care about the keyword "template", just define.
classtp<char *, char>::classtp(const char * ptr, char c)
{
	a = new char[std::strlen(ptr) + 1];
	std::strcpy(a, ptr);
	b = c;
}
char * classtp<char *, char> ::first() { return a + 1; }

int main() {
	classtp<int, int> test_int(1, 2);
	classtp<char *, char> test_specific("abc", 'd');
	cout << test_int.first() << endl;
	cout << test_specific.first() << endl;
	return 0;
}
