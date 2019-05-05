#include <stdio.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>


//using namespace std;
struct alumno{
	std::string nombre;
	std::string asignatura;
	int id_mat;
	int id_grupo;
};


void unit_test_to_string();
int unit_test_read_alumno();

namespace a309{

	///////////
	///interfaz publico
	std::string to_string(const alumno&);
	int read_alumno(alumno &a);
	void clear_alumno(alumno& a);


	//////////
	//definiciones
	std::string to_string(const alumno& a){
		std::string res;


		//formato nombre
		std::string nombre = "nombre:";
		nombre+=a.nombre;
		nombre+='\n';


		//formato asignatura
		std::string asignatura = "asignatura:";
		asignatura+=a.asignatura;
		asignatura+='\n';

		//formato matricula       PROBLEMA:    el string no aguanta el número de la matrícula como cadena
		std::string matricula = "matricula:";
		std::stringstream sstr; //almacen para la matricula
		sstr<<a.id_mat;
		matricula+=sstr.str();
		matricula+='\n';

		//formato grupo     
		std::string grupo = "grupo:";
		std::stringstream sstr_grupo; 
		sstr_grupo<<a.id_grupo;
		grupo+=sstr_grupo.str();
		grupo+='\n';
		//final
		res+=nombre;
		res+=asignatura;
		res+=matricula;
		res+=grupo;



		return res;
	}
	int read_alumno(alumno &a){
		//introducir datos de un alumno
		clear_alumno(a);
		std::cout<<"introduzca datos <N>  <A>  <id_mat>  <id_group>"<<std::endl;

		std::cin>>a.nombre>>a.asignatura>>a.id_mat>>a.id_grupo;
		if(!std::cin) return -1;

		return 0;
	
	}
	void clear_alumno(alumno& a){
		a.nombre=" ";
		a.asignatura=" ";
		a.id_mat=0;
		a.id_grupo=0;
	}
}




//int read_alumnos(alumnos &d);

//int to_file(string filename, const alumno &str);
//int from_file(string filename, alumnos& str);



void unit_test_to_string(){
	alumno a;
	a.nombre="juan";
	a.asignatura="inf_ind";
	a.id_mat=57550;
	a.id_grupo=3;

	std::cout<<a309::to_string(a);

}

int unit_test_read_alumno(){
	alumno a;
	if(a309::read_alumno(a)!=0) return -1;

	std::cout<<a309::to_string(a);

}

void main()
{
	if(unit_test_to_string()!=0) {std::cout<<"error"; }

}