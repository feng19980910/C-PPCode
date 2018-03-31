#include <fstream>
#include <iostream>
#include <cstdlib>
#include <time.h>
#include "vector.h"
using std::ofstream;
using std::cin;
using std::cout;
using std::endl;
using namespace VECTOR;
int main() {
	srand(time(0));
	Vector sum;
	Vector step;
	double target, len;
	int count = 0;

	ofstream fout;
	fout.open("data.txt", std::ios::out);

	cout << "Please input the target length: ";
	fout << "Please input the target length: ";
	cin >> target;
	fout << target << '\n';
	cout << "Please input the length of one step: ";
	fout << "Please input the length of one step: ";
	cin >> len;
	fout << len << '\n';
	while (sum.len() < target) {
		sum = sum + Vector(len, double(rand() % 360) / Rad_to_degree);
		count++;
		fout << count << ')' << '\t' << "(x, y) = " << sum << endl;
	}
	cout << "After " << count << " steps, succeed!\n";
	fout << "After " << count << " steps, succeed!\n";
	cout << "(x, y) = " << sum << endl;
	fout << "(x, y) = " << sum << endl;

	return 0;
}
