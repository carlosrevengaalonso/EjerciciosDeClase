#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>

using namespace std;
class Punto {
	double x;
	double y;
public:
	Punto() :x(0.0), y(0.0) {}
	Punto(double x,double y):x(x),y(y){}

	friend Punto operator + (const Punto& p1, const Punto& p2);
	Punto operator+(const Punto& p2);
	bool operator!() { return (x == 0.0 && y == 0.0); }
	Punto operator+( double k);
	Punto& operator=(const Punto&); //devuelves la referencia para que en el main puedas hacer una operación si quieres
	Punto& operator+=(const Punto& p);
	friend Punto operator+(double, const Punto&);
	friend Punto operator +(Punto lhs, const Punto& rhs);
	
//I/O
ostream& print(ostream& =cout ) const ;
friend ostream&  operator<<(ostream&,const Punto&);
};


class ManagerPunto{
	Punto l[10];

public:
	Punto operator [] (int index); // si se pusiese "const Punto operator [] (int index) const;" no se podría modificar el punto

};





Punto operator +(Punto lhs, const Punto& rhs){
	lhs+=rhs;
	return lhs;

}

ostream&  operator<<(ostream& o, const Punto& p)
{
	return p.print(o);
	
 }

Punto Punto::operator +(const Punto& p2) {

	cout << "SOY MIEMBRO" << endl;
	Punto res(*this);
	res.x += p2.x;
	res.y += p2.y;
	return res;

}
Punto operator +(const Punto& p1, const Punto& p2)
{
	cout << "SOY INDEPENDIENTE" << endl;
	Punto res(p1);
	res.x += p2.x;
	res.y += p2.y;

	return res;
}
Punto Punto::operator+(double k) {
	Punto res(*this);
	res.x = k;
	res.y = k;

	return res;
}

 Punto operator+(double k, const Punto& p2) {
	 Punto res(p2);
	 res.x = k;
	 res.y = k;

	 return res;
}

 Punto&  Punto::operator=(const Punto& p) {
	 if (this !=&p) {
		 this->x = p.x;
		 this->y=p.y;
	 }
	 return *this;
 }

ostream& Punto::print(ostream& o) const {
	o << "[" << this->x << "," << this->y << "]" << endl;
	return o;
}




struct lessthan{
	bool operator()(int lhs, int rhs){return lhs<rhs;}
};

void main() 
{
	Punto p;
	Punto p1(5.0,7.0);

	std::vector<int> v(10, 0); //10 elementos de valor 0
	cout<<v[3]<<endl; //funiona porque se ha sobrecargado los corchetes
	
	lessthan l;

	if(l(3,5)){cout<<"LHS MENOR QUE RHS"<<endl;}

	int l[20];
	int index=10;

	int k1=l[index++]; //lee la posicion 10 y luego suma
	int k2=l[++index]; //suma y lee la posicion 11


	(p + p1).print();

	//Modo explicito

	operator+(p, p1).print();
	p.operator+(p1).print();
	if (!p) { cout << "estoy en el origen" << endl; }

	//traslacion
	//(p + 17.5).print();
	(17.5 + p).print();
	system("PAUSE");

	//asignación
	p1 = p;
	if (!p1) { cout << "BIEEEEEEEEEN" << endl; }

	//sacar a fichero punto.txt
	ofstream f_out("punto.txt");
	f_out << (!7.5 + p);
	f_out.close();

	
}