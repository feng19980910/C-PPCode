// exception.cpp -- do exception mode by myself
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

class myexcept {
	private:
		string msg;
	public:
		myexcept(const string & message = "this is an unkown error") : msg(message) {}
		const string & what() { return msg; }
};

class index_error : public myexcept {
	private:
		int ind;
	public:
		index_error(int i, const string & mg = "there is an index error") : myexcept(mg), ind(i) {}
		int index() { return ind; }
};

class type_error : public myexcept {
	public:
		type_error(const string & mg = "there is an type error") : myexcept(mg) {}
};

template <typename type>
class simple_array {
	private:
		int size;
		type * arr;
	public:
		simple_array(const type * a, int s) : size(s) {
			arr = new type[size];
			for (int i = 0; i < size; ++i)
				arr[i] = a[i];
		}
		~simple_array() { delete [] arr; }
		type operator[](int i) const;
		type & operator[](int i);
		void raise_type_error();
};
template <typename type>
type simple_array<type>::operator[](int i) const {
	if (i >= size || i < 0)
		throw index_error(i);
	return arr[i];
}

template <typename type>
type & simple_array<type>::operator[](int i) {
	if (i >= size || i < 0)
		throw index_error(i);
	return arr[i];
}

template <typename type>
void simple_array<type>::raise_type_error() {
	throw type_error();
}


int main() {
	int int_array[3] = { 1, 2, 3 };
	simple_array<int> array(int_array, 3);

	cout << "the simple_array<int> array has been initialized by 3 items." << endl;
	cout << "but now, I try to get array[3], and catch the exceptrion." << endl;
	
	try {
		array[3];
	}
	catch (index_error & ie) {
		cout << "the error information: " << endl;
		cout << ie.what() << endl;
		cout << "the illegal index is: " << ie.index() << endl;
	}
	cout << endl;

	cout << "try to raise type_error, however use an unsignience function" << endl;
	try {
		array.raise_type_error();
	}
	catch (type_error & te) {
		cout << "the error information: " << endl;
		cout << te.what() << endl;
	}
	cout << endl;

	cout << "the unknown error" << endl;
	try {
		array[3];
	}
	catch (myexcept & me) {
		cout << "the error message:" << endl;
		cout << me.what() << endl;
	}
	cout << endl;

	return 0;
}
