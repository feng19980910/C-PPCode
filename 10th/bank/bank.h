#ifndef BANK_H_
#define BANK_H_
class Account {
private:
	char name[51];
	char account[51];
	double deposit;
public:
	Account(const char* nm = "", const char* acc = "", double dp = 0.0);
	void show() const;
	bool dep(const double dp);
	bool draw(double dr);
};

#endif