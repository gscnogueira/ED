#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

typedef struct lista_no{
	int dado;
	struct lista_no* ant;
	struct lista_no* prox;	
}lista_no;

lista_no* cria_elemento( int i){
	lista_no* e=NULL;
	e=malloc(sizeof(lista_no));
	if(!e)
		return e;
	e->dado=i;
	e->ant=NULL;
	e->prox=NULL;

	return e;

}
_Bool isEmpty(lista_no* lista){
	return(!lista);
}
void insere_inicio(lista_no** lista, lista_no* e){
	if(!lista||!e)
		return;
	e->prox=(*lista);
	if(*lista){
		(*lista)->ant=e;
	}
	(*lista)=e;
}
void insere_final(lista_no** lista, lista_no* e){
	if(!lista||!e)
		return;
	if(isEmpty(*lista)){
		insere_inicio(lista, e);
		return;
	}
	if((*lista)->prox==NULL){
		e->prox=(*lista)->prox;
		e->ant=(*lista);
		(*lista)->prox=e;
		return;
	}
	
	insere_final(&((*lista)->prox), e);
}
void insere_posicao(lista_no** lista, lista_no* e,int pos, int* count){
	if((!lista)||(!e))
		return;
	if(*count==pos){
		e->prox=*lista;
		e->ant=(*lista)->ant;
		if((*lista)->ant){
			(*lista)->ant->prox=e;
		}
		if((*lista)->prox){
			(*lista)->prox->ant=e;
		}
		return;
	}
	(*count)++;
	insere_posicao(&((*lista)->prox),e, pos, count);

}
void remove_inicio(lista_no** lista){
	lista_no* t=NULL;
	if(!lista||!(*lista))
		return;
	t=(*lista);
	if((*lista)->prox)
		(*lista)->prox->ant=(*lista)->ant;
	(*lista)=(*lista)->prox;
	free(t);
}
void remove_final(lista_no** lista){
	lista_no* t=NULL;
	if(!lista||!(*lista))
		return;
	if((*lista)->prox==NULL){
		t=(*lista);
		(*lista)->ant->prox=(*lista)->prox;
		free(t);
		return;
	}
	remove_final(&((*lista)->prox));

}
void remove_posicao(lista_no** lista, int pos, int* count){
	lista_no* t=NULL;
	if(!lista||!(*lista))
		return;
	if(pos==*count){
		t=(*lista);
		(*lista)->ant->prox=(*lista)->prox;	
		(*lista)->prox->ant=(*lista)->ant;
		free(t);
		return;
	}
	(*count)++;
	remove_posicao(&((*lista)->prox), pos, count);
}
void printl(lista_no* lista){
		if(lista==NULL)
			return;			
		printf("%d - ",lista->dado);
		if(lista->ant)
			printf("1 - ");
		else
			printf("0 - ");
		if(lista->prox)
			printf("1\n");
		else
			printf("0\n");
		printl(lista->prox);
	}
void printt(lista_no* lista){
	if(lista==NULL)
			return;			
		printt(lista->prox);
		printf("%d - ",lista->dado);
		if(lista->ant)
			printf("1 - ");
		else
			printf("0 - ");
		if(lista->prox)
			printf("1\n");
		else
			printf("0\n");
}
int tamanho_lista(lista_no* lista){
	if(!lista)
		return 0;
	return 1+tamanho_lista(lista->prox);
}
void mostra_lista( lista_no* lista){
	printl(lista);
	printf("Tamanho: %d\n", tamanho_lista(lista));
}
void mostra_listat( lista_no* lista){
	printt(lista);
	printf("Tamanho: %d\n", tamanho_lista(lista));
}
void libera(lista_no** lista){
	lista_no* t;
	if(isEmpty(*lista))
		return;
	libera(&((*lista)->prox));
	t=(*lista);
	if((*lista)->ant)
		(*lista)->ant->prox=(*lista)->prox;
	free(t);
}
int main(){
	int n, i=1, j;
	lista_no* lista=NULL;

	while(scanf("%d", &n)!= EOF)
		insere_final(&lista, cria_elemento(n));
	
	mostra_lista(lista);
		insere_final(&lista, cria_elemento(43));
	insere_final(&lista, cria_elemento(65));
	putchar('\n');
	mostra_lista(lista);
	insere_inicio(&lista, cria_elemento(56));
	insere_inicio(&lista, cria_elemento(12));
	putchar('\n');
	mostra_lista(lista);
	insere_posicao(&lista,cria_elemento(10), 3,&i);
	insere_inicio(&lista, cria_elemento(15));
	putchar('\n');
	mostra_lista(lista);
	for (j = 0; j < 3; ++j)
		remove_final(&lista);
	putchar('\n');
	mostra_lista(lista);
	for (j = 0; j < 3; ++j)
		remove_inicio(&lista);
	putchar('\n');
	mostra_lista(lista);
	remove_final(&lista);
	i=1;
	remove_posicao(&lista, 3, &i);
	putchar('\n');
	mostra_lista(lista);
	putchar('\n');	
	mostra_listat(lista);



	return 0;
}	