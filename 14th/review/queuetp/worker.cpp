// worker.cpp -- define the methods of class worker which declared in worker.h

#include "worker.h"
#include <iostream>
#include <cstring>
using namespace std;

worker::worker() {
	name[0] = number[0] = vocation[0] = '\0';
};

worker::worker(const char * nm, const char *num, const char * vc) {
	set_name(nm);
	set_number(num);
	set_vocation(vc);
};

worker::worker(const worker & wk) {
	set_name(wk.name);
	set_number(wk.number);
	set_vocation(wk.vocation);
}

worker & worker::operator=(const worker & wk) {
	set_name(wk.name);
	set_number(wk.number);
	set_vocation(wk.vocation);
};

bool worker::set_name(const char * nm) {
	if (!nm)
		return false;
	strcpy(name, nm);
	return true;
}

bool worker::set_number(const char * num) {
	if (!num)
		return false;
	strcpy(number, num);
	return true;
}

bool worker::set_vocation(const char * vc) {
	if (!vc)
		return false;
	strcpy(vocation, vc);
	return true;
}

void worker::show() const {
	cout << "name : " << name << endl;
	cout << "number : " << number << endl;
	cout << "vocation : " << vocation << endl;
}
