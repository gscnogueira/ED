#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

typedef struct ab_int
{
		char dado;
		struct ab_int* esq;
		struct ab_int* dir;

}ab_int;
ab_int* elemento(char c){
	ab_int* e=NULL;
	e=malloc(sizeof(ab_int));
	if(!e)
		return e;
	e->dado=c;
	e->esq=NULL;
	e->dir=NULL;
	return e;
}
void mostra_arvore(ab_int* raiz) {
    putchar('(');
    if(!raiz){
    	putchar(')');
   		return;	
    }
    printf("%d ",raiz->dado);	
    mostra_arvore(raiz->esq);
    putchar(' ');
    mostra_arvore(raiz->dir);
	putchar(')');
}
void insere(ab_int** raiz, ab_int* e){
	if(!raiz)
		return;
	if(!(*raiz)){
		*raiz=e;
		return;
	}
	if(e->dado>(*raiz)->dado)
		insere(&((*raiz)->dir), e);
	else
		insere(&((*raiz)->esq), e);
}
void rotaciona_esquerda(ab_int **p_raiz) {
	if(!p_raiz||!(*p_raiz))
		return;
	if(!(*p_raiz)->dir)
		return;
    ab_int* aux=(*p_raiz);
   	(*p_raiz)=(*p_raiz)->dir;
   	aux->dir=(*p_raiz)->esq;
   	(*p_raiz)->esq=aux;

}
void rotaciona_direita(ab_int **p_raiz){
	if(!p_raiz||!(*p_raiz))
		return;
	if(!(*p_raiz)->esq)
		return;
    ab_int* aux=(*p_raiz);
   	(*p_raiz)=(*p_raiz)->esq;
   	aux->esq=(*p_raiz)->dir;
   	(*p_raiz)->dir=aux;


}
void em_lista(ab_int **p_raiz) {
    if(!p_raiz||!(*p_raiz))
    	return;
    while((*p_raiz)->esq)
    	rotaciona_direita(p_raiz);
    return em_lista(&(*p_raiz)->dir);
}
void comprime(ab_int **p_raiz, int rotacoes) {
    if(!p_raiz||!(*p_raiz))
    	return;
    if(!rotacoes)
    	return;
   
    rotaciona_esquerda(p_raiz);
    comprime(&(*p_raiz)->dir, rotacoes-1);

}
void num_elementos(ab_int **p_raiz, int* n){
	if(!p_raiz||!(*p_raiz))
    	return;
    (*n)++;
    num_elementos(&(*p_raiz)->esq, n);
    num_elementos(&(*p_raiz)->dir, n);

    
}
void dsw(ab_int **p_raiz) {
	int n=0;
	num_elementos(p_raiz,&n);
	n=(n-1)/2;
    em_lista(p_raiz);
	while(n){
    comprime(p_raiz,n);
    n/=2;
	}	
}	
int main(){
	ab_int* raiz=NULL;
	int n, i, j=0; 
	scanf("%d", &n);
	while(n){
		scanf("%d", &i);
		insere(&raiz, elemento(i));
		n--;
	}
	num_elementos(&raiz,&j);
	mostra_arvore(raiz);
	dsw(&raiz);
	putchar('\n');
	mostra_arvore(raiz);




	return 0;
}