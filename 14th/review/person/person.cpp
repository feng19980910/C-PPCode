#include "person.h"
#include <iostream>
#include <string>
using namespace std;

Person::Person() : firstname(), lastname() {
}

Person::Person(const string & fn, const string & ln) : firstname(fn), lastname(ln) {
}

void Person::Show() const {
	cout << "Name : " << firstname << ' ' << lastname << endl;
}


Gunslinger::Gunslinger() : Person(), nick(0) {
}

Gunslinger::Gunslinger(const string & fn, const string & ln, int ni) : Person(fn, ln), nick(ni) {
}

double Gunslinger::Draw() const {
	srand((unsigned)time(nullptr));
	return ((double)rand() / RAND_MAX);
}

void Gunslinger::Show() const {
	Person::Show();
	cout << "Nick : " << nick << endl;
}

PokerPlayer::PokerPlayer() : Person() {
}

PokerPlayer::PokerPlayer(const string & fn, const string & ln) : Person(fn, ln) {
}

unsigned int PokerPlayer::Draw() const {
	srand((unsigned int)time(nullptr));
	return rand() % 52 + 1;
}


BadDude::BadDude() : Person(), Gunslinger(), PokerPlayer() {
}

BadDude::BadDude(const string & fn, const string & ln, int ni) : Person(fn, ln), Gunslinger(fn, ln, ni), PokerPlayer(fn, ln) {
}

double BadDude::Gdraw() const {
	return Gunslinger::Draw();
}

unsigned int BadDude::Cdraw() const {
	return PokerPlayer::Draw();
}

void BadDude::Show() const {
	Gunslinger::Show();
}
