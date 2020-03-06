#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

typedef struct element_t{
	char string[256];
	struct element_t* lig;
}element_t;
typedef struct fila{
	element_t* inicio;
	element_t* fim;
}fila;

element_t* cria_elemento(char* string){
	element_t* e=NULL;
	e=malloc(sizeof(element_t));
	if(!e)
		return e;
	strcpy(e->string, string);
	e->lig=NULL;

	return e;
}
void cria_fila(fila* fila){
	fila->inicio=NULL;
	fila->fim=NULL;
}
_Bool isEmpty(fila* fila){
	return (!(fila->inicio) && !(fila->fim));
}
element_t* front(fila* fila){
	return (fila->inicio);
}
void enqueue(fila* fila, element_t* e){
	if(!e||!fila)
		return;
	if(isEmpty(fila))
		fila->inicio=e;
	else 
		fila->fim->lig=e;
	fila->fim=e;
}
void dequeue(fila* fila){
	element_t* e=NULL;
	if(!fila||isEmpty(fila))
		return;
	e=fila->inicio;
	fila->inicio=e->lig;
	if(!fila->inicio)
		fila->fim=NULL;
	free(e);
}
void mostra_elementos(element_t* atvd){
	if(!atvd)
		return;
	printf("%s\n",atvd->string);
	mostra_elementos(atvd->lig);
}

_Bool eh_palindromo(char* string, int l, int r){
	int i, j;
	for(i=l,j=r;i<r&&j>l;i++,j--){
		if(string[i]!=string[j-1])
			return false;
	}
	return true;
}
void mostra_string(char * string, int l, int r){
	int i;
	printf("Palavra: ");
	for(i=l; i<r+1; i++){
		printf("%c",string[i]);
	}
	putchar('\n');
}
_Bool contem_sub(int l1, int r1, int l2, int r2){
	return((l2<l1&&r2>=r1)||(l2<=l1&& r2>r1));
}
_Bool eh_sub(int l1, int r1, int l2, int r2){
	return((l1<l2&&r1>=r2)||(l1<=l2&& r1>r2));
}
_Bool comp(char* string, int l1, int r1, int l2 , int r2){
	int i, j;
	if(!((r1-l1)==(r2-l2)))
		return false;
	for(i=l1, j=l2;i<=r1&&j<=r2; i++, j++ )
		if(string[i]!=string[j])
			return false;
	return true;
}
_Bool eh_2_palindromo(char* string){
	int i, j,n=0, tam=strlen(string), l1=0, r1=0, l2, r2;
	for(j=0;j<tam;j++)	
		for(i=0;i<tam;i++)
			if((j-i>1)&&(j!=(tam-1)||i!=0)){
				if(eh_palindromo(string, i, j+1)){
					l2=i;
					r2=j;
					if(!comp(string,l1, r1, l2, r2)&&!eh_sub(l1, r1, l2, r2)&&!contem_sub(l1, r1, l2, r2)){
						l1=i;
						r1=j;
						n++;
						if(n==2)
							return true;
					}
				}
			}
	return (n>1);
}
int main(){
	fila pal;
	cria_fila(&pal);
	char string[256];

	while(scanf("%s", string)!=EOF){
		if(eh_2_palindromo(string)){
			enqueue(&pal,cria_elemento(string));
		}
	}
	mostra_elementos((&pal)->inicio);


	return 0;
}