// portmaster.cpp -- define the methods of class declared in portmaster.h
#include "portmaster.h"
#include <cstring>		// for strlen, strcpy
#include <iostream>
using std::strlen;
using std::strcpy;
using std::cout;
using std::endl;
using std::ostream;

// define methods of class Port
Port::Port(const char * br, const char * st, int b) : bottles(b) {
	brand = new char[strlen(br) + 1];
	strcpy(brand, br);
	strcpy(style, st);
}
Port::Port(const Port & p) {
	brand = new char[strlen(p.brand) + 1];
	strcpy(brand, p.brand);
	strcpy(style, p.style);
	bottles = p.bottles;
}
Port & Port::operator=(const Port & p) {
	delete [] brand;
	brand = new char[strlen(p.brand) + 1];
	strcpy(brand, p.brand);
	strcpy(style, p.style);
	bottles = p.bottles;
	return *this;
}
Port & Port::operator+=(int b) {
	bottles += b;
	return *this;
}
Port & Port::operator-=(int b) {
	bottles -= b;
	return *this;
}
void Port::Show() const {
	cout << "Brand : " << brand << endl;
	cout << "King : " << style << endl;
	cout << "Bottles : " << bottles << endl;
}
ostream & operator<<(ostream & os, const Port & p) {
	cout << p.brand << ", " << p.style << ", " << p.bottles;
	return os;
}

// define methods of VintagePort
VintagePort::VintagePort() : Port() {
	nickname = new char[1];
	nickname[0] = '\0';
	year = 0;
}
VintagePort::VintagePort(const char * br, int b, const char * nn, int y) : Port(br, "vintage", b) {
	nickname = new char[strlen(nn) + 1];
	strcpy(nickname, nn);
	year = y;
}
VintagePort::VintagePort(const VintagePort & vi) : Port(vi) {
	nickname = new char[strlen(vi.nickname) + 1];
	strcpy(nickname, vi.nickname);
	year = vi.year;
}
VintagePort & VintagePort::operator=(const VintagePort & vp) {
	Port::operator=(vp);
	delete [] nickname;
	nickname = new char[strlen(vp.nickname) + 1];
	strcpy(nickname, vp.nickname);
	year = vp.year;
}
void VintagePort::Show() const {
	Port::Show();
	cout << "NickName : " << nickname << endl
		<< "Year : " << year << endl;
}
ostream & operator<<(ostream & os, const VintagePort & vp) {
	cout << Port(vp) << ", " << vp.nickname << ", " << vp.year;
	return os;
}
