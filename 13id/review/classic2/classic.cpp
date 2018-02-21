// classic.cpp -- methods of classes in classic.h
// use dynamic memory allocation
#include "classic.h"
#include <cstring>		// for strcpy()
#include <iostream>		// for cout, endl
using std::strcpy;
using std::cout;
using std::endl;

Cd::Cd(const char * s1, const char * s2, int n, double x) {
	label = new char[std::strlen(s1) + 1];
	strcpy(label, s1);
	performers = new char[std::strlen(s2) + 1];
	strcpy(performers, s2);
	selections = n;
	playtime = x;
}
Cd::Cd(const Cd & d) {
	performers = new char[std::strlen(d.performers) + 1];
	label = new char[std::strlen(d.label) + 1];
	strcpy(performers, d.performers);
	strcpy(label, d.label);
	selections = d.selections;
}
Cd::Cd() {
	performers = new char[1];
	label = new char[1];
	performers[0] = label[0] = '\0';
	selections = 0;
	playtime = 0.0;
}
Cd::~Cd() {
	delete [] performers;
	delete [] label;
}
void Cd::Report() const {
	cout << "Performers : " << performers << endl;
	cout << "Label : " << label << endl;
	cout << "Selections : " << selections << endl;
	cout << "Playtime : " << playtime << endl;
}
Cd & Cd::operator=(const Cd & d) {
	delete [] performers;
	delete [] label;
	performers = new char[std::strlen(d.performers) + 1];
	label = new char[std::strlen(d.label) + 1];
	strcpy(performers, d.performers);
	strcpy(label, d.label);
	selections = d.selections;
	playtime = d.playtime;
	return *this;
}

Classic::Classic(const char * s0, const char * s1, const char * s2, int n, double x) : Cd(s1, s2, n, x) {
	mainly = new char[std::strlen(s0) + 1];
	strcpy(mainly, s0);
}
Classic::Classic(const Classic & cl) : Cd(cl) {
	mainly = new char[std::strlen(cl.mainly) + 1];
	strcpy(mainly, cl.mainly);
}
Classic::Classic() : Cd() {
	mainly = new char[1];
	mainly = '\0';
}
Classic::~Classic() {
	delete mainly;
}
void Classic::Report() const {
	Cd::Report();
	cout << "Mainly ablout : " << mainly << endl;
}
Classic & Classic::operator=(const Classic & c) {
	Cd::operator=(c);
	delete [] mainly;
	mainly = new char[std::strlen(c.mainly) + 1];
	strcpy(mainly, c.mainly);
	return *this;
}
