#include "bank.h"
#include <string>
#include <iostream>

Account::Account(const char* nm, const char* acc, double dp) {
	strcpy(name, nm);
	strcpy(account, acc);
	deposit = dp;
}

void Account::show() const {
	using std::cout;
	using std::endl;

	cout << "Name : " << name << endl;
	cout << "Account : " << account << endl;
	cout << "Deposit : " << deposit << endl;
}

bool Account::dep(const double dp) {
	if (dp < 0)
		return false;
	else {
		deposit += dp;
		return true;
	}
}
bool Account::draw(double dr) {
	if (dr <= deposit) {
		deposit -= dr;
		return true;
	}
	else
		return false;
}