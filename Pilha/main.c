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




int isCheia(t_pilha * pilha) {
    return (pilha->topo == MAX-1);
}



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
	t_elemento vazio = {""};

	return pilha->vetor[pilha->topo--];

}

void tiraCarros(t_pilha *pilha, int qntCarrosRetirados){
    int i;
    for(i = 0 ; i<qntCarrosRetirados; i++){
    pop(pilha);

    }
}


int main(int argc, char *argv[]) {
t_pilha pilha;
pilha.topo = -1;
entraCarros(&pilha);
// Mostrar placa
printf("A placa do ultimo carro e: %s", pilha.vetor[pilha.topo].placa);

//
tiraCarros(&pilha, MAX);

//Mostra quantos carros sobraram
printf("\nRestaram %d carros", (pilha.topo) +1 );
return 0;
}
