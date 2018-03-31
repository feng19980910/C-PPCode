#include "person.h"
#include <iostream>
int main() {
	Person one;
	Person two("Smythecraft");
	Person three("Dimwiddy", "Sam");
	two.Show();
	std::cout << std::endl;
	two.FormalShow();
	return 0;
}