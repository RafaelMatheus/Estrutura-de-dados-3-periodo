/*
 * Pilha.c
 *
 *  Created on: 09/04/2017
 *      Author: Rafael Matheus
 *      Matricula: 1610014657
 *      Disciplica: Estrutura de dados
 *      Professor: Wallace Bonfim
 *
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX 3

// Tipo base dos elementos da lista
typedef struct elementos {
    char placa[50];
} t_elemento;

// Estrutura da pilha
typedef struct pilha {
    t_elemento vetor[MAX];
    int topo;


} t_pilha;


/**
 * Verifica se a lista está cheia ou vazia
 */


int isCheia(t_pilha * pilha) {
    return (pilha->topo == MAX-1);
}


/**
 * Coloca a placa do carro na posição i+ (-1) onde
 *
 */

int push(t_pilha *pilha, t_elemento valor)
{

    if (isCheia(pilha))
        return 0; // erro

    pilha->vetor[++pilha->topo] = valor;
    return 1; // sucesso
}





int entraCarros(t_pilha *pilha){

	t_elemento plc;
	int i;
	//Pegar placa e guardar na pilha
	for(i = 0; i<MAX; i++){
		//pega placa e guarda na pilh
		printf("Informe a placa do carro %d:  ", (i+1));
		scanf("%s", &plc.placa);
		push(pilha, plc);

	}
}




t_elemento pop(t_pilha *pilha){
	return pilha->vetor[pilha->topo--];


}

/**
 * Pega os elementos do topo da pilha e retorna um t_elemento
 */
t_elemento getElementoTopo(t_pilha * pilha)
{

        return pilha->vetor[pilha->topo--];
}

/**
 * Função responsavel por retirar os carros
 * e imprimir as placas
 */

void tiraCarros(t_pilha *pilha, int qntCarrosRetirados){

    int i;
    int j = 1;//Guarda a posição de saida dos carros

    t_elemento saidaCarros;
    for(i = pilha->topo; i > -1; i--){// -1 é o inicio da pilha

    	printf("A placa do %dª carro a sair e %s\n", j, pilha->vetor[pilha->topo]);
    	pop(pilha);
    	j++;
    }

}





int main(int argc, char *argv[]) {
int i;
t_pilha pilha;
pilha.topo = -1;

entraCarros(&pilha);
// Mostrar placa do primeiro carro a sair (ultimo carro a entrar na pillha)
printf("A placa do ultimo carro a entrar e: %s\n\n", pilha.vetor[pilha.topo].placa);

//Remove os carros mostrando a placa de todos na ordem que saem
tiraCarros(&pilha, MAX);


//Mostra quantos carros sobraram
printf("\nRestaram %d carros", (pilha.topo) +1 );
return 0;
}

