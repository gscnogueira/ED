#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#define TAM_MAX 1000

typedef struct element{
	 char nome[21];
	 int colisoes;
}element;
typedef struct {
    unsigned int num_elementos;
    element dados [TAM_MAX];
} tab_disp_string;

int is_in(tab_disp_string* td, char* nome){
	int i;
	for(i=0;i<td->num_elementos;i++){
		if(!strcmp(nome,td->dados[i].nome))
			return i;
	}
	return -1;
}
void insere(tab_disp_string* td, char* nome){
	int pos=is_in(td, nome);

	if(pos>=0){
		(td->dados[pos].colisoes)+=1;
	}
	else{
		strcpy(td->dados[td->num_elementos].nome, nome);
		(td->num_elementos)++;
	}
	
}
int main(){

	int n, i;
	char nome [21];
	tab_disp_string td;
	td.num_elementos=0;

	scanf("%d",&n);
	while(n){
		scanf("%s", nome);
		insere(&td,nome);
		n--;
	}
	n=(&td)->num_elementos;
	for(i=0;i<n;++i){
		printf("%s %d\n", (&td)->dados[i].nome, (&td)->dados[i].colisoes);
	}






	return 0;
}