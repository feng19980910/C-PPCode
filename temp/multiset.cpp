#include <set>
#include <iostream>
#include <algorithm>
#include <utility>

template <class T, class T1>
class SHOW {
	public:
		void operator()(const T & n) { std::cout << n << ' '; }
		void operator()(const std::pair<T, T1> & p) {
			std::cout << p.first << ' ';
			std::cout << p.second << std::endl;
		}
};

int main() {
	using namespace std;
	
	multiset<pair<int, string>> m;

	m.insert(pair<int, string>(415, "San Francisco"));
	m.insert(pair<int, string>(510, "Oakland"));
	m.insert(pair<int, string>(718, "Brooklyn"));
	m.insert(pair<int, string>(718, "Staten Island"));
	m.insert(pair<int, string>(415, "San Rafael"));
	m.insert(pair<int, string>(510, "Berkeley"));

	cout << "Number of cities with area code 415: "
		<< m.count(pair<int, string>(415, "oakland")) << endl;
	for_each(m.begin(), m.end(), SHOW<int, string>());
		cout << endl;

	return 0;
}
