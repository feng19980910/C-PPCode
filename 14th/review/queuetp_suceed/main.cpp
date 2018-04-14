#include "queuetp.h"
#include "worker.h"

#include <iostream>
using namespace std;

int main() {
	bool goon{ true };
	char choose;
	queuetp<worker> queue;
	worker temp;
	char name[20];
	char number[20];
	char vocation[20];

	while (goon) {
		cout << "'e' to enqueue, 'd' to dequeue, 'q' to quit" << endl;
		cin >> choose;
		switch (choose) {
		case 'e':
			cout << "Please inpress name, number and vocation : " << endl;
			cin >> name;
			cin >> number;
			cin >> vocation;
			queue.enqueue(worker(name, number, vocation));
			break;
		case 'd':
			if (queue.dequeue(temp))
				temp.show();
			else
				cout << "false" << endl;
			break;
		case 'q':
			goon = false;
			break;
		}
	}

	return 0;
}
