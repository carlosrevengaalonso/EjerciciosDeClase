#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;


//#define UNIT_TEST_PUNTO
//#define UNIT_TEST_PUNTOBASE
//#define UNIT_TEST_PUNTOCOL
#define UNIT_TEST_UPCAST



class Punto{
 double x;
 double y;
public:

};


class _PuntoBase{

public:
	enum rep_t {CRUZ=0, ESTRELLA, CIRCULO}; //rep_t es el tipo de representación
	enum col_t {AZUL=0, BLANCO, NEGRO};
	static string to_string(rep_t ); //es un genérico, no depende del objeto
	static string to_string(col_t );


protected:
	int id; //estado propio es siempre privado
	_PuntoBase(int id_out):id(id_out){} //para que alguien superior no cree puntos bases y las clases derivadas puedan seguir modificando lo heredado

/////////
//INTERFAZ

public:

	ostream& print(ostream& o=cout)const{o<<"id: "<<id; return o;}


};


string _PuntoBase::to_string(rep_t r){
	string res;

	switch(r){
	case CRUZ:
		res="CRUZ"; //es válido porque el operador = está sobrecargado dentro del string
		break;
	case CIRCULO:
		res="CIRCULO";
		break;
	case ESTRELLA:
		res="ESTRELLA";
		break;
	//default

	return res;
	
	
	}
}

string _PuntoBase::to_string(col_t c){
	string res;

	switch(c){
	case AZUL:
		res="AZUL"; //es válido porque el operador = está sobrecargado dentro del string
		break;
	case BLANCO:
		res="BLANCO";
		break;
	case NEGRO:
		res="NEGRO";
		break;
	//default

	return res;
	
	}


class Punto:public _PuntoBase{
	double x, y;

	//////////////
	//INTERFAZ

public:
	Punto(double x=0.0, double y=0.0, int id=1):x(x), y(y), _PuntoBase(id){} //hay que llamar al constructor de la clase para el identificador
	Punto (const Punto& p, int id_out):x(p.x), y(p.y), _PuntoBase(id_out){} //con este constructor (no es copia) se pueden rellenar las coordenadas de un punto y el identificador
	void set_id(int id_new){id=id_new;} // si id fuese privado daría error pero como es protected no lo da

	
	ostream& print(ostream& o=cout)const;

	template<class U>
	ostream& print(ostream& o=cout)const;

};


template<class U>
ostream& Punto::print(ostream& o)const{

	_PuntoBase::print(o);
	o<<"("<<static_cast<U>(x)<<","<<static_cast<U>(y)<<")"<<endl;// para redondear el numero a entero, float
	return o;
}


ostream& Punto::print(ostream& o)const{
	
	_PuntoBase::print(o);
	o<<"("<<x<<","<<y<<")"<<endl;
	return o;
}


class PuntoCol:public Punto{
	rep_t r;
	col_t c;

	///////////////
	//INTERFAZ

public:
	PuntoCol(rep_t r, col_t c, const Punto& p):r(r), c(c), Punto(p){} //va a utilizar el constructor copia del punto, aunque no lo hemos creado
	ostream& print(ostream& o=cout)const;

};

ostream& PuntoCol::print(ostream& o)const{
	//_PuntoBase::id=8; daría error porque la funcion print es const
	Punto::print(o);
	o<<to_string(r)<<" "<<to_string(c)<<endl;

	return o;
}


//////////////
//IMPORTANTE//
//////////////
void imprimir(_PuntoBase* pb){pb->print();} //se traga cualquier objeto de la jerarquía que esté aguas abajo del PuntoBase (UPCAST)
//////////////



void main(){

#ifdef UNIT_TEST_PUNTOBASE
	//_PuntoBase pb(120);
	//pb.print();
	
	cout<<_PuntoBase::to_string(_PuntoBase::AZUL); //IMPORTANTE

#endif

#ifdef UNIT_TEST_PUNTO
	Punto p(3.15, 7.45, 100);
	p.print();
	p.print<int>();
	p._PuntoBase::print();

#endif

#ifdef UNIT_TEST_PUNTOCOL
	PuntoCol pc(_PuntoBase::CIRCULO, _PuntoBase::AZUL, Punto(10.0, 11.0, 100);
	pc.print();
	pc.Punto::print();
	pc._PuntoBase::print();

#endif

#ifdef UNIT_TEST_UPCAST
	PuntoCol pc(_PuntoBase::CIRCULO, _PuntoBase::AZUL, Punto(10.0, 11.0, 100);
	imprimir(&pc);

#endif
}