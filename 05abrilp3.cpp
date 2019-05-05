#include "stdio.h"
#include <iostream>


//PREGUNTA TEST: Si A es amigo de B y B es amigo de C, ¿A es amigo de C?-->NO

//EJEMPLO CON FRIEND
using namespace std;

class PRUEBA; //Si no se pusiese esta línea, la función triturador_foo no sabría qué es prueba por el orden de lectura de las líneas

int triturador_foo(PRUEBA& p){p.estado= 0;}

ostream& print(ostream& o, const PRUEBA &p){
	o<<p.estado<<endl;
	return o;
}

class PRUEBA{
	friend class JV;
	friend int triturador_foo(PRUEBA& p);
	int estado;
	friend ostream& print(ostream& o, const PRUEBA &);
public:
	PRUEBA(int e):estado(e){}
};

class JV{ //juanito valderrama
public:
	void triturar_PRUEBA(PRUEBA& p){p.estado=0;}

};

int main(){
	PRUEBA p(10);
	JV juanito;
	print(cout,p);

	juanito.triturar_PRUEBA(p);

	return 0;
}


