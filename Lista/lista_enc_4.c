/**
 * Author: Gabriel da Silva Corvino Nogueira
 * E-mail: gab.nog94@gmail.com * E-mail: gab.nog94@gmail.com
 */ 
 #include <stdio.h>
 #include <stdlib.h>
 #include <stdbool.h>
 #include <string.h>
 #include <ctype.h>

typedef struct lista_no{
	int chave;
	int tempo;
	struct lista_no* prox;
	struct lista_no* back;
}lista_no;

lista_no* cria_elemento(int chave, int tempo){
	lista_no* e=NULL;
	e=malloc(sizeof(lista_no));
	e->chave=chave;
	e->tempo=tempo;
	e->prox=NULL;
	e->back=NULL;

	return e;
}
int acha_posicao(lista_no** lista,lista_no* e){
	if((*lista)==e)
		return 0;
	return 1+acha_posicao(&((*lista)->prox), e);
}
void inicializa_back(lista_no** lista, lista_no* e, int j){
	if((!lista)||(!e))
		return;
	int pos= acha_posicao(lista, e);
	int i;		
	lista_no* ptr=NULL;
	if(j==0){
		e->back=NULL;
		return;
	}
	for ( i = 0, ptr=(*lista); i < (pos-j)&&ptr!=NULL; ++i, ptr=ptr->prox);
	if(ptr)
		e->back=ptr;
}
void add_elemento(lista_no** lista, lista_no* e, lista_no** lista_ref, int j){
	if((!lista)||(!e))
		return;
	if((*lista)==NULL){
		(*lista)=e;
		inicializa_back(lista_ref,e,j);
		return;
	}	
	add_elemento(&((*lista)->prox), e, lista_ref, j);
}
lista_no* encontra_elemento(lista_no** lista, int i){
	lista_no* t; 
	if((!lista)||(!(*lista)))
		return NULL;
	if((*lista)->chave==i){
		t=(*lista);
		return t;
	}
	return encontra_elemento(&((*lista)->prox), i);

}
void anula_back(lista_no** lista, lista_no* e){
	if((!lista)||(!(*lista))||(!e))
		return;
	if((*lista)->back==e){
		(*lista)->back=NULL;
	}
	anula_back(&((*lista)->prox),e);
}
void retira(lista_no** lista, lista_no* e){
	if((!lista)||(!(*lista))||(!e))
		return;
	if((*lista)==e){
		(*lista)=(*lista)->prox;
		free(e);
		return;
	}
	retira(&((*lista)->prox),e);
}
void retira_e_anula(lista_no** lista, int i){
	lista_no* e=encontra_elemento(lista,i);
	anula_back(lista,e);
	retira(lista, e);	
}
void printl(lista_no* l,lista_no* lref){
	if(!l)
		return;
	putchar('[');
	printf("%d,",l->chave);
	printf("%d",l->tempo);
	if(l->back!=NULL)
		printf(",%d",acha_posicao(&lref,l->back));
	putchar(']');
	if(l->prox!=NULL)
		putchar(' ');
	printl(l->prox, lref);

}
_Bool vazia(lista_no* l){
	return l==NULL;
}

 int main(){
 	char c;
 	int a, b, t=0;
 	lista_no* lista=NULL;


 	while(scanf("%c", &c)){
 		if(c=='f'){
 			if(vazia(lista))
 				printf("-1\n");
 			else{
 				printl(lista, lista);
 				putchar('\n');
 			}
 			break;
 		}
 		if(c=='i'){
  			scanf("%d %d", &a, &b);
 			add_elemento(&lista, cria_elemento(a, t), &lista, b);
 			t++;
 		}
 		if(c=='r'){
 			scanf("%d",&a);
 			retira_e_anula(&lista,a);
 			t++;
 		}
 	}



 return 0;
 }
 		