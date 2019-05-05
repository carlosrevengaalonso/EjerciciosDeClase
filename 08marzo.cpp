#include <stdio.h>

int main(int argc, char **argv){
	alumno a;
	a.nombre="diego";
	...

	//check parametros
	if(argc!=2){
	std::cout<<"introduzca el nombre del archivo"<<std::endl;
	return -1;
	}
	std::string filename=argv[1];
	a309::to_file(filename, a);
}