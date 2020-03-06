#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

typedef struct ab_char
{
		char dado;
		struct ab_char* esq;
		struct ab_char* dir;

}ab_char;
void mostra_arvore(ab_char* raiz) {
    putchar('(');
    if(!raiz){
    	putchar(')');
   		return;	
    }
    printf("%c ",raiz->dado);

    mostra_arvore(raiz->esq);
    putchar(' ');
    mostra_arvore(raiz->dir);
	putchar(')');
}
int altura(ab_char *raiz) {
	int ad,ae;
   if(!raiz)
   		return 0;
   	ae=altura(raiz->esq);
   	ad=altura(raiz->dir);
   	if(ae>ad)
   		return ae+1;
   	else
   		return ad+1;
}

void insere(ab_char** p_raiz, ab_char* e) {
    if(!p_raiz)
    	return;
    if(!(*p_raiz)){
    	*p_raiz=e;
    	return;
    }
    if(altura((*p_raiz)->dir)<altura((*p_raiz)->esq))
    	insere(&((*p_raiz)->dir), e);
    else
    	insere(&((*p_raiz)->esq), e);

}
void rotaciona_esquerda(ab_char **p_raiz) {
	if(!p_raiz||!(*p_raiz))
		return;
	if(!(*p_raiz)->dir)
		return;
    ab_char* aux=(*p_raiz);
   	(*p_raiz)=(*p_raiz)->dir;
   	aux->dir=(*p_raiz)->esq;
   	(*p_raiz)->esq=aux;


}
ab_char* elemento(char c){
	ab_char* e=NULL;
	e=malloc(sizeof(ab_char));
	if(!e)
		return e;
	e->dado=c;
	e->esq=NULL;
	e->dir=NULL;
	return e;
}
int main(){
	ab_char* raiz=elemento('a');
	raiz->esq=elemento('b');
	raiz->dir=elemento('c');
	rotaciona_esquerda(&(raiz));
	mostra_arvore(raiz);

	return 0;
}