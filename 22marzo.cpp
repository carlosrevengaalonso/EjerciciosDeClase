
//Ejercicio probalble del primer parcial


#include "Esfera.h"
#include "Mundo.h"
#include <iostream>


using namespace std;

struct coord_t{
	double x,y,z;
	coord_t(double x, double y, double z):x(x), y(y), z(z){}
};

class Esfera{
	double r;
	coord_t c;
public:
	Esfera(double r, coord_t c):c(c), r(r){}
};

class Mundo{
	Esfera e;
public:
	Mundo(Esfera e_out):e(e_out){}
//I/O
	ostream& print (ostream& o);
};


ostream& Mundo::print(ostream& o){

	o<<"soy un mundo cruel..."<<endl;

	return o;
}


int main(){
	Esfera e(3, coord_t(1.0, 2.0, 3.0));
	Mundo m1(e);
	Mundo m2(m1);
	m1.print(cout);
	m2.print(cout);
}