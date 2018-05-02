// exc_mean.h -- exception classes for hmean(), gmean()
#include <iostream>
#include <exception>

class Base_exc : public std::logic_error {
	public:
		double v1, v2;
		Base_exc(double a = 0, double b = 0, const char * msg = "base_exc")
			: logic_error(msg), v1(a), v2(b) {}
};

class bad_hmean : public Base_exc {
	public:
		bad_hmean(double a = 0, double b = 0) : Base_exc(a, b, "bad_hmean") {}
 		// void mesg();
};

// inline void bad_hmean::mesg() {
// 	std::cout << "hmean(" << v1 << ", " << v2 << "): "
// 		<< "invalid arguments: a = -b\n";
// }

class bad_gmean : public Base_exc {
	public:
		double v1;
		double v2;
		bad_gmean(double a = 0, double b = 0) : v1(a), v2(b), Base_exc(a, b, "bad_gmean") {}
		// const char * mesg();
};

// inline const char * bad_gmean::mesg() {
// 	return "gmean() grguments should be >= 0\n";
// }
