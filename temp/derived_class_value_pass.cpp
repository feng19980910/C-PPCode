// derived_class_value_pass.cpp -- it is ok to pass a derived class by value 
#include <iostream>
using std::cout;
using std::endl;

class cla {
};
class clb : public cla {
};

void foo(cla a) { cout << "pass by value" << endl; }
int main() {
	clb b;
	foo(b);
	return 0;
}

