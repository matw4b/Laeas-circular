/*Header com as estruturas e as funcoes
* Para compilar digite:
* gcc -c lista.c
* gcc -o main main.c lista.o
*/
#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct{
	int fim;
	int elem[MAX];
}LAEAS;

LAEAS* inicializarLaeas (LAEAS* p);
int laeasVazia(LAEAS* p);
int laeasCheia(LAEAS* p);
int inserirFinal(LAEAS* p, int novoE);
int removerInicio(LAEAS* p);
void buscarElemento(LAEAS* p, int desejado);
void imprimirLaeas(LAEAS* p);

#endif