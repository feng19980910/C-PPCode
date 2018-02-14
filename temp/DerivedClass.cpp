// DerivedClass.cpp -- to see how the derived class work
#include <iostream>
#include <cstring>
using namespace std;

class my {
	private:
		char name[50];
		int age;
	public:
		my(const char * n, int ag) {
			strcpy(name, n);
			age = ag;
		}
		void show() {
			cout << "name: " << name << endl;;
			cout << "age: " << age << endl;
		}
};

class My : public my {
	private:
		char c;
	public:
		My(const char * n, const int ag, const char ch) : my(n, ag) {
			c = ch;
		}
		void Show() {
			show();
			cout << "char: " << c << endl;
		}
};


int main() {
	My a("feng", 21, 'F');
	a.show();
	a.Show();
	return 0;
}
