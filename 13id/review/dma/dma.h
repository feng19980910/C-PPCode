// dam.h -- inheritance and dynmamic memory allocation
#ifndef DMA_H_
#define DMA_H_
#include <iostream>

class ABC {
	public:
		ABC() {};
		virtual ~ABC() {};
		virtual void show() = 0;
};

// Base Class Using DMA
class baseDMA : public ABC {
	private:
		char * label;
		int rating;
	public:
		baseDMA(const char * l = "null", int r = 0);
		baseDMA(const baseDMA & rs);
		virtual ~baseDMA();
		baseDMA & operator=(const baseDMA &rs);
		virtual void show();
};

// derived class without DMA
// no destructor needed
// uses implicit copy constructor
// uses implicit assignment operator
class lacksDMA : public baseDMA {
	private:
		enum { COL_LEN = 40 };
		char color[COL_LEN];
	public:
		lacksDMA(const char * c = "blank", const char * l = "null",	int r = 0);
		lacksDMA(const char * c, const baseDMA & rs);
		virtual void show();
};
// derived class with DMA
class hasDMA : public baseDMA {
	private:
		char * style;
	public:
		hasDMA(const char * s = "none", const char * l = "null",
				int r = 0);
		hasDMA(const char * s, const baseDMA & rs);
		hasDMA(const hasDMA & hs);
		~hasDMA();
		hasDMA & operator=(const hasDMA & rs);
		virtual void show();
};
#endif
