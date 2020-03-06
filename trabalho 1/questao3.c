/** Matricula:180113330
 *       Nome: Gabriel da Silva Corvino Nogueira
 *      Turma: B */

#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct 
{
	double elementos[202];
	int tam;
	
}pilha_t;
void create(pilha_t* p){
	p->tam=0;
}
_Bool isEmpty(pilha_t* p){
	return p->tam==0;
}
double top(pilha_t* p){
	return 	p->elementos[(p->tam)-1];

}
void empty(pilha_t* p){
	p->tam=0;
}
void push(pilha_t* pilha ,double elemento){
	if(pilha->tam==101)
		return;
	pilha->elementos[pilha->tam]=elemento;
	(pilha->tam)++;

}
double pop(pilha_t* pilha){
	double aux;
	(pilha->tam)--;
	aux=pilha->elementos[pilha->tam];
	return aux;
}
_Bool numero(char c){
 	if((c>='0'&& c<='9')||c=='.')
 		return true;
 	return false;
 }
 _Bool operador(char c){
 	switch(c){
 		case '+':
 			return true;
 		case '-':
 			return true;
 		case '*':
 			return true;
 		case '/':
 			return true;
 		case '^':
 			return true;
 		default:
 			return false;

 	}
 }
double opera(char operador, double a, double b){
	if(operador=='+')
		return a+b;
	if(operador=='-')
		return a-b;
	if(operador=='*')
		return a*b;
	if(operador=='/')
		return a/b;
	if(operador=='^')
		return pow(a,b);
	return 0;
}
double calcula(const char* posfixa) {
int i, j=0;
pilha_t numeros;
double resultado;
char string[201];
	for (i = 0; posfixa[i]!='\0'; ++i)
	{
		if(numero(posfixa[i])){
			string[j]=posfixa[i];
			j++;
		}
		if(posfixa[i]==' '||posfixa[i]=='\0'){
			string[j]='\0';
			j=0;
			if(string[0]!='\0')
				push(&numeros,atof(string));
		}
		if(operador(posfixa[i])){
			resultado=opera(posfixa[i],pop(&numeros), pop(&numeros));
			push(&numeros, resultado);
		}	
	}
	
	return top(&numeros);
}

int main() {
    char posfixa[201];

    scanf("%200[^\n]", posfixa);
    printf("%.5lf\n", calcula(posfixa));

    return 0;
}
