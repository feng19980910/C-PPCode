// testportmaster.cpp -- test the methods of portmaster defined
#include "portmaster.h"
#include <iostream>
using std::cout;
int main() {
	Port * p1 = new VintagePort("brand1", 20, "The Noble", 50);
	Port * p2 = new Port("brand2", "ruby", 50);
	cout << "p1 : " << endl;
	p1->Show();
	cout << "p1 : " << *p1 << endl;

	cout << "p2 : " << endl;
	p2->Show();
	cout << "p2 : " << *p2 << endl;

	delete p1;
	delete p2;
	return 0;
}
