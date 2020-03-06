#include <stdio.h>
#include <stdlib.h>	
#include <string.h>

typedef struct LSE_int
{
	int dado;
	struct LSE_int* prox;
}lse_int;


lse_int* cria_elemento(int dado){
	lse_int* e=NULL;
	if(dado){
		e=malloc(sizeof(lse_int));
		e->dado=dado;
		e->prox=NULL;
	}
	return e;
}
void insere_no_incio(lse_int** lista, lse_int* e){
	if((!lista)||(!e))
		return;
	e->prox=(*lista);
	(*lista)=e;
}
void insere_no_final(lse_int** lista, lse_int* e){
	if((!lista)||(!e))
		return;
	if(!(*lista))
		(*lista)=e;
	if((*lista)->prox==NULL){
		(*lista)->prox=e;
		e->prox=NULL;
		return;
	}
	insere_no_final(&((*lista)->prox),e);
}
void remove_final(lse_int** lista){
	lse_int* e=NULL;
	if((!lista)||(!(*lista)))
		return;
	if((*lista)->prox==NULL){
		e=*lista;
		printf("%d\n",e->dado);
		(*lista)=(*lista)->prox;
		free(e);
		return;
	}
	if((*lista)->prox->prox==NULL){
		e=(*lista)->prox;
		(*lista)->prox=NULL;
		printf("%d\n",e->dado);
		free(e);
		return;
	}
	remove_final(&((*lista)->prox));	
}
void remove_inicio(lse_int** lista){
	lse_int* e=NULL;
	if(!lista||(!(*lista)))
		return;
	e=(*lista);
	(*lista)=(*lista)->prox;
	(e)->prox=NULL;
	printf("%d\n",e->dado);
	free(e);
}
void printl(lse_int* lista){
	if(lista==NULL)
		return;
	printf("%d\n",lista->dado);
	printl(lista->prox);
}
void remove_valor(lse_int** lista, int v, int* remocoes){
	lse_int* e= NULL;

	if(!lista||(!(*lista))||(!remocoes)){
		return;
	}
	if((*lista)->dado==v){
		e=(*lista);
		(*lista)=(*lista)->prox;
		free(e);
		(*remocoes)++;
	remove_valor(lista,v, remocoes);
	}
	else
		remove_valor(&((*lista)->prox),v, remocoes);
}
void remove_posicao(lse_int** lista, int pos, int* i){
	lse_int* e=NULL;
	if(!lista||(!(*lista))){
		return;
	}
	if((*i)==pos){
		e=(*lista);
		*lista=(*lista)->prox;
		printf("%d\n",e->dado);
		free(e);
		return;
	}
	(*i)++;
	remove_posicao(&((*lista)->prox), pos, i);

}
void troca_valor(lse_int** lista, int a, int n){
	if(!lista||(!(*lista)))
		return;
	if((*lista)->dado==a){
		(*lista)->dado=n;
		return;
	}
	troca_valor(&((*lista)->prox), a, n);
}
int ocorrencias(lse_int** lista, int v){
	if(!lista||(!(*lista)))
		return 0;
	if((*lista)->dado==v)
		return ocorrencias(&((*lista)->prox),v)+1;
	else
		return ocorrencias(&((*lista)->prox),v);
}
int main(){
	char c;
	int a, i,n;
	int remocoes;
	lse_int* lista=NULL;
	

	while(1){
		scanf("%c",&c);
		if(c=='F'){
			scanf("%d",&a);
			insere_no_final(&lista,cria_elemento(a));
		}
		if(c=='I'){
			scanf("%d",&a);
			insere_no_incio(&lista,cria_elemento(a));

		}
		if(c=='P'){
			remove_final(&lista);
		}
		
		if(c=='D')
			remove_inicio(&lista);
		if(c=='V'){
			remocoes=0;
			scanf("%d",&a);
			remove_valor(&lista,a,&remocoes);
			printf("%d\n",remocoes);
		}
		if(c=='E'){
			i=1;
			scanf("%d",&a);
			remove_posicao(&lista, a, &i);
		}
		if(c=='T'){
			scanf("%d",&a);
			scanf("%d",&n);
			troca_valor(&lista, a, n);
		}
		if(c=='C'){
			scanf("%d",&a);
			printf("%d\n",ocorrencias(&lista, a));

		}
		if(c=='X'){	
			putchar('\n');
			printl(lista);
			break;
		}
	}
	

	return 0;
}