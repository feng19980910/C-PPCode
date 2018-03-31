#include <iostream>
#include "Stonewt.h"
using std::cout;
using std::endl;
int main() {
	Stonewt temp(10, 8.0);
	Stonewt result;
	result = temp * 2;
	cout << "temp = " << temp << endl;
	cout << "result = temp * 2" << endl;
	cout << "result = " << result << endl;
	result = 2 * temp;
	cout << "result = 2 * temp" << endl;
	cout << "result = " << result << endl;
	return 0;
}
