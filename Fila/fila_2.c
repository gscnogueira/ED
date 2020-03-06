#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>


typedef struct element{
	char nome[50];
	struct element* lig;
}element;

typedef struct fila{
	struct element* final;
	struct element* inicio;
}fila;


element* cria_elemento(char* nome){
	element* e=NULL;
	e=malloc(sizeof(element));
	if(!e)
		return e;
	strcpy(e->nome, nome);
	e->lig=NULL;
	return e;
}
void cria_fila(fila* fila){
	if(!fila)
		return;
	fila->final=NULL;
	fila->inicio=NULL;
}
_Bool isEmpty(fila* fila){
	return(fila->final==NULL&&fila->inicio==NULL);
}
void enqueue(fila* fila, element* e){
	if(!e||!fila)
		return;
	if(isEmpty(fila))
		fila->inicio=e;	
	else
		fila->final->lig=e;

	fila->final=e;
	e->lig=NULL;
}
element* dequeue(fila* fila){
	element* t=NULL;
	if(isEmpty(fila))
		return t;
	t=fila->inicio;
	fila->inicio=t->lig;
	if(!(fila->inicio)){
		fila->final=NULL;
	}
	return t;
}	
element front(fila* fila){
	return *(fila->inicio);
}
void mostra_fila(element* e){
	if(!e)
		return;
	printf("%s\n",e->nome);
	mostra_fila(e->lig);

}
void limpa_fila(element* fila){
	if(!fila)
		return;
	limpa_fila(fila->lig);	
	free(fila);
}
int main(){
	fila fila;
	element* aux;
	char nome [50];
	int n;
	cria_fila(&fila);
	while(scanf("%s", nome)){
		if(isdigit(nome[0]))
			break;
		enqueue(&fila,cria_elemento(nome));
	}
	n=atoi(nome);
	while(n){ 
		aux=dequeue(&fila);
		enqueue(&fila, aux);
		n--;
	}
	if(!isEmpty(&fila)){
	printf("Pessoa da frente: %s\n", (&fila)->inicio->nome);
	printf("Pessoa do fim: %s\n", (&fila)->final->nome);

	}
	limpa_fila((&fila)->inicio);




	return 0;
}