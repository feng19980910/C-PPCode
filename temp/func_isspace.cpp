#include <iostream>
using namespace std;
int main() {
	char ch;
	while (ch = cin.get()) {
		if (ch == '\n')
			continue;
		cout << isspace(ch) << endl;
	}
	return 0;
}
