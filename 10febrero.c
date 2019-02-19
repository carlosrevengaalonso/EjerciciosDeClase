#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//int *allocate_list_of_int(size_t num_elem);
//int *allocate_list_of_int(***pInt,int num_elem); 
//int **allocate_matrix(int N, int F);
//void clear_matrix(int **pMat, int N);
/*
void main()
{
	//void*->puntero a cualquier tipo que quieras
	int *pInt = allocate_list_of_int(10);
	pInt[5] = 8;
	//uso
	printf("el numero es :%d", pInt[5]);

	//libero
	free(pInt);

	system("PAUSE");
}

int *allocate_list_of_int(size_t num_elem)
{
	int j;
	int *pInt = (int*)malloc(sizeof(int)*num_elem); // el tipo al que quieres convertir tiene que ser el mismo que el tipo de origen 
	for (j = 0; j < num_elem; j++) {
		pInt[j] = 0;
	}
	return pInt;
}
// ****************************Reserva de memoria en dos dimensiones(concepto doble puntero)**************************************
void main() 
{
	int N = 2, M = 3;
	int **pMat = allocate_matrix(N, M);
	//uso
	printf(" el numero es: %d", pMat[0][1]);
	printf(" el numero es: %d", pMat[1][0]);
	//libero
	system("PAUSE");

}
int** allocate_matrix(int N, int M)
{
	int j;
	int **pMat = NULL;
	int i;
	//reserva de memoria
	pMat = (int**)malloc(sizeof(int*)*N);
	for (i = 0; i < N; i++)
	{
		pMat[i] = (int*)malloc(sizeof(int)*M);
	}
	//error check
	if (pMat == NULL) {
		perror("error;");
		return NULL;
	}
	// inicializar la matriz a 0s
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			pMat[i][j] = 0;
		}
	}
}
void clear_matrix(int **pMat, int N)
{
	int i;
	if(pMat!=NULL){
	for (i = 0; i < N; i++) {
		free(pMat[i]);

	}
	free(pMat);
	pMat = NULL;
	}
}
*/
struct nodo_t {
	int dato;
	struct nodo_t* siguiente;
};
typedef struct nodo_t nodo;
//INTERFAZ
void printf(nodo* head);
nodo* init(int dato);
void push_back(nodo* head, int dato);
nodo* push_front(nodo** head, int dato);

void clear(nodo*^head); //Limpiar la memoria





void push_back(int *head, int dato) { //Introduce un dato al final de una lista
	nodo* actual = head;
	nodo* pElem;
	while (actual->siguiente != NULL) {
		actual = actual->siguiente;
	}
	//actual->tail
	pElem=nuevo_elemento();
	pElem->dato = dato;
	pElem->siguiente = NULL;
	actual->siguiente = pElem;


}


// funcion auxiliar
nodo* nuevo_elemento() {
	return (nodo*)malloc(sizeof(nodo));

}
nodo *init(int dato) {
	nodo* head = nuevo_elemento();
	head->dato = dato;
	head->siguiente = NULL;
	return head;

}
void imprime_lista(nodo* head){
	nodo *actual = head;
	do {
		printf("%d", actual->dato);
		actual = actual->siguiente;
	} while (actual != NULL);
}

void main()
{
	nodo* head = init(10);
	printf("el dato de la cabeza es :%d\n", head->dato);
	printf(head);
	push_back(head, 27);
	//imprime_lista(head);
	
	push_front(&head, 43);
	printf(head);
	system("PAUSE");
}
nodo_t* push_front(nodo_t** head, int dato) { //Introduce un dato al principio de la lista

	nodo* actual = *head;
	nodo* pElem = nuevo_elemento();
	pElem->dato = dato;
	pElem->siguiente = actual;
	*head = pElem;
	return *head;

}

void clear(nodo* head) {
	nodo* actual = head;
	nodo* siguiente;
	while (actual->siguiente != NULL) {
		siguiente = actual->siguiente;
		free(actual);

	}


}