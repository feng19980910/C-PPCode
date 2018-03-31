// string2.cpp -- String class methods
#include <cstring>
#include "string2.h"
using std::cin;
using std::cout;

// initializing static class member
int String::num_strings = 0;

// static method
int String::HowMany() {
	return num_strings;
}

// class methods
String::String(const char * s) {			// constructor String from C string
	len = std::strlen(s); 					// set size
	str = new char[len + 1];				// allot storage
	std::strcpy(str, s);					// initialize pointer
	num_strings++;							// set object count
}

String::String() {							// default constructor
	len = 4;
	str = new char[1];
	str[0] = '\0';							// default string
	num_strings++;
}

String::String(const String & st) {
	num_strings++;							// handle static member update
	len = st.len;							// same length
	str = new char(len + 1);				// allot space(storage)
	std::strcpy(str, st.str);				// copy string to new location
}

String::~String() {							// necessary destructor
	-- num_strings;							// required
	delete[] str;							// required
}

void String::stringlow() {
	for (int i = 0; str[i]; i++)
		str[i] = tolower(str[i]);
}

void String::stringup() {
	for (int i = 0; str[i]; i++)
		str[i] = toupper(str[i]);
}

int String::has(char c) const {
	int num = 0;
	for (int i = 0; str[i]; i++)
		if (c == str[i])
			num++;
	return num;
}


// overload operator methods
// add two Strings
String String::operator+(const String & st) const {
	char * p = new char[strlen(str) + strlen(st.str) + 1];
	int j = 0;
	for (int i = 0; str[i]; i++, j++)
		p[j] = str[i];
	for (int i = 0; st.str[i]; i++, j++)
		p[j] = st.str[i];

	String result(p);
	delete[] p;
	return result;
}

// assign a String to a String
String & String::operator=(const String & st) {
	if (this == &st) 
		return * this;
	delete[] str;
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
	return *this;
}

// assign a C string to a String
String & String::operator=(const char * s) {
	delete[] str;
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	return *this;
}

// read-write char access ofr non-const String
char & String::operator[](int i) {
	return str[i];
}

// read-only char access for const String
const char & String::operator[](int i) const {
	return str[i];
}

// overloaded operator friend
String operator+(const char * st1, const String &st2) {
	int l = strlen(st1);
	char * p = new char[l + strlen(st2.str) + 1];
	strcpy(p, st1);
	strcpy(p + l, st2.str);
	String result(p);
	delete p;
	return result;
}
	

bool operator<(const String & st1, const String & st2) {
	return (std::strcmp(st1.str, st2.str) < 0);
}

bool operator>(const String & st1, const String & st2) {
	return st2 < st1;
}

bool operator==(const String & st1, const String & st2) {
	return (std::strcmp(st1.str, st2.str) == 0);
}

// simple String output
ostream & operator<<(ostream & os, const String & st) {
	os << st.str;
	return os;
}

// quick and dirty String input
istream & operator>>(istream & is, String & st) {
	char temp[String::CINLIM];
	is.get(temp, String::CINLIM);
	if (is)
		st = temp;
	while (is && is.get() != '\n')
		continue;
	return is;
}
