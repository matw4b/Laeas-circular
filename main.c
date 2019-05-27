#include "lista.h"

/*Testa todas as funcoes implementadas*/
int main(){
	
	LAEAS lista; /*Cria uma lista LAEAS*/
	/*OBS: Como a LAEAS eh estatica, ela nao pode ser criada atraves de uma outra funcao,
	*pois assim que a funcao acaba, a lista some junto com a funcao.*/
	
	LAEAS* p; /* Ponteiro que aponta para a lista. Ele eh passado como argumento nas funcoes.*/
	p = &lista;
	
	int op, posicao, aux;/*'op' eh a operacao escolhida no menu; 'posicao' eh o indice da lista, 'aux' eh uma variavel para a leitura de elementos*/
	
	inicializarLaeas(p); /*Limpa o lixo de memoria, configura o indice 'fim' da lista e deixa a lista vazia (zerada).*/
	
	do{
		printf("(1) Inserir elemento\n");
		printf("(2) Remover elemento\n");
		printf("(3) Buscar um elemento\n");
		printf("(4) Imprimir a lista\n");
		printf("(0) Encerrar programa\n");
		scanf(" %d", &op);
		
		if(op == 1){
			printf("Digite um numero: ");
			scanf(" %d", &aux);
			if(inserirFinal(p, aux))
				printf("Elemento inserido com sucesso\n");
			else
				printf("O elemento nao pode ser inserido\n");
		}
		
		if(op == 2){
			if(removerInicio(p))
				printf("Elemento removido\n");
			else
				printf("Nao houve remocao\n");
		}
		
		if(op == 3){
			printf("Digite um numero: ");
			scanf(" %d", &aux);
			buscarElemento(p, aux);
		}
		if(op == 4)
			imprimirLaeas(p);
		
		
	}while(op != 0);
	
	return 0;
}