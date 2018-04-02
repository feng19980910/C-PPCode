// Frabjous.cpp -- the 2ed question on CppPrimerPlus
#include <iostream>
#include <cstring>
using  namespace std;

class Frabjous {
	private:
		char fab[20];
	public:
		Frabjous(const char * s = "C++") { strcpy(fab, s); }
		virtual void tell() { cout << fab; }
};
class Gloam {
	private:
		int glip;
		Frabjous fb;
	public:
		Gloam(int g = 0, const char * s = "C++");
		Gloam(int g, const Frabjous & f);
		void tell();
};

Gloam::Gloam(int g, const char * s) : fb(s), glip(g) {
}

Gloam::Gloam(int g, const Frabjous & f) : fb(f), glip(g) {
}

void Gloam::tell() {
	cout << "glip : " << glip << endl;
	cout << "frabjous : ";
	fb.tell();
	cout << endl;
}
