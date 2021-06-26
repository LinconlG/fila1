#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct no{
	int dado;
	struct no *prox;
};
//--------------
typedef struct no *pont;
pont navegador;
pont inicio;

int op;
//-------------
void mostrar(pont arg);
void inserir(pont arg);
void remover(pont arg);
void menu();
//programa
int main(){
	
	srand(time(NULL));
	
	navegador = (pont) malloc(sizeof(struct no));
	navegador->dado = 0;
	navegador->prox = NULL;
	inicio = navegador;
	
	while(op != 3){
		
		mostrar(inicio);
		menu();
		
		switch(op){
			case 1: inserir(inicio);
				break;
			case 2: remover(inicio);
				break;
			case 3:	
				break;
			default: printf("\n Resposta invalida, por favor insira uma resposta valida...\n\n");
					system("pause");
				break;	
		}		
	}
	
	return 0;
}
//Funções****************
void menu(){
	
	printf("\n****************************************\n \n 1-Inserir dado na lista    2-Remover dado da lista\n         3-Sair \n\n Resposta: ");
	scanf("%d", &op);
	fflush(stdin);
	printf("\n\n");
}
//------------------------
void inserir(pont arg){
	
	while(arg->prox != NULL){
		
		arg = arg->prox;
	}
	
	arg->prox = (pont) malloc(sizeof(struct no));
	arg = arg->prox;
	arg->dado = rand()%100;
	arg->prox = NULL;
	
	system("cls");
}

//------------------------
void mostrar(pont arg){
	
	while(arg->prox != NULL){
		
		printf(" %d;", arg->dado);
		
		arg = arg->prox;
	}
	
	printf(" %d;", arg->dado);
	printf("\n");
}
//------------------------
void remover(pont arg){
	
	pont antecessor;
	antecessor = (pont) malloc(sizeof(struct no));
	antecessor->dado = 0;
	antecessor->prox = NULL;
	
	
	antecessor = arg;
	inicio = arg->prox;
	
	free(antecessor);
	
	system("cls");
}

