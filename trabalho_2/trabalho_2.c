#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

typedef struct aq_char{
	char dado;
	int pixels;
	struct aq_char* filhos[4];
	
}aq_char;

aq_char* cria_elemento(char c){
	int i;
	aq_char* e=NULL;
	e=malloc(sizeof(aq_char));
	if(!e)
		return NULL;
	e->dado=c;
	e->pixels=1024;
	for(i=0;i<4;i++)
		e->filhos[i]=NULL;	
	return e;	
}
_Bool soh_tem_folhas(aq_char* raiz){
	int i;
	for(i=0;i<4;i++){
		if(!raiz||(!raiz->filhos[i]))
			return false;
		if(raiz->filhos[i]->dado=='p'&&!soh_tem_folhas(raiz->filhos[i]))
			return false;
	}
	return true;
}
_Bool possivel_inserir(aq_char* raiz){
	if(!raiz)
		return true;
	if(raiz->dado=='p')
		return true;
	return false;
}
void insere(aq_char** raiz, aq_char* e){
	int i;
	if(!raiz)
		return;
	if(!(*raiz)){
		*raiz=e;
		return;
	}
	if((*raiz)->dado=='p')
		for(i=0;i<4;i++)
			if((!soh_tem_folhas((*raiz)->filhos[i]))&&possivel_inserir((*raiz)->filhos[i])){
				(e->pixels)/=4;
				insere(&((*raiz)->filhos[i]), e);
				break;
			}
}
void mostra_arvore(aq_char* raiz){
	int i;
	putchar('(');
	if(!raiz){
		putchar(')');
		return;
	}
	printf("%c", raiz->dado);
	for(i=0;i<4;i++){
		mostra_arvore(raiz->filhos[i]);	
		putchar(' ');
	}
	putchar(')');

}
aq_char* recebe(){
	char c;
	int i=0;
	aq_char* raiz=NULL;
	while(scanf("%c",&c)){
		i++;
		if(c=='\n')
			break;
		insere(&raiz,cria_elemento(c));
	}
	return raiz;
}
_Bool eh_preto(aq_char* raiz){
	return(raiz->dado=='f');
}
_Bool eh_pai(aq_char* raiz){
	return(raiz->dado=='p');
}
void cria_nova(aq_char* raiz1, aq_char* raiz2, aq_char** nova_raiz){
	int i;
	if(raiz1&&raiz2){
		if(raiz1->dado==raiz2->dado){
			insere(nova_raiz, cria_elemento(raiz1->dado));
		}
		else{
			if(eh_preto(raiz1)||eh_preto(raiz2)){
				insere(nova_raiz, cria_elemento('f'));
			}
			else
				if(eh_pai(raiz1)||eh_pai(raiz2))
					insere(nova_raiz, cria_elemento('p'));
		
		}
		if((eh_pai(raiz1)&&!eh_preto(raiz2))||(eh_pai(raiz2)&&!eh_preto(raiz1)))	
			for(i=0;i<4;i++)
				cria_nova(raiz1->filhos[i],raiz2->filhos[i],nova_raiz);

	}
	if(raiz1&&!raiz2){
		insere(nova_raiz, cria_elemento(raiz1->dado));
		if(eh_pai(raiz1))	
			for(i=0;i<4;i++)
				cria_nova(raiz1->filhos[i],raiz2,nova_raiz);
	}
	if(raiz2&&!raiz1){
		insere(nova_raiz, cria_elemento(raiz2->dado));
		if(eh_pai(raiz2))	
			for(i=0;i<4;i++)
				cria_nova(raiz1,raiz2->filhos[i],nova_raiz);
	}
	if(!raiz1&&!raiz2)
		return;

}
void percorre(aq_char* raiz, int* pp){
	int i;
	if(!raiz)
		return;
	if(raiz->dado=='f')
		(*pp)+=raiz->pixels;
	for(i=0;i<4;i++)
		percorre(raiz->filhos[i], pp);
}
int main(){
	int num;
	aq_char* raiz1=recebe();
	aq_char* raiz2=recebe();
	aq_char* nova_raiz=NULL;

	
	
	
	
	cria_nova(raiz1, raiz2,&nova_raiz);
	percorre(nova_raiz, &num);
	printf("%d\n",num);


	return 0;
}