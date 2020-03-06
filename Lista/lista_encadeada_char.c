/**      @file: lista_encadeada_char.c
 *     @author: Guilherme N. Ramos (gnramos@unb.br)
 * @disciplina: Estruturas de Dados
 *
 * Implementação das funções para lidar com lista duplamente encadeada contendo
 * um caractere. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista_encadeada_char.h"

elemento_t* elemento(const info_t* info, elemento_t* ant, elemento_t* prox) {
    elemento_t* e= NULL;
    e=malloc(sizeof(elemento_t));
    if(!e)
        return e;
    e->info=*info;
    e->prox=prox;
    e->ant=ant;

    return e;
}

void libera(elemento_t** ptr) {
    if(ptr && (*ptr)){
        free(*ptr);
        (*ptr)=NULL;
    }
}

int infocmp(const info_t* e1, const info_t* e2) {
    if (e1 == e2) return 0;
    if (!e1) return -1;
    if (!e2) return 1;
    return (*e1) - (*e2);
}

int elementocmp(const elemento_t* e1, const elemento_t* e2) {
    if (e1 == e2) return 0;
    if (!e1) return -1;
    if (!e2) return 1;
    return infocmp(&(e1->info), &(e2->info));

}
_Bool insere(elemento_t* e, unsigned int pos, lista_t** ptr_lista) {
    elemento_t* ptr=NULL;
    elemento_t* anterior=NULL;
    int i=0;
    if((!e)||(!ptr_lista))   
        return false;
    ptr=(*ptr_lista);
    while(ptr!=NULL&&i<pos){
        anterior=ptr;
        ptr=ptr->prox;
            i++;
    }
    if(anterior==NULL&&pos==0){
        e->prox=(*ptr_lista);
        e->ant=NULL;
        if(*ptr_lista!=NULL)
            (*ptr_lista)->ant=e;
        (*ptr_lista)=e;

        return true;
    }
    else if(i==pos){
    anterior->prox=e;
    e->ant=anterior;
    e->prox=ptr;
    if(ptr!=NULL)
        ptr->ant=e;
    return true;
    }
   
   return false;
}

_Bool insere_em_ordem(elemento_t* e, lista_t** ptr_lista){
    elemento_t* anterior=NULL;
    elemento_t* ptr=(*ptr_lista);
    if((!e)||(!ptr_lista))  
        return false;
    while(ptr!=NULL&&((ptr->info)<(e->info))){
        anterior=ptr;
        ptr=ptr->prox;
    }
    if(anterior==NULL){
        e->prox=(*ptr_lista);
        e->ant=NULL;
        if(*ptr_lista!=NULL)
            (*ptr_lista)->ant=e;
        *ptr_lista=e;
        return true;
    }
    else{
        e->prox=ptr;
        e->ant=anterior;
        anterior->prox=e;
        if(ptr)
            ptr->ant=e;
        return true;
    }
}

elemento_t* retira(unsigned int pos, lista_t** ptr_lista) {
    elemento_t* ptr=(*ptr_lista);
    if(ptr!=NULL&&ptr_lista!=NULL){
        if(pos==0){
            if(ptr->prox!=NULL&&ptr->ant!=NULL){
                ptr->ant->prox=ptr->prox;
                ptr->prox->ant=ptr->ant;
            }
            if(ptr->ant==NULL&&ptr->prox!=NULL){
                ptr->prox->ant=NULL;
            }
            if(ptr->ant!=NULL&&ptr->prox==NULL){
                ptr->ant->prox=NULL;
            }
            if(ptr->ant==NULL&&ptr->prox==NULL)
                (*ptr_lista)=NULL;
            ptr->prox=NULL;
            ptr->ant=NULL;
        

            return ptr;
        }   
        return retira(pos-1,&(ptr->prox));

    }
    return NULL;
}

elemento_t* retira_em_ordem(info_t* info, lista_t** ptr_lista) {
   elemento_t* ptr=(*ptr_lista);
   if(ptr!=NULL&&ptr_lista!=NULL){
        if(ptr->info==*info){
            if(ptr->prox!=NULL&&ptr->ant!=NULL){
                ptr->ant->prox=ptr->prox;
                ptr->prox->ant=ptr->ant;
            }
            if(ptr->ant!=NULL&&ptr->prox==NULL)
                ptr->ant->prox=NULL;
            if(ptr->ant==NULL&&ptr->prox!=NULL)
                ptr->prox->ant=NULL;
            if(ptr->prox==NULL&&ptr->ant==NULL)
                (*ptr_lista)=NULL;  
            
            ptr->prox=NULL;         
            ptr->ant=NULL;
            return ptr;
        }
        return retira_em_ordem(info,&(ptr->prox));
   }
   return NULL;
}
void esvazia(lista_t** ptr_lista) {
    elemento_t* ptr=*ptr_lista;
    elemento_t* aux=NULL;
    if(ptr!=NULL){
        esvazia(&(ptr->prox));
        aux=retira(0,ptr_lista);
        libera(&aux);
    }
}

elemento_t* busca(const info_t *info, lista_t* lista) {
    if(info&&lista){    
        if(*info==lista->info)
            return lista ;
        return busca(info,lista->prox);
    }
    return NULL;
}

unsigned int tamanho(const lista_t* lista) {
    if(!lista)
        return 0;
    return 1+tamanho(lista->prox);
    
}
    
_Bool vazia(const lista_t *lista) {
    return(lista==NULL? true : false);
}

void print_i(const info_t* info) {
    if(info)
        printf("%c", *info);
}

void print_e(const elemento_t* e) {
    if(e) {
        printf("\tinfo: ");
        print_i(&(e->info));
        printf("\n\tprox: %p\n", e->prox);
        printf("\n\t ant: %p\n", e->ant);
    }
}

void print_l(const lista_t* lista) {
    int i = 0;
    while(lista) {
        printf("\n%d-esimo elemento:\n", i);
        print_e(lista);
        lista = lista->prox;
        ++i;
    }
}