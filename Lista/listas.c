#include <stdio.h>
#include <stdlib.h>
#include <string.h>


 typedef struct nolista
 {
 	int info;
 	struct nolista* prox;
 }Nolista;

 typedef struct
 {
 	Nolista* prim;
 }Lista;

 Lista* cria_lista(){
 	Lista* l= NULL;
 	l=malloc(sizeof(Lista));
 	if(l)
 		l->prim=NULL; 

 	return l;
 }
 void add_inicio(Lista* l, int v){
 	Nolista* n=NULL;
 	n=malloc(sizeof(Nolista));
 	if(!n)
 		return;
 	n->info=v;
 	n->prox=(l)->prim;
 	(l)->prim=n;	
 }
 void mostra_lista(Lista* l){
 	Nolista* ptr= NULL;
 	for( ptr=(l)->prim;ptr!=NULL;ptr=ptr->prox)
 		printf("%d\n",ptr->info);
 }
 int esta_na_lista(Lista* l, int v){
 	Nolista* ptr=NULL;
 	for( ptr=(l)->prim;ptr!=NULL;ptr=ptr->prox){
 		if(ptr->info==v){
 			return 1;
 		}
 	}
 	return 0;
 }
 void add_crescente(Lista* l, int v){
 	Nolista* ptr=l->prim;
 	Nolista* anterior= NULL;
 	Nolista* novo= NULL;
 	while(ptr!=NULL&&ptr->info<v){
 		anterior=ptr;
 		ptr=ptr->prox;
 	}
 	novo=malloc(sizeof(Nolista));
 	if(!novo)
 		return;
 	novo->info=v;
 	if(anterior==NULL){
 		novo->prox=l->prim;
 		l->prim=novo;
 		return;
 	}
 	novo->prox=anterior->prox;
 	anterior->prox=novo;
 }
 void retira_elemento(Lista* l, int v){
 	Nolista* ptr=l->prim;
 	Nolista* ant=NULL;
 	while(ptr!=NULL&&ptr->info!=v){
 		ant=ptr;
 		ptr=ptr->prox;
 	}
 	if(ptr==NULL)
 		return;
 	if(ant==NULL)
 		l->prim=ptr->prox;
 	else
 		ant->prox=ptr->prox;
 	free(ptr);
 	ptr=NULL;
 }
 int esta_vazia(Lista* l){
 	return(l->prim==NULL? 1 : 0);
 }
 void libera_lista(Lista* l){
 	Nolista* ptr=l->prim;
 	Nolista* aux=NULL;
 	while(ptr!=NULL){
 		aux=ptr->prox;
 		free(ptr);
 		ptr=aux->prox;
 	}
 	free(l);
 }


int main(){
	Lista* l=cria_lista();
	add_crescente(l,2);
	add_crescente(l,65);
	add_crescente(l,7);
	add_crescente(l,20);
	mostra_lista(l);

	libera_lista(l);
	



	return 0;
}