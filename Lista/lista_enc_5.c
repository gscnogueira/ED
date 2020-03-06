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
		int pos;
		int id;
		struct lista_no* prox;
		struct lista_no* ant;
	}lista_no;

	lista_no* cria_elemento(int pos, int i){
		lista_no* e=NULL;
		e=malloc(sizeof(lista_no));
		if(!e)
			return e;
		e->pos=pos;
		e->id=i;
		e->prox=NULL;
		e->ant=NULL;
		return e;
	}
	_Bool isEmpty(lista_no* lista){
		return (!lista);
	}
	void add_final(lista_no** lista, lista_no* e){
		if(!lista||!e)
			return;
		if(isEmpty(*lista)){
			(*lista)=e;
			return;
		}
		if(!(*lista)->prox){
			(*lista)->prox=e;
			e->ant=*lista;
			return;
		}
		add_final(&((*lista)->prox), e);
	}
	void printl(lista_no* lista){
		if(lista==NULL)
			return;			
		printf("%d - %d\n",lista->pos, lista->id);
		printl(lista->prox);
	}
	_Bool esta_no_final(lista_no* e){
		return(e->prox==NULL);
	}
	_Bool esta_no_comeco(lista_no* e){
		return(e->ant==NULL);
	}
	void retira(lista_no** lista){
		lista_no* t;
			
		if(!(*lista)||!lista)
			return;
		if((*lista)->id>=60){
			t=*lista;
			if(!esta_no_comeco(*lista)){
				(*lista)->ant->prox=(*lista)->prox;
			}
			if(!esta_no_final(*lista)){
				(*lista)->prox->ant=(*lista)->ant;
			}
		
			*lista=(t)->prox;
			free(t);
			if(!(*lista))
				return;
			return retira(lista);
			
		}

		return retira(&((*lista)->prox));

		

	}
	int pos_na_lista(lista_no** lista, lista_no* e){
		if(!lista||!e||!(*lista))
			return 0;
		if((*lista)==e)
			return 1;
		return pos_na_lista(&((*lista)->prox),e)+1;
	}
	void print_esperado(lista_no* lista, lista_no** lista_ref){
		if(lista==NULL)
			return;
		printf("%d - %d\n",pos_na_lista(lista_ref, lista), lista->pos);
		print_esperado(lista->prox,lista_ref);
	}
		

	 int main(){
		int i ,posn=1;
		lista_no* original=NULL;
		lista_no* pref=NULL;
		while(scanf("%d", &i)!=EOF){
			add_final(&original, cria_elemento(posn, i));
			if(i>=60)
				add_final(&pref, cria_elemento(posn, i));
			posn++;
		}
		printf("Fila geral original\n");
		printl(original);
		printf("\nFila preferencial\n");
		printl(pref);
		retira(&original);
		printf("\nFila geral atualizada\n");
		printl(original);
		printf("\nResultado esperado fila preferencial\n");
		print_esperado(pref,&pref);
		printf("\nResultado esperado fila geral\n");
		print_esperado(original, &original);


		


	 return 0;
	 }
