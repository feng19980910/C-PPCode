#include "bank.h"
#include <iostream>
int main() {
	using std::cout;
	using std::endl;
	using std::cin;
	Account usr[5] = { Account("usr0", "0001000"), Account("usr1", "0001001"), Account("usr2", "0001002"),
						Account("usr3", "0001003"), Account("usr4", "0001004") };
	double num;

	//deposit 1000
	num = 1000;
	cout << "Deposit " << num;
	if (usr[1].dep(num))
		cout << " succeed.\n";
	else
		cout << " fail.\n";
	usr[1].show();
	cout << endl;

	//deposit 1000
	num = 1000;
	cout << "Deposit " << num;
	if (usr[1].dep(num))
		cout << " succeed.\n";
	else
		cout << " fail.\n";
	usr[1].show();
	cout << endl;

	//draw 2000
	num = 2000;
	cout << "Draw " << num;
	if (usr[1].draw(num))
		cout << " succeed.\n";
	else
		cout << " fail.\n";
	usr[1].show();
	cout << endl;

	//draw 1     FAIL
	num = 1;
	cout << "Draw " << num;
	if (usr[1].draw(num))
		cout << " succeed.\n";
	else
		cout << " fail.\n";
	usr[1].show();


	return 0;
}