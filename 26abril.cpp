#include <stdio.h>
#include <iostream>

class Base{
public:
	int x;

	Base(int x=0):x(x){}
	Base(const Base& b);

	Base &operator =(const Base& rhs);

};

class Derivada:public Base{
public:
	int y;

	Derivada(int x):Base(x){y=10;}
	Derivada(const Derivada& d):Base(d){y=d.y;} //*******formato de un constructor copia********

	Derivada &operator =(const Derivada& rhs);
};

Derivada& Derivada &operator =(const Derivada& rhs){ //*******formato de la sobrecarga del operador asignación

	//me copio
	if(this != &rhs ){
		//copio la parte derivada
		this->y=rhs.y; 
	
		//copio la parte base
		//this->x=rhs.x; o la siguiente línea
		Base::operator=(rhs); //o la siguiente línea
		//*static_cast<Base*>(this) =rhs;
	}

	return *this;
}



void main(){
	Derivada d, d1;
	d1=d;
	//Derivada d(10);


	//Derivada d1(d);
	//d1=d;

}