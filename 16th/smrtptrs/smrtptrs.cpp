// smrtptrs.cpp -- using three kinds of smart pointers
// requires support of C++11 shared_ptr and unique_ptr
#include <iostream>
#include <string>
#include <memory>

class Report {
	private:
		std::string str;
	public:
		Report(const std::string & s) : str(s) 
			{ std::cout << "Object created!" << std::endl; }
		~Report() { std::cout << "Object deleted!" << std::endl; }
		void comment() const { std::cout << str << std::endl; }
};

int main() {
	{
		std::auto_ptr<Report> ps(new Report("using auto_ptr"));
		ps->comment();		// use -> to invoke a member function
	}
	{
		std::shared_ptr<Report> ps(new Report("using shared_ptr"));
		ps->comment();
	}
	{
		std::unique_ptr<Report> ps(new Report("using unique_ptr"));
		ps->comment();
	}
	return 0;
}
