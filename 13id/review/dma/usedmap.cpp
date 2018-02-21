// usedmap.cpp -- test the new dma class
#include <iostream>
#include "dma.h"
#define QUANTITY 3
using std::cin;
using std::cout;
using std::endl;

int main() {
	ABC * p[QUANTITY];
	int type;
	char str[3][50];
	int num;

	for (int count = 0; count < QUANTITY; count++) {
		cout << "Create an object!" << endl;
		cout << "press 1 for baseDMA, 2 for lacksDMA, 3 for hasDMA" << endl;
		cin >> type;
		switch (type) {
			case 1:
				cout << "baseDMA:\nlabel : ";
				cin >> str[0];
				cout << "rating : ";
				cin >> num;
				p[count] = new baseDMA(str[0], num);
				break;
			case 2:
				cout << "lacksDMA:\blabel : ";
				cin >> str[0];
				cout << "rating : ";
				cin >> num;
				cout << "color : ";
				cin >> str[1];
				p[count] = new lacksDMA(str[1], str[0], num);
				break;
			case 3:
				cout << "hasDma:\blabel : ";
				cin >> str[0];
				cout << "rating : ";
				cin >> num;
				cout << "style : ";
				cin >> str[1];
				p[count] = new hasDMA(str[1], str[0], num);
				break;
			default:
				cout << "Please press in 1, 2 or 3!" << endl;
				count--;
		}
	}
	for (int count = 0; count < QUANTITY; count++)
		p[count]->show();
	return 0;
}
