// Frabjous3.h -- the 3rd question on CppPrimerPlus

#include <iostream>
#include <cstring>
using namespace std;
class Frabjous {
	private:
		char fab[20];
	public:
		Frabjous(const char * s = "C++") { strcpy(fab, s); }
		virtual void tell() { cout << fab; }
};

class Gloam : private Frabjous {
	private:
		int glip;
	public:
		Gloam(int g = 0, const char * s = "C++");
		Gloam(int g, const Frabjous & f);
		void tell();
};

Gloam::Gloam(int g, const char * s) : glip(g), Frabjous(s) {
}

Gloam::Gloam(int g, const Frabjous & f) : glip(g), Frabjous(f) {
}

void Gloam::tell() {
	cout << "Glip : " << glip << endl;
	cout << "Frabjous : ";
	Frabjous::tell();
	cout << endl;
}
