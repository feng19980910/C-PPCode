#include "cow.h"
#include <iostream>
#include <string.h>

Cow::Cow() {
	hobby = new char[1];
	hobby[0] = '\0';
	name[0] = '\0';
	weight = 0;
}

Cow::Cow(const char * nm, const char * ho, double wt) {
	hobby = new char[strlen(ho) + 1];
	strcpy(hobby, ho);
	strcpy(name, nm);
	weight = wt;
}

Cow::Cow(const Cow & c) {
	hobby = new char[strlen(c.hobby) + 1];
	strcpy(hobby, c.hobby);
	strcpy(name, c.name);
	weight = c.weight;
}

Cow::~Cow() {
	delete[] hobby;
}

Cow & Cow::operator=(const Cow & c) {
	delete[] hobby;
	hobby = new char[strlen(c.hobby) + 1];
	strcpy(hobby, c.hobby);
	strcpy(name, c.name);
	weight = c.weight;
	return *this;
}

void Cow::ShowCow() const {
	using std::cout;
	using std::endl;
	cout << "Cow " << name << "'s hobby is : " << endl;
	cout << hobby << endl;
	cout << "Weight : " << weight << endl;
}
