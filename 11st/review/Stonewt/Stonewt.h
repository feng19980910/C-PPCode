#ifndef STONEWT_H_
#define STONEWT_H_
#include <iostream>
class Stonewt {
	private:
		enum { pds_per_stone = 14 };
		int stone;
		double pds_left;
		double pounds;
	public:
		Stonewt();							// default
		Stonewt(int stn, double pds_l);		// stone and pounds form
		Stonewt(double pds);				// pounds form
		Stonewt operator*(double mult);		// operator *
		friend Stonewt operator*(double mult, const Stonewt & t);
		friend std::ostream & operator<<(std::ostream & os, Stonewt & t);
};
#endif
