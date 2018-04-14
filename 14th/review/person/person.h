// person.h -- declear class person
#ifndef PERSON_H_
#define PERSON_H_
#include <string>
using namespace std;

class Person {
	private:
		string firstname;
		string lastname;
	public:
		Person();
		Person(const string & fn, const string & ln);
		void Show() const;
};

class Gunslinger : virtual public Person {
	private:
		int nick;
	public:
		Gunslinger();
		Gunslinger(const string & fn, const string & ln, int ni);
		double Draw() const;
		void Show() const;
};

class PokerPlayer : virtual public Person {
	public:
		PokerPlayer();
		PokerPlayer(const string & fn, const string & ln);
		unsigned int Draw() const;
};

class BadDude : public Gunslinger, public PokerPlayer {
	public:
		BadDude();
		BadDude(const string & fn, const string & ln, int ni);
		double Gdraw() const;
		unsigned int Cdraw() const;
		void Show() const;
};

#endif
