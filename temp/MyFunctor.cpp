// functor.cpp -- class which overload operator()
#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <utility>

// a functor
class Fun {
	public:
		void operator()(const std::pair<int, std::string> & p) {
			std::cout << p.first << ' ' << p.second << std::endl;
		}
};

template <typename _iterator, class func>
void For_each(_iterator begin, _iterator end, func f) {
	for (begin; begin != end; ++begin)
		f(*begin);
}

void func(const std::pair<int, std::string> & p) {
	using namespace std;
	cout << p.first << ' ' << p.second << endl;
}

int main() {
	using namespace std;

	class Fun fun;
	typedef pair<int, string> Pair;
	typedef map<int, string> Map;

	Map m;
	m.insert(Pair(3, "cde"));
	m.insert(Pair(2, "bcd"));
	m.insert(Pair(4, "def"));
	m.insert(Pair(2, "zzz"));

	For_each(m.begin(), m.end(), fun);
	For_each(m.begin(), m.end(), func);

	return 0;
}

