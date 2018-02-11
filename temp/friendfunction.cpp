// friendfunction.cpp -- to achieve "int + Time" form
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class Time {
	private:
		int hours;
		int minutes;
	public:
		Time(int h = 0, int m = 0);
		friend Time operator+(int min, const Time & t);
		Time operator+(const Time & t) const;
		Time operator+(const int t) const;
		void show();
};
Time::Time(int h, int m) {
	hours = h;
	minutes = m;
	hours += minutes / 60;
	minutes %= 60;
}
Time operator+(int min, const Time & t) {
	Time result;
	result.minutes = min + t.minutes;
	result.hours = result.minutes / 60 + t.hours;
 	result.minutes %= 60;
	return result;
}
Time Time::operator+(const Time & t) const {
	Time result;
	result.minutes = minutes + t.minutes;
	result.hours = result.minutes / 60 + hours + t.hours;
	result.minutes %= 60;
	return result;
}
Time Time::operator+(const int min) const {
	Time result;
	result.minutes = min + minutes;
	result.hours = result.minutes / 60 + hours;
	result.minutes %= 60;
	return result;
}		
void Time::show() {
	cout << hours << " hours, " << minutes << " minutes.\n";
}

int main() {
	Time x(1, 15);
	Time y(0, 46);
	Time z;
	int t = 51;

	cout << "x: "; x.show();
	cout << "y: "; y.show();
	z = x + y;
	cout << "z: "; z.show();
	z = z + t;
	cout << "z = z + t\n";
	cout << "z: "; z.show();
	z = t + z;
	cout << "z = t + z\n";
	cout << "z: "; z.show();

	return 0;
}
