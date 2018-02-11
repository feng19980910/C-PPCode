// overloadios.cpp -- overload iostream and operator<<
#include <iostream>
using namespace std;

class Myclass {
	private:
		int x;
		int y;
	public:
		Myclass(int a = 0, int b = 0);
		friend void operator<<(ostream & co, Myclass & m);
};
Myclass::Myclass(int a, int b) {
	x = a;
	y = b;
}
void operator<<(ostream & co, Myclass & m) {
	co << "(" << m.x << ", " << m.y << ")";
}

int main() {
	Myclass m(1,2);
	cout << m;
	cout << endl;
	return 0;
}
