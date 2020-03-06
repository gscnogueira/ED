#include <stdbool.h>
#include <string.h>
#include <stdio.h>
 

typedef struct{

	char elementos[101];
	int tam;

}pilha_t;

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
 _Bool ver_limitadores(const char* expressao){
 	int i;
 	char aux;
 	pilha_t limitadores;
 	(limitadores.tam)=0;
 	for (i = 0; expressao[i]!='\0'; ++i)
 	{
 		if(expressao[i]=='('||expressao[i]=='['||expressao[i]== '{'){
 			push(&limitadores, expressao[i]);
 		}
 		if(expressao[i]==')'||expressao[i]==']'||expressao[i]== '}'){
 			if ((limitadores.elementos[0]==')')||
 				(limitadores.elementos[0]==']')||
 				(limitadores.elementos[0]=='}'))
 				return false;

 			aux=pop(&limitadores);

	 		if((expressao[i]==')'&& aux!='(')||
	 		   (expressao[i]==']'&& aux!='[')||
	 		   (expressao[i]=='}'&& aux!='{')){
	 		   	
	 		   	return false;
	 		}
	 	}
 	}
 	if(limitadores.tam==0)
	 	return true;
	 return false;
 }
 _Bool numero(char c){
 	if(c>='0'&& c<='9')
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
 _Bool ehlimitador(char c){
 	switch(c){
 		case '(':
 			return true;
 		case ')':
 			return true;
 		case '[':
 			return true;
 		case ']':
 			return true;
 		case '{':
 			return true;
 		case '}':
 			return true;
 		default:
 			return false;

 	}
 }
 _Bool limitador_fechando(char c){
 	switch(c){
 		case ')':
 			return true;
 		case ']':
 			return true;
 		case '}':
 			return true;
 		default:
 			return false;
 	}

 }
 _Bool limitador_abrindo(char c){
 	switch(c){
 		case '(':
 			return true;
 		case '[':
 			return true;
 		case '{':
 			return true;
 		default:
 			return false;
 	}

 }
 _Bool ver_esquerda(const char* expressao, int pos){
 	int i;
 	for (i = pos; expressao[i-1]==' ' ; --i);
 	if(numero(expressao[i-1]))
 		return true;
 	if(limitador_abrindo(expressao[i-1]))
 		return false;
 	if(numero(expressao[i-1])||ehlimitador(expressao[i-1]))
 		return true;
 	return false;

 }
 _Bool ver_direita(const char* expressao, int pos){
 	int i;
 	for (i = pos; expressao[i+1]==' ' ; ++i);
 	if(limitador_fechando(expressao[i+1]))
 		return false;
 	if(numero(expressao[i+1]))
 		return true;
 	if(numero(expressao[i+1])||ehlimitador(expressao[i+1]))
 		return true;
 	return false;

 }
 _Bool ver_operador(const char* expressao){
 	int i;
 	for(i=0;expressao[i]!='\0';++i){
 		if(operador(expressao[i])){
 			if(i==0||i==strlen(expressao))
 				return false;
 			if((!ver_esquerda(expressao,i))||(!ver_direita(expressao,i)))
 				return false;
 		}
 	}

 			return true;

 }
 _Bool ver_espacos(const char* expressao){
 	int i;
 	for (i = 0; expressao[i]!='\0'; ++i)
 	{
 		if(i!=0&&i!=(strlen(expressao))-1){
 			if(expressao[i]==' '){
 				if(numero(expressao[i-1])&&numero(expressao[i+1]))
 					return false;
 				if(ehlimitador(expressao[i-1])&&ehlimitador(expressao[i+1]))
 					return false;
 				if(ehlimitador(expressao[i-1])&&numero(expressao[i+1]))
 					return false;
 				if(numero(expressao[i-1])&&ehlimitador(expressao[i+1]))
 					return false;
 			}
 		}
 	}
 	return true;
 }
 _Bool ver_cont_limitador(const char* expressao){
 	int i;
 	for (i = 0; expressao[i]!='\0'; ++i)
 	{
 		if(limitador_abrindo(expressao[i])&&limitador_fechando(expressao[i+1]))
 			return false;
 		if(ehlimitador(expressao[i]))
 			if(i!=0&&i!=(strlen(expressao)-1))
 				if(numero(expressao[i-1])&&numero(expressao[i+1]))
 					return false;
 			
 	}
 	return true;
 }
 _Bool valida(const char* expressao){
 	if(!ver_limitadores(expressao))
 		return false;
 	if(!ver_espacos(expressao))
 		return false;
 	if(!ver_operador(expressao))
 		return false;
 	if(!ver_cont_limitador(expressao))
 		return false;
 	return true;

 }

int main() {
    char expressao[101];
    
    scanf("%100[^\n]", expressao);
    
    if (valida(expressao))
        printf("VALIDA\n");
    else
        printf("INVALIDA\n");
        
    return 0;
}