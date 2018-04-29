// cast_operator.cpp -- pretice using dynamic_cast, static_cast, const_cast, reinterrupt_cast

#include <iostream>
using namespace std;

class cla {
	private:
		int a, b;
	public:
		cla(int A = 0, int B = 0) : a(A), b(B) {}
		virtual void tell() const {
			cout << "I have two integer, they are: " << a << " and " << b << ".\n";
		}
		virtual ~cla() {}
};

class clb : public cla {
	private:
		char c;
	public:
		clb(int A = 0, int B = 0, char C = 'z') : cla(A, B), c(C) {}
		virtual void say() const {
			cla::tell();
			cout << "But!! I still have a character, it is: " << c << ".\n";
		}
		virtual ~clb() {}
};

class cca {
	private:
		double a;
	public:
		cca(double A = 0.0) : a(A) {}
		virtual void say() const {
			cout << "I have a double float number, it is: " << a << ".\n";
		}
		virtual ~cca() {}
};

int main() {
	cla * pcla = new cla(1, 2);
	clb * pclb = nullptr;
	cca * pcca = nullptr;

	cout << "try to use dynamic_cast to down translate" << endl;
	if (pclb = dynamic_cast<clb *>(pcla))
		pclb->say();
	else
		cout << "Failed" << endl;
	cout << "try to use dynamic_cast to unrelated translate" << endl;
	if (pcca = dynamic_cast<cca *>(pcla))
		pcca->say();
	else
		cout << "Failed" << endl;

	cout << "try to use static_cast to down translate" << endl;
	if (pclb = static_cast<clb *>(pcla))
		pclb->say();
	else
		cout << "Failed" << endl;
	// compile passed, but a runtime error take place !!!!!

	cout << "try to use static_cast to unrelated translate" << endl;
	cout << "not allowed" << endl; // couldn't pass the compiler
	// if (pcca = static_cast<cca *>(pcla))
	// 	pcca->say();
	// else
	// 	cout << "Failed" << endl;

	// delete pcla;
	return 0;
}
