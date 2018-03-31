//#pragma once
#ifndef PERSON_H_
#define PERSON_H_
#include <string>
using std::string;
class Person {
private:
	static const int LIMIT = 25;
	string lname;
	char fname[LIMIT];
public:
	Person() { lname = ""; fname[0] = 0; }
	Person(const string &ln, const char * fn = "Heyyou");
	//the following methods display lname and fname
	void Show() const;			// firstname lastname format
	void FormalShow() const;	// lastname, firstname format
};	
#endif