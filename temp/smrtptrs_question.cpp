// requires support of C++11 shared_ptr and unique_ptr
#include <iostream>
#include <string>
#include <memory>

class Report {
	private:
		std::string str;
	public:
		static int count;
		Report(const std::string & s) : str(s) 
			{ std::cout << "Object created!" << ' ' << this << std::endl; ++count; }
		~Report() { std::cout << "Object deleted!" << ' ' << this << std::endl; }
		void comment() const { std::cout << str << ' ' << count << std::endl; --count; }
};
int Report::count = 0;

int main() {
	// use normal construcotr
	Report::count = 0;
	{
		std::unique_ptr<Report> ps(new Report("make one by meself"));
		Report * p = new Report("make one by myself");
		// ps = std::unique_ptr<Report>(p);
		ps->comment();
		p->comment();
		delete p;
	}
	std::cout << Report::count << std::endl << std::endl;

	// use operator=
	Report::count = 0;
	{
		std::unique_ptr<Report> ps;
		Report * p = new Report("make one by myself");
		ps = std::unique_ptr<Report>(p);
		ps->comment();
		p->comment();
		delete p;
	}
	std::cout << Report::count << std::endl << std::endl;

	Report::count = 0;
	{
		std::shared_ptr<Report> ps;
		Report * p = new Report("make one by myself");
		ps = std::shared_ptr<Report>(p);
		ps->comment();
		p->comment();
		delete p;
	}
	std::cout << Report::count << std::endl << std::endl;

	Report::count = 0;
	{
		std::auto_ptr<Report> ps;
		Report * p = new Report("make one by myself");
		ps = std::auto_ptr<Report>(p);
		ps->comment();
		p->comment();
		delete p;
	}
	std::cout << Report::count << std::endl << std::endl;

	return 0;
}
