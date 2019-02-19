#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


//Realice un programa que sustituya la palabra crueeeel por cruel
/*
int main(){
	char str[]="hola mundo crueeeel";
	char* pChr;

	pChr=strchr(str,'c');
	strcpy(pChr, "cruel");
	puts(str);

	return 0;
}
*/







//Ejemplo para ver como funciona el sprintf: imprime una cadena
/* 
int main(){
	int num=50;
	char str[100];
	sprintf(str, "los alumnos del A309 son %d", num);
	puts(str);
}
*/





//Ejercicio que recoja un numero introducido en una frase y que lo imprima por pantalla 

/*
char* leer_frase(char* dest);
int extraer_numero(const char* dest);


int main(){
	
	int num=0;
	char str[250];

	leer_frase(str);
	num=extraer_numero(str);
	printf("%d", num);
	return 0;

}


char* leer_frase(char* dest){
	//leer flujo stdin
	printf("Introduzca una frase:\n");
//	esto sólo cogería hasta el primer espacio
	//scanf("%s", dest);
	//puts(dest);

//esto lee todo lo que encuentra hasta el \n:
//^ significa complementario
	scanf("%[^\n]", dest);
	puts(dest);

	return dest;
}

int extraer_numero(const char* dest){
	char token[50];
	int num=0;

	sscanf(dest,"%*[^0123456789]%d", &num);
	//* significa que ignoras todo lo de dentro del paréntesis (todo lo que no sean números) e imprimes ese número
	return num;

}

*/



int leer_numero_matricula(char* dest);
int extraer_numero(const char* dest);


int main(){
	
	int num=0;
	char str[250]="manuel_87550";
	num=leer_numero_matricula(str);
	printf("%d", num);
	return 0;

}

int leer_numero_matricula(char* dest)
{
	int i=0, num=0;
	char* pChr=dest;

	for(i;	*pChr!='\0';pChr++){

		if(isdigit(*pChr)){ //si es un digito entra en el if
			num=strtol(pChr, NULL, 10);
			break;
		}
	}

	return num;

}


