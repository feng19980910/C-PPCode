#include <iostream>
#include "namesp.h"
using std::endl;
using std::cin;
using std::cout;
using namespace SALES;
int main() {
	Sales s1, s2;
	double sales[4] = { 31.2, 32.2, 81.9, 99.0 };
	setSales(s1, sales);
	setSales(s2);
	cout << "Default one:" << endl;
	showSales(s1);
	cout << endl;
	cout << "Custom one:\n";
	showSales(s2);
	return 0;
}