#include <stdio.h>
#include <iostream>
#include <string>



//crear y borrar memoria de una matriz en c++                                                        ¡¡¡¡IMPORTANTE!!!!

/*int ** allocate_matrix(int N, int M){
	int** m = new int*[N];
	for(int i=0; i<N;i++){
		m[i]=new int[M];
	}

	//inicialización
	return m;
}


void free_matrix(int** m, int N){
	for(int i=0;i<N;i++){
		delete[] m[i]; //corchete en delete porque es una colección de punteros
	}
	delete[] m;
	m=NULL;

}*/


//ejercicios con string 


using namespace std; //importante para utilizar cout, string, ...

int main(){
	string str="mi abuela"; 
	string str1=str;


	//cout<<"longitud:"<<str.size()<<endl; // también se puede poner str.length();

	//cout<<str1<<endl;

	size_t pos=str.find("abuela",3, 2); //buscar en el buffer de string "abuela" empezando desde la posición 3, los dos primeros caracteres de abuela ->ab
	if(pos!=string::npos){
		cout<<"posicion:"<<pos; //imprime un 3 que es la posicion donde esta
	}
	


}