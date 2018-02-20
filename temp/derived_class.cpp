// derived_class.cpp -- test the feature of derived class
#include <iostream>
using std::cout;
using std::endl;
class my {
	private:
		int x;
	public:
		my(int i = 0);
		virtual ~my() {}		// virtual destruct function is necessary
		const int & X;
		virtual void show() const;
};
class myplus : public my {
	private:
		char c;
	public:
		myplus(int i = 0, char ch = 'c');
		virtual ~myplus() {};	// again! virtual destruct function is neccessary
		virtual void show() const;
};

my::my(int i) : X(x) {
	x = i;
}
void my::show() const {
	 cout << '(' << x << ')';
}
myplus::myplus(int i, char ch) 
		: my(i), c(ch) {}
void myplus::show() const {
	cout << '(' << X << ", " << c << ')';
}

void SHOW_v(const my t) {
	t.show();
}

int main() {
	my * p1 = new my(1);
	my * p2 = new myplus(2, 'b');
	cout << "p1->show() is : ";
	p1->show();
	cout << endl;
	cout << "p2->show() is : ";
	p2->show();
	cout << endl;
	cout << "p2->my::show() is : ";
	p2->my::show();				// forcely use my::show() rather than myplus::show() by virtual
	cout << endl;
	cout << "SHOW_v(*p1) is : ";
	SHOW_v(*p1);
	cout << endl;
	cout << "SHOW_v(*p2) is : ";// !!! call my.show() not myplus.show() !!!
	SHOW_v(*p2);				// pass by value could also get an derived object as pararmeter is allowed
	cout << endl;				// maybe implicit translate derived to original type

	delete p1;
	delete p2;

	return 0;
}
