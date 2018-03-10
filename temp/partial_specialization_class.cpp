// partial_specialization_class.cpp -- partial_specialization
#include <iostream>
using namespace std;

template <class t1, class t2, class t3>
class classtp {
	public:
		void show() { cout << "general template" << endl; }
};
template <class t1, class t2>
class classtp<t1, t2, t2> {
	public:
		void show() { cout << "t1, t2, t2 template" << endl; }
};
template <class t1>
class classtp<t1, t1*, t1*> {
	public:
		void show() { cout << "t1, t1*, t2 template" << endl; }
};

int main()
{
	// no matter how the partial template like, 
	// you must write as the general template.
	classtp<char, int, double> ct1;
	classtp<char, int, int> ct2;
	classtp<char, char *, char *> ct3;

	// classtp<char, int> ct4;	// argument error(3 needed, 2 gaven)
	
	ct1.show();			// general template
	ct2.show();			// t1, t2, t2 template
	ct3.show();			// t1, t1*, t2 template

	return 0;
}
