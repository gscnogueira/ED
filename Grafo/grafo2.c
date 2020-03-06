#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#define TAMANHO 2000

/* TAMANHO é um valor constante. */

typedef struct {
    char vertices[TAMANHO];
    unsigned int arestas[TAMANHO][TAMANHO];
    unsigned int ordem;
} grafo_t;
/* Atenção, não  modifique o trecho acima! */

/* Retorna a quantidade de arestas que incidem sobre um vértice. */
int grau_de_entrada(grafo_t* g, char vertice) {
    int a, i,vertices=0;
    if(!g||!vertice)
    	return 0;
    a=idx_vertice(g, vertice);
    for(i=0;i<g->ordem; i++){
    	if(g->arestas[i][a]==1)
    		vertices++;
    }

    return vertices;
}

int main(){





	return 0;
}