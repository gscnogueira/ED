#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

typedef struct atvd_t{
	char descricao [501];
	int pri;
	struct atvd_t* lig;

}atvd_t;
typedef struct fila{
	atvd_t* inicio;
	atvd_t* fim;
}fila;

atvd_t* cria_elemento(char* string, int pri){
	atvd_t* e=NULL;
	e=malloc(sizeof(atvd_t));
	if(!e)
		return e;
	strcpy(e->descricao, string);
	e->pri=pri;
	e->lig=NULL;

	return e;
}
void cria_fila(fila* fila){
	fila->inicio=NULL;
	fila->fim=NULL;
}
_Bool isEmpty(fila* fila){
	return (!(fila->inicio) && !(fila->fim));
}
void enqueue(fila* fila, atvd_t* e){
	if(!e||!fila)
		return;
	if(isEmpty(fila))
		fila->inicio=e;
	else 
		fila->fim->lig=e;
	fila->fim=e;
}
void dequeue(fila* fila){
	atvd_t* e=NULL;
	if(!fila||isEmpty(fila))
		return;
	e=fila->inicio;
	fila->inicio=e->lig;
	if(!fila->inicio)
		fila->fim=NULL;
	free(e);
}
void mostra_elementos(atvd_t* atvd){
	if(!atvd)
		return;
	printf("Atividade: %s Prioridade: #%d \n", atvd->descricao, atvd->pri);
	mostra_elementos(atvd->lig);
}
int qtd_elementos(atvd_t* atvd){
	if(!atvd)
		return 0;
	return 1+qtd_elementos(atvd->lig);
}
int tam_fila(fila* fila){
	int i, tam;
	for(i=0; i<10; ++i)
		tam+=qtd_elementos((&fila[i])->inicio);
	return tam;

}
void mostra_fila(fila* fila){
	int i;
	printf("Tamanho da fila: %d \n", tam_fila(fila));
	for(i=0; i<10;++i){
		if(!isEmpty(&fila[i]))
			mostra_elementos((&fila[i])->inicio);
	}
}

int main(){
	char descricao[501];
	int pri;
	int n, i, j=0;
	fila atividades[10];
	for (i = 0; i < 10; ++i)
		cria_fila(&(atividades[i]));
	while(scanf("%s", descricao)){
		if(isdigit(descricao[0])){
			n=atoi(descricao);
			break;
		}
		scanf("%d", &pri);
		enqueue(&atividades[pri-1], cria_elemento(descricao,pri));	
	}
	while(n&&j<10){
		while(isEmpty(&atividades[j]))
			j++;
		if(j>=10)
			break;
		dequeue(&atividades[j]);
		n--;
	}
		mostra_fila(atividades);



	return 0;
}