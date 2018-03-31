// protected.cpp -- It says that derived class will make
// the protected member in original class be public
#include <iostream>
using std::cout;
using std::endl;

class origin {
	private:
		int a;
	protected:
		char b;
	public:
		double c;

		origin(int x = 1, char y = '-', double z = 0.1);
};
class derive : public origin {
	public:
		char e;
		double f;

		derive();
};
class deriveplus : public derive {
	public:
		char g;

		deriveplus();
};

origin::origin(int x, char y, double z) :
		a(x), b(y), c(z) {}
derive::derive() :
		e(b), f(c)  {}
deriveplus::deriveplus() :
		g(b) {}				// protected member from origin to derive could be used as like by derivedplus

int main() {
	derive de;
	deriveplus dp;
	cout << "or = origin, de = derive, dp = deriveplus" << endl;
	cout << "  its public de.e = " << de.e << endl;
	cout << "   or public de.c = " << de.c << endl;
	cout << "or protected de.b = ERROR!" << endl;
	// cout << "origin protected de.b = " << de.b << endl;  // compile error "b is protected"
	// means protected member could be used as like only by derived class

	cout << "de public dp.e = " << dp.e << endl;
	cout << "or public dp.c = " << dp.c << endl;
	// cout << "or protected dp.b = " << dp.b << endl; // compile error "b is protected"
	// means protected member from origin is protected member of derive class
	// or... the relationship is "only from one to pass another", no de's a or de's b of c, all are or's

	return 0;
}
