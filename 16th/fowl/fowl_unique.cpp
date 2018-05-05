// fowl.cpp -- unique_ptr a poor choice
// CON'T COMPILE
// unique_ptr & unique_ptr::operator=(const unique_ptr & t) = delete;
#include <iostream>
#include <string>
#include <memory>

int main() {
	using namespace std;
	unique_ptr<string> films[5] = {
		unique_ptr<string>(new string("Fowl Balls")),
		unique_ptr<string>(new string("Duck Walds")),
		unique_ptr<string>(new string("Chicken Runs")),
		unique_ptr<string>(new string("Turkey Errors")),
		unique_ptr<string>(new string("Goose Eggs"))
	};
	unique_ptr<string> pwin;
	pwin = films[2];		// films[2] loses ownership

	cout << "The nominess for best avian baseball film are\n";
	for (int i = 0; i < 5; i++)
		cout << *films[i] << endl;
	cout << "The winner is " << *pwin << "!\n";
	return 0;
}
