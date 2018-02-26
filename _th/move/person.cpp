#include "person.h"
#include <string>
#include <iostream>
Person::Person(const string &ln, const char * fn) {
	lname = ln;
	strcpy(fname, fn);
}

void Person::Show() const {
	using std::cout;
	cout << "Name : " << fname << " " << lname << std::endl;
}
void Person::FormalShow() const {
	using std::cout;
	cout << "Name : " << lname << " " << fname << '\n';
}