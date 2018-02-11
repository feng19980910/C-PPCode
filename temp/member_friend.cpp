// member_friend.cpp -- member function and friend function
#include <iostream>
using namespace std;
class My {
	private:
		int m;
	public:
		My(int i);
		friend ostream & operator<<(ostream & os, const My & t);
		// friend My operator-(const My & t);	//友元函数
		My operator-();							//成员函数
};
My::My(int i) {
	m = i;
}
ostream & operator<<(ostream & os, const My & t) {
	os << t.m;
	return os;
}
// My operator-(const My& t) {
My My::operator-() {
	return My(-m);
}

int main() {
	My t(1);
	My m(2);
	cout << t << ' ' << m << endl;
	cout << "-t = " << -t << endl;
	return 0;
}
