#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

typedef struct element_p{
	char info [101];
	struct element_p* prox;

}element_p;

element_p* cria_elemento(char* string){
	element_p* e=NULL;
	e=malloc(sizeof(element_p));
	if(!e)
		return e;
	e->prox=NULL;
	strcpy(e->info, string);

	return e;

}
_Bool isEmpty(element_p* pilha){
	return(!pilha);
}
void push(element_p** pilha, element_p* e){
	if(!pilha||!e)
		return;
	if(isEmpty(*pilha)){
		(*pilha)=e;
		return;
	}
	if(!(*pilha)->prox){
		e->prox=(*pilha)->prox;
		(*pilha)->prox=e;
		return;
	}
	push(&((*pilha)->prox), e);

}
void pop(element_p** pilha){
	element_p* t=NULL;
	if(!*pilha)
		return;
	if(!(*pilha)->prox){
		t=(*pilha);
		*pilha=(*pilha)->prox;
		printf("%s\n",t->info);
		free(t);
		return;
	}

	if(!(*pilha)->prox->prox){
		t=(*pilha)->prox;
		(*pilha)->prox=(*pilha)->prox->prox;
		printf("%s\n",t->info);
		free(t);
		return;
	}
	pop(&(*pilha)->prox);

}

int main(){
	element_p* pilha_num;
	element_p* pilha_str;
	char str [101];

	while(scanf("%s", str)){
		if(!strcmp(str,"end"))
			break;
		if(isdigit(str[0]))
			push(&pilha_num, cria_elemento(str));
		
		else
			push(&pilha_str, cria_elemento(str));
	}
	printf("Palavras:\n");
	while(!isEmpty(pilha_str))
		pop(&pilha_str);
	printf("Numeros:\n");
	while(!isEmpty(pilha_num))
		pop(&pilha_num);



	return 0;
}