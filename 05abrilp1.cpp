#include "stdio.h"
#include <stdlib.h>
#include <iostream>
#include <math.h>
#define PI 3.141592//para activar el PI

//ejemplo de calculo del area para un Circulo, triangulo y cuadrado

//class Circulo{
//	double radio;
//
//public:
//	Circulo(double r):radio(r){}
//	double area() const{
//		return PI*radio*radio;
//	}
//};
//
//class Triangulo{
//	double base, altura;
//
//public:
//	Triangulo(double b, double a):base(b), altura(a){}
//	double area() const{
//		return (base*altura)/2;
//	}
//};
//
//class Cuadrado{
//	double lado;
//
//public:
//	Cuadrado(double l):lado(l){}
//	double area() const{
//		return lado*lado;
//	}
//};
//
//class Geom{
//	const Cuadrado* pcu; //puntero a algo que es constante 
//	const Triangulo* pt;
//	const Circulo* pcir;
//
//public:
//	Geom(Cuadrado* c):pcu(c), pcir(NULL), pt(NULL) {}
//	Geom(Triangulo* t):pcu(NULL), pcir(NULL), pt(t){}
//	Geom(Circulo* cir):pcu(NULL), pcir(cir), pt(NULL){}
//	double area();
//};
//
//double Geom::area(){
//	if(pcu!=NULL){pcu->area();}
//	if(pt!=NULL){pt->area();}
//	if(pcir!=NULL){pcir->area();}
//
//}
//
//void main(){
//
//
//
//
//
//}


