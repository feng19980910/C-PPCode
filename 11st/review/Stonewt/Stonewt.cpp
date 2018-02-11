#include "Stonewt.h"
#include <iostream>
Stonewt::Stonewt() {
	stone = pds_left = pounds = 0;
}

Stonewt::Stonewt(int stn, double pds_l) {
	stone = stn;
	pds_left = pds_l;
	pounds = stone * pds_per_stone + pds_l;
}

Stonewt::Stonewt(double pds) {
	pounds = pds;
	stone = int(pds) / pds_per_stone;
	pds_left = pds - stone * pds_per_stone;
}

Stonewt Stonewt::operator*(double mult) {
	Stonewt result;
	result.pounds = mult * pounds;
	result.stone = int(result.pounds) / pds_per_stone;
	result.pds_left = result.pounds - result.stone * pds_per_stone;
	return result;
}

Stonewt operator*(double mult, const Stonewt & t) {
	return Stonewt(t.pounds * mult);
};

std::ostream & operator<<(std::ostream & os, Stonewt & t) {
	os << t.stone << " stone(s), " << t.pds_left << " pounds";
	return os;
}
