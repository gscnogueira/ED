#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

typedef struct element_t{
	char tipo[51];
	char cor [51];
	int time;
	struct element_t* prox;
}element_t;

element_t* cria_elemento(char* tipo, char* cor, int time){
	element_t* e=NULL;
	e=malloc(sizeof(element_t));
	if(!e)
		return e;
	strcpy(e->tipo, tipo);
	strcpy(e->cor, cor);
	e->time=time;
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
	char tipo[51];
	char cor [51];
	int time, roupas=0, total=0;

	while(scanf("%s", tipo)){
		if(!strcmp(tipo,"end"))
			break;
		scanf("%s %d", cor, &time);
		push(&pilha, cria_elemento(tipo, cor, time));
	}
	while(!isEmpty(pilha)){
		printf("Tipo: %s Cor: %s\n",top(&pilha)->tipo, top(&pilha)->cor);
		total+=top(&pilha)->time;
		roupas++;
		pop(&pilha);
	}
	printf("Total de roupas = %d\n",roupas);
	printf("Total de tempo = %d\n",total);

	return 0;
}