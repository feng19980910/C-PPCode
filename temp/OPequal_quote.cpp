// OPequl_quote -- to see operator= return queto or value
#include <iostream>
using std::cout;
int main() {
	int i = 0;
	(i = 1) = 2;
	cout << "(i = 1) = 2;" << '\n';
	cout << "i = " << i << '\n';
	// result:
	// i = 2
	// so operator= return quote
	return 0;
}
