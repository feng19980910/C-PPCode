// str1.cpp -- introducing the string class
#include <iostream>
#include <string>
// using string constructors

int main() {
	using namespace std;
	string one("Lottery Winner!");			// ctor #1	string(const char * s)
	cout << one << endl;
	string two(20, '$');					// ctor #2	string(size_type n, char c)
	cout << two << endl;
	string three(one);						// ctor #3	string(const string & str);
	cout << three << endl;
	one += " Oops!";						// overloaded +=
	cout << one << endl;
	two = "Sorry! That was ";
	three[0] = 'P';
	string four;							// ctor #4	string()
	four = two + three;						// overload +, =
	cout << four << endl;
	char alls[] = "All's well that ends well";
	string five(alls, 20);					// ctor #5	string(const char * s, size_type n)
	cout << five << "!\n";
	string six(alls+6, alls + 10);			// ctor #6	template <class Iter> string(Iter begin, Iter end)
	cout << six << ", ";
	string seven(&five[6], &five[10]);		// ctor #6 again
	cout << seven << "...\n";
	string eight(four, 7, 16);				// ctor #7	string(const string & str, string size_type pos = 0, size_type n = npos)
	cout << eight << " in motion!" << endl;

	string feng1("abcdefghijkl");
	feng1[0] = 0;				// WILL DELETE THE FISRT CHARACTER IN STRING FENG1
	cout << feng1 << endl;
	// string feng2(feng1, 100);	// WILL THROW AN EXCEPTION(std::out_of_range)
	// cout << feng2 << endl;
	// string feng3(nullptr);	// WILL THROW AN EXCEPTION(std::logic_error)
	return 0;
}
