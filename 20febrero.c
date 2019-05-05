#include <stdio.h>
#include <stdlib.h>


typedef unsigned int BOOL; //para definir la funcion BOOL no incluida en C
typedef BOOL** mat; //si no haces esto, dónde ponga mat tienes que poner BOOL**

//la estructura del grafo sería la siguiente
//
struct graph_t{
	mat m; // también se podría poner BOOL ady[100][100]; 
	int NV; // numero de vertices
};

typedef struct graph_t graph;


//

/*********************
//allocation utilities 
*********************/



mat allocate_matrix(int N, int M); //crear espacio en memoria
void free_matrix(mat, int N); //borrar espacio en memoria de la matriz
void print_matrix(mat m, int N, int M);

/*********************
//graph management
*********************/

graph* init_graph(int NV); //para inicializar la matriz


void free_graph(graph* pg); //borrar espacio en memoria del grafo
void print_header(graph* pg); //muestra en pantalla el prototipo
void print_edges(graph* pg); //muestra en pantalla los datos
int addEdge(graph* , int v, int w);
BOOL isEdge(graph* , int v, int w);


int degree(graph*, int v); //numero de conexiones que tiene un nodo
int* degree_all(graph*, int l[]); //decir los vecinos que hay en la ciudad (lista de vecinos)

int* sort_vertices_min_deg(graph*, int l[]); //ordenar una lista que le pasas


/*********************
//graph I/O
*********************/

graph* read_graph(const char* filename);




mat allocate_matrix(int N, int M){
	int i,j;
	mat m=(mat)malloc(sizeof(BOOL*)*N);
	for(i=0;i<N;i++){
		m[i]=(BOOL*)malloc(sizeof(BOOL)*M);
	}

	//checking: if(m==NULL){return NULL;}

	//también iría aquí el mensaje de perror de que no hay memoria suficiente

	//initialization to empty matrix
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			m[i][j]=0;
		}
	}

	return m;
}
void free_matrix(mat m, int N){
	int i;
	for(i=0;i<N;i++){
		free(m[i]);
	}
	free(m);
	m=NULL;
}
void print_matrix(mat m, int N, int M){
	int i,j;
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			printf("%d ", m[i][j]);
		}
		puts(""); //se emplea para separar las líneas de la matriz (printf("\n");)
	}
}






graph* init_graph(int NV){
	graph* pg=(graph*)malloc(sizeof(graph));
	//check if(pg==NULL){return NULL;}

	pg->NV=NV;
	pg->m=allocate_matrix(pg->NV, pg->NV);
	//check if(pg->NULL){return NULL;}

	return pg;
}


void free_graph(graph* pg){
	free_matrix(pg->m, pg->NV);
	free(pg);
	pg=NULL;
}

void print_header(graph* pg){
	printf("grafo con %d vertices\n", pg->NV);
}

void print_edges(graph* pg){
	int i,j;
	for(i=0; i<pg->NV-1;i++){
		for(j=i+1; j<pg->NV;j++){
			if(pg->m[i][j]==1){
				printf("[%d--%d]\n", i, j);
			}
		}
	}
}

int addEdge(graph* pg, int v, int w){
	if(v>=pg->NV || v<0) return -1;

	pg->m[v][w]=1;
	pg->m[w][v]=1;
	return 0;
}

BOOL isEdge(graph* pg , int v, int w){ //comprobar que hay una arista


	return pg->m[v][w];

}



graph* read_graph(const char* filename){
	char c, token[50], line[250];
	int v,w, NV, NE, i; //v y w son las aristas; NV y NE son el número de vertices y de aristas
	graph* pg;
	FILE* fin=fopen(filename,"r");
	if(fin==NULL){
		perror("error:");
		return NULL;
	}



	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//primera opcion
	//se puede hacer de la forma que va leyendo línea a línea adjunta en las diapositivas o de la siguiente forma que es más rápida:
	//leer char

	/////////
	//leer hasta la 'p'

	/*c=fgetc(fin); //para ir leyendo los chars
	while(c!='p'){ //mientras que el primer char no sea p, sigues leyendo
		while((c=fgetc(fin))!='\n'){} //sigues leyendo en la misma línea hasta que llegas al \n que sales de este bucle pero sigues buscando la p en la siguiente línea
			c=fgetc(fin);
	}

	//parse header
	fscanf(fin,"%s%d%d", token, &NV, &NE );
	//if(error)... por si no hubiese una línea con p
	//if(feof(fin)).... si llegas al final del fichero sin encontrar una p
	*/



	//segunda opcion
	//leer linea a linea
	while(1){
		fgets(line, 250, fin);
		if(line[0]=='p') break;
		//if(feof(fin)) //error..... return NULL;
	}
	//parse header

	sscanf(line, "%*s%*s%d%d", &NV, &NE);


	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	///// mem alloc graph

	pg=init_graph(NV);
	//check pg!=NULL...


	//leer las aristas
	for(i=0; i<NE; i++){
		fscanf(fin,"%c%d%d", token, &v, &w);
		addEdge(pg, v-1, w-1); //se le resta uno porque en la matriz va de 1 a N y el bucle va de 0 a N
	}


	fclose(fin); //hacer lo primero con el fopen para que no se olvide
}


int degree(graph* pg, int v){ //recorrer la fila y contar los 1
	int deg=0;
	int i;

	for(i=0; i<pg->NV; i++){
		if(pg->m[v][i]==1) deg++;
	}


	return deg;
}


int* degree_all(graph* pg, int l[]){
	int i;
	for (i=0; i<pg->NV; i++){
		l[i]=degree(pg, i);
	}
	return l;
}

int* sort_vertices_min_deg(graph* pg, int l[]){
	int i, j, temp;
	int* deg1=(int*)malloc(sizeof(pg->m[0][0])*pg->NV);
	degree_all(pg, deg1);


	//relleno l con vertces de 1... N
	for(i=0; i< pg->NV; i++)
		l[i]=i;
	//sort
	for (i=0; i<pg->NV-1;i++){
		for (j=i+1; j<pg->NV;j++){
			if(deg1[i] > deg1[j]){
				temp= l[i];
				l[i]=l[j];
				l[j]=temp;
			}
		}
	
	}
	return l;
}

int main(){
	//graph *pg;
	////test matriz
	//mat matriz=allocate_matrix(5,10);
	//matriz[0][1]=1;
	//print_matrix(matriz, 5, 10);
	//free_matrix(matriz, 5);

	////test grafo
	//pg=init_graph(10);
	//print_header(pg);
	//print_edges(pg);
	//free_graph(pg);

	//addEdge(pg,0,1);


	//test fichero
	//int ld[200], SOL=138;
	//graph* pg=read_graph("ejcarreteras.txt");
	//if(pg==NULL) return -1;
	//degree_all(pg, ld);
	//if(ld[199]!=SOL+1) return -1;
	//free_graph(pg);
	
	return 0;
}