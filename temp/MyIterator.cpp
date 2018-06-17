#include <iostream>
#include <vector>
#include <algorithm>
using std::cout;
using std::endl;

template <typename type>
class can {
	private:
		type * items;
		int _size;
	public:
		can() : items(nullptr), _size(0) {}
		can(int i) : items(new type[i]), _size(i) {}
		can(const can & c) : items(new type[c._size]), _size(c._size) {
			for (int i = 0; i < c._size; i++)
				items[i] = c.items[i];
		}
		~can() { delete [] items; }

		type & operator[](int i) { return items[i]; }
		int size() { return _size; }

		class iterator;
		iterator begin() { return iterator(*this); }
		iterator end() { return iterator(*this, this->_size); }

		class iterator {
			private:
				int i;
				type * subitems;
			public:
				iterator(const can & c, int i0 = 0) : i(i0), subitems(c.items) {}
				//iterator(int i0 = 0) : i(i0), subitems(items) {}

				iterator & operator=(const can & c) { subitems = c._items, i = 0; }
				iterator & operator++() { i++; return *this; }
				iterator operator++(int) { iterator temp(*this); i++; return temp; }
				type operator*() { return subitems[i]; }
				bool operator==(const iterator & it) { return this->subitems == it.subitems && this->i == it.i; }
				bool operator!=(const iterator & it) { return !this->operator==(it); }
				iterator operator+(int i) { return iterator(this->i + i); }
		};
};

template <typename t>
void show(const t & it) { cout << it << endl; }
int main() {
	can<int> temp(10);
	for (int i = 0; i < 10; ++i)
		temp[i] = i;
	can<int>::iterator it = temp;
	for (can<int>::iterator i = temp; i != temp.end(); ++i)
		cout << *i << endl;
// 	can<int> temp(10);
// 	for (int i = 0; i < 10; i++)
// 		temp[i] = i;
// 	for (can<int>::iterator it = temp.begin(); it != temp.end(); it++)
// 		cout << *it << ' ';
// 	cout << endl;
// 	typedef void (*p)(const typename can<int>::iterator);
// 	std::for_each(temp.begin(), temp.end(), show);

	return 0;
}
