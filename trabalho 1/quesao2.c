/** Matricula:180113330
 *       Nome: Gabriel da Silva Corvino Nogueira
 *      Turma: E */

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct {
	char elementos[201];
	int tam;
}pilha_t; 

void create(pilha_t* p){
	p->tam=0;
}
_Bool isEmpty(pilha_t* p){
	return p->tam==0;
}
char top(pilha_t* p){
	return 	p->elementos[(p->tam)-1];

}
void empty(pilha_t* p){
	p->tam=0;
}
void push(pilha_t* pilha ,char elemento){
	if(pilha->tam==101)
		return;
	pilha->elementos[pilha->tam]=elemento;
	(pilha->tam)++;

}
char pop(pilha_t* pilha){
	char aux;
	(pilha->tam)--;
	aux=pilha->elementos[pilha->tam];
	return aux;
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
 _Bool numero(char c){
 	if((c>='0'&& c<='9')||c=='.')
 		return true;
 	return false;
 }
 _Bool esta_no_final(const char* string, int i){
 	return(string[i+1]=='\0');
 }
int precedencia(char c){
	int p;
	p=0;
	if(c=='+'||c=='-')
		p=1;
	if(c=='*'||c=='/')
		p=2;
	if(c=='^')
		p=3;
	return p; 	
}
_Bool eh_parentese_fechando(char c){
	return(c==')');
}
_Bool eh_parentese_abrindo(char c){
	return(c=='(');
}
void organiza(const char* infixa,  char* posfixa){
	int i, j ;
	pilha_t operadores;
	create(&operadores);
	for(i=0, j=0;infixa[i]!='\0';i++){
		if(numero(infixa[i])){
			if(j>0&&operador(posfixa[j-1])){
				posfixa[j]=' ';
				j++;
			}
			posfixa[j]=infixa[i];
			j++;
		}
		if(operador(infixa[i])||esta_no_final(infixa, i)||eh_parentese_fechando(infixa[i])|| eh_parentese_abrindo(infixa[i])){
			if(((!isEmpty(&operadores))&&(precedencia(infixa[i])<=precedencia(top(&operadores))))||esta_no_final(infixa, i)||eh_parentese_fechando(infixa[i]))
			{	
				if(!eh_parentese_abrindo(infixa[i])&&(!(top(&operadores)=='^'&&infixa[i]=='^'))){
					while(!isEmpty(&operadores)&&(precedencia(top(&operadores))>=precedencia(infixa[i]))){	
						if(eh_parentese_abrindo(top(&operadores))){
							pop(&operadores);
							break;
						}
						posfixa[j]=' ';
						posfixa[j+1]=pop(&operadores);
						j+=2;
					}
				}
				if(operador(infixa[i])||eh_parentese_abrindo(infixa[i])){
					push(&operadores, infixa[i]);
					if(top(&operadores)=='^'&&infixa[i]=='^'){
						posfixa[j]=' ';
						j++;
					}
				}	
			}
			else{
				push(&operadores, infixa[i]);
				if(!eh_parentese_abrindo(infixa[i])){
					posfixa[j]=' ';
					j++;
				}
			}

		}
	}
	posfixa[j]='\0';

	}	
void transforma(const char* infixa, char* posfixa) {
    organiza(infixa, posfixa);		
}

int main() {
    char infixa[101], posfixa[201];

    scanf("%100[^\n]", infixa);

    transforma(infixa, posfixa);
    printf("%s\n", posfixa);

    return 0;
}