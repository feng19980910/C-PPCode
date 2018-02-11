#include "namesp.h"
#include <iostream>
namespace SALES {
	void setSales(Sales & s, const double ar[], int n) {
		double sum;
		n = n < QUARTERS ? n : QUARTERS;
		s.max = s.min = ar[0];
		sum = 0;
		for (int i = 0; i < n; i++) {
			s.sales[i] = ar[i];
			s.max = s.max > ar[i] ? s.max : ar[i];
			s.min = s.min > ar[i] ? ar[i] : s.min;
			sum += ar[i];
		}
		s.average = sum / n;
	}

	void setSales(Sales & s) {
		using std::cout;
		using std::cin;
		using std::endl;

		cout << "Please input #" << 0 + 1 << " sale: ";
		cin >> s.sales[0];
		s.max = s.sales[0];
		s.min = s.sales[0];
		s.average = 0;
		for (int i = 1; i < QUARTERS; i++) {
			cout << "Please input #" << i + 1 << " sale: ";
			cin >> s.sales[i];
			s.max = s.max > s.sales[i] ? s.max : s.sales[i];
			s.min = s.min < s.sales[i] ? s.min : s.sales[i];
			s.average += s.sales[i];
		}
		s.average /= QUARTERS;
	}

	void showSales(const Sales & s) {
		using std::cin;
		using std::cout;
		using std::endl;

		for (int i = 0; i < QUARTERS; i++)
			cout << "#" << i + 1 << ": " << s.sales[i] << endl;
		cout << "max = " << s.max << endl;
		cout << "min = " << s.min << endl;
		cout << "averaget = " << s.average << endl;
	}
}