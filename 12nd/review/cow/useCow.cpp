// useCow.cpp -- use the class Cow
// compile with cow.cpp
#include "cow.h"
#include <iostream>

int main() {
	using std::endl;
	using std::cout;

	Cow a;
	Cow b("cowb", "sleep", 300);
	Cow c(b);

	cout << "declared cow a,b,c, there are them" << endl;
	cout << "a:";
	a.ShowCow();
	cout << endl << "b:";
	b.ShowCow();
	cout << endl << "c:";
	c.ShowCow();
	
	a = b;
	cout << endl << "after \"a = b\", \n a:";
	a.ShowCow();
	Cow * p = new Cow("cowp", "eat", 500);
	cout << endl << "use pointer to initialize a Cow object\n";
	cout << "p:";
	p->ShowCow();
	delete p;
	p = NULL;
	cout << endl;
	
	return 0;
}
