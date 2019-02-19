#include <stdio.h>

#define MAX_LENGTH 20



//nodo_t* erase (nodo_t** head, int dato)   --> el doble puntero es para poder modificar la cabecera y después devuelves la nueva cabecera


//FICHEROS//

//int main(){
//	FILE* f=fopen("log.txt", "r");
//
//	if(f==NULL){
//		perror("error");
//		return 0;
//	}
//	fputs("hola somos el a309", f);
//
//	fclose(f);
//return 0;
//}




//int main(){
//	FILE* f=fopen("log.txt", "a");
//
//	if(f==NULL){
//		perror("error");
//		return 0;
//	}
//	fputs("adios", f);
//
//	fclose(f);
//return 0;
//}



//int main(){
//	int i=0;
//	FILE* f=fopen("num.txt", "w");
//
//	if(f==NULL){
//		perror("error");
//		return 0;
//	}
//
//	for (i=0;i<5;i++)
//		fprintf(f, "%d", i);
//	
//	fclose(f);
//return 0;
//}


//int main(){
//	int i=0;
//	char line [MAX_LENGTH];
//	FILE* fin=fopen("num.txt", "r");
//
//	if(f==NULL){
//		perror("error");
//		return 0;
//	}
//	while(1){
//		fgets(line, MAX_LENGTH, fin);
//		if(ferror(fin)){
//			perror("error");
//			break;
//		}
//		//procesar
//		puts(line);
//		if(feof(fin))
//			break;
//	}
//	fclose(fin);
//return 0;
//}


//ejercicio nube de puntos

struct punto_t{
	float x;
	float y;
};

typedef struct punto_t punto;

int main(){
	float x, y;
	punto lp[4]; int i;
	FILE* fin=fopen("num.txt", "r");

	for(i=0;i<4;i++){
		fscanf(fin, "%f%f", &lp[i].x, &lp[i].y);
		//sscanf para tratar la linea 
	}
	
	fclose(fin);
return 0;
}