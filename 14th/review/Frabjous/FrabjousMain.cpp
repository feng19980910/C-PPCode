// FrabjousMain.cpp -- compile with Frabjous?.h
// this is the main funtion of Frabjous?.h

// #include "Frabjous2.h"
#include "Frabjous3.h"
#include <iostream>
using namespace std;

int main() {
	Frabjous a("frabjous");
	Gloam b(1, a);
	Gloam c(2, "gloam");
	a.tell();
	cout << endl;
	b.tell();
	c.tell();
	return 0;
}
