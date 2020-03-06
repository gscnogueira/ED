#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

typedef struct element_t{
	int peso;
	struct element_t* prox;
}element_t;

element_t* cria_elemento(int peso){
	element_t* e=NULL;
	e=malloc(sizeof(element_t));
	if(!e)
		return e;
	e->peso=peso;
	e->prox=NULL;
	return e;
}
_Bool isEmpty(element_t* pilha){
	return (!pilha);
}
void push(element_t** pilha, element_t* e){
	if(!e||!pilha)
		return;
	e->prox=*pilha;
	*pilha=e;
}
void pop(element_t** pilha){
	element_t* t=NULL;
	if(!pilha||!(*pilha))
		return;
	t=(*pilha);
	(*pilha)=(*pilha)->prox;
	free(t);
}
element_t* top(element_t** pilha){
	if(!pilha||!(*pilha))
		return NULL;
	return (*pilha);
}
int main(){
	element_t* pilha=NULL;
	int peso, total=0, peso_retirado=0;

	while(scanf("%d", &peso)){
		if(!peso)
			break;
		push(&pilha, cria_elemento(peso));	
	}
	scanf("%d", &peso);
	while(top(&pilha)->peso!=peso){
		printf("Peso retirado: %d\n",top(&pilha)->peso);
		peso_retirado+=top(&pilha)->peso;
		total++;
		pop(&pilha);
	}
	printf("Anilhas retiradas: %d\n",total );
	printf("Peso retirado: %d\n", peso_retirado);




	return 0;
}