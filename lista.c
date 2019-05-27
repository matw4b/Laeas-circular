/*Funcoes auxiliares*/
#include "lista.h"

/*Funcao que inicializa a lista. */
LAEAS* inicializarLaeas(LAEAS* p){
	int i;
	/*Fim eh o indice do ultimo elemento da lista ja preenchida. Quando ela esta vazia, nenhum elemento esta preenchido. Portando, coloquei -1.*/
	p->fim = -1;
	for(i = 0; i<MAX; i++){
		p->elem[i] = 0;
	}
	return p;
}

/*Funcao que verifica se a lista esta vazia. Se sim, retorna 1, caso contrario, retorna 0.*/
int laeasVazia(LAEAS* p){
	if(p->fim == -1)
		return 1;
	else
		return 0;
}

/*Funcao que verifica se a lista esta cheia. Se sim, retorna 1, caso contrario, retorna 0.*/
int laeasCheia(LAEAS* p){
	if(p->fim == MAX-1)
		return 1;
	else
		return 0;
}

/*Funcao que insere elementos no final da lista. Deve ser informado o endereco da lista e o elemento a ser inserido.*/
int inserirFinal(LAEAS* p, int novoE){
	if( laeasCheia(p) )/*Verifica se eh possivel fazer uma insercao.*/{
		printf("Nao eh possivel inserir um elemento numa lista cheia. \n");
		return 0;
	}
	else{
		p->elem[p->fim+1] = novoE;/*Insere um novo elemento.*/
		p->fim = p->fim + 1;/*Atualiza o indice da lista.*/
		return 1;
	}
}

/*Funcao que remove um elemento no inicio da lista. Deve ser informado o endereco da lista.*/
int removerInicio(LAEAS* p){
	if(laeasVazia(p)){/*Verifica se a lista esta vazia.*/
		printf("Nao eh possivel remover um elemento de uma lista vazia. \n");
		return 0;
	}
	else{
		int i;
		if(p->fim > 0 )/*Se a lista tiver mais de 1 elemento, faz deslocamento.*/
			for(i = 0; i < p->fim; i++){
				p->elem[i] = p->elem[i+1];
			}
		else{/*Senao, apenas remove o elemento.*/
			p->elem[0] = 0;
		}
		p->fim = p->fim - 1;/*Atualiza o fim da lista.*/
		return 1;
	}
}

/*Funcao que procura um elemento dentro da lista. Os parametros sao: endereco da lista; numero a ser procurado.*/
void buscarElemento(LAEAS* p, int desejado){
	int i, achou = 0;/*Declaracao de um indice para andar na lista e de uma flag para sinalizar se o elemento foi encontrado.*/
	if( !laeasVazia(p)){/*Verifica se a lista nao esta vazia.*/
		i = 0;
		while(!achou && (p->fim+1 != i)){/*Percorre a lista ate encontrar o elemento, ou, ate chegar ao fim da lista.*/
			if(p->elem[i] == desejado){
				printf("O elemento %d foi encontrado na posicao %d. \n", desejado, i+1); /*Apenas para nao dizer posicao 0 para o usuario.*/
				achou = 1;
			}
			i++;
		}
		if(!achou)/*Informa que o elemento nao foi encontrado na lista*/
			printf("Elemento %d nao encontrado. \n", desejado);
	}
	else/*Informa ao usuario que a lista esta vazia.*/
		printf("Lista vazia. \n");
}

/*Funcao que exibe a lista na tela. Deve ser informado o endereco da lista*/
void imprimirLaeas(LAEAS* p){
	int i;
	if(!laeasVazia(p)){/*Se a lista nao estiver vazia, ela eh exibida.*/
		for(i = 0; i<= p->fim; i++){
			printf("%d ", p->elem[i]);
		}
	}
	printf("\n");
}
