//stacker.cpp -- testing the Stack class
#include <iostream>
#include <cctype> // or ctype.h
#include "stack.h"
int main() {
	using namespace std;
	Stack st; // create an empty stack
	char ch;
	double sum = 0;
	int count = 0;
	customer po;
	cout << "Please enter A to add a purchase order.\n"
		<< "P to process a PO, or Q to quit.\n";
	while (cin >> ch && toupper(ch) != 'Q') {
		while (cin.get() != '\n')
			continue;
		if (!isalpha(ch)) {
			cout << '\a';
			continue;
		}
		switch (ch) {
		case 'A':
		case 'a':
			cout << "Enter a PO fullname and payment to add: ";
			cin >> po.fullname;
			cin >> po.payment;
			if (st.isfull())
				cout << "stack already full\n";
			else
				st.push(po);
			break;
		case 'P':
		case 'p':
			if (st.isempty())
				cout << "stack already empty\n";
			else {
				st.pop(po);
				sum += po.payment;
				count += 1;
				cout << "PO #" << po.fullname << " popped\n";
				cout << "Now sum = " << sum << endl;
				cout << "And there are(is) " << count << " customer(s).\n";
			}
			break;
		}
		cout << "Please enter A to add a purchase order,\n"
			<< "P to process a PO, or Q to quit.\n";
	}
	cout << "Bye\n";
	return 0;
}