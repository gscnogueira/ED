#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#define TAMANHO 2000

typedef struct {
    char vertices[TAMANHO];
    unsigned int arestas[TAMANHO][TAMANHO];
    unsigned int ordem;
} grafo_t;
/* Atenção, não  modifique o trecho acima! */

/* Retorna o índice do vértice no vetor, caso exista, -1 caso contrário. */
int idx_vertice(grafo_t* g, char v) {
	int i;
  	if(!g||!v)
  		return -1;
  	for(i=0;i<TAMANHO;i++){
  		if (g->vertices[i]==v)
  			return i;
  	}
  	return -1;
}
_Bool aresta(grafo_t* grafo, char origem, char destino) {
	int a,b;
		if(!grafo||!origem||!destino)
			return false;
		a=idx_vertice(grafo, origem);
		b=idx_vertice(grafo, destino);
		if(a==-1||b==-1)
			return false;
		grafo->arestas[a][b]=1;
		grafo->arestas[b][a]=1;
    	
    	return true;

}

int main(){





	return 0;
}