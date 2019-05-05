#include "stdio.h"
#include <iostream>
#include "math.h"

#include "globals.h"
#include "Geom.h"

void main(){
	TRIANGULO_GLOBAL.print(std::cout);
	std::cout<<VARIABLE_GLOBAL<<std::endl;
	a309::TRIANGULO_GLOBAL_A309.print(std::cout);



	std::cout<<mis_datos_globales::VARIABLE_GLOBAL<<std::endl;
}

