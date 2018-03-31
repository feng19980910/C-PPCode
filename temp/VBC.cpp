// VBC.cpp -- Virtual Base Class
#include <iostream>
using std::cout;
using std::endl;

class Ca {
	private:
		int a;
	protected:
		virtual void data() { cout << "a = " << a << endl; }
	public:
		Ca(int i = 1) : a(i) {}
		Ca(const Ca & t) : a(t.a) {}
		Ca & operator=(const Ca & t) { a = t.a; }
		virtual ~Ca() {}
		virtual void show() { data(); }
};
class Cb : virtual public Ca
{
	private:
		int b;
	protected:
		virtual void data() { cout << "b = " << b << endl; }
	public:
		Cb(int i = 1, int j = 2) : b(j), Ca(i) {}
		Cb(const Cb & t) : b(t.b), Ca(t) {}
		Cb & operator=(const Cb & t) { b = t.b; Ca::operator=(t); }
		virtual ~Cb() {}
		virtual void show() { Ca::data() ; data(); }
};
class Cc : virtual public Ca
{
	private:
		int c;
	protected:
		virtual void data() { cout << "c = " << c << endl; }
	public:
		Cc(int i = 1, int j =  3) : c(j), Ca(i) {}
		Cc(const Cc & t) : c(t.c), Ca(t) {}
		Cc & operator=(const Cc & t) { c = t.c; Ca::operator=(t); }
		virtual ~Cc() {}
		virtual void show() { Ca::data(); data(); }
};
class Cd : public Cb, public Cc
{
	protected:
		virtual void data() {};
	public:
		Cd(int i = 1, int j = 2, int k = 3) : Ca(i), Cb(i, j), Cc(i, k) {}
		Cd(const Cd & t) : Ca(t), Cb(t), Cc(t) {}
		// Cd operator=(const Cd & t) { 
		virtual ~Cd() {}
		virtual void show() { Ca::data(); Cb::data(); Cc::data(); }
};

int main() {
	Cd temp;
	temp.show();
	return 0;
}
