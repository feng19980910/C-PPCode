#ifndef VECTOR_H_
#define VECTOR_H_
#include <math.h>
#include <iostream>
namespace VECTOR {
	using std::sin;
	using std::cos;
	using std::atan;
	using std::sqrt;
	using std::ostream;
	const double Rad_to_degree = 45 / atan(1.0);
	class Vector {
		private:
			enum Mode { POLAR, RECTANGULAR };
			Mode mode;
			double y;
			double x;
			double length;
			double angle;
		public:
			Vector();						// default
			Vector(double n1, double n2, Mode mo = RECTANGULAR);
			double len() { return length; }
			void translate(Mode mo);
			void showdegree();
			Vector operator+(const Vector & v2);
			friend ostream & operator<<(ostream & os, const Vector & vec);	// show by poler form
	};
}


#endif
