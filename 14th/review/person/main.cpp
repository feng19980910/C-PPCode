#include "person.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
	Person feng("Linfeng", "Liu");
	feng.Show();

	Gunslinger fengg("Linfeng", "Liu", 8);
	cout << fengg.Draw() << endl;
	fengg.Show();

	PokerPlayer fengp("linfeng", "Liu");
	cout << fengg.Draw() << endl;

	BadDude fengb("Linfeng", "Liu", 8);
	cout << fengb.Gdraw() << endl;
	cout << fengb.Cdraw() << endl;
	fengb.Show();

	return 0;
}
