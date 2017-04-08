#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

#define MAX 3 //numero de alunos na lista sequencial


/**
*
*
*
*   Autor: Rafael Matheus
*   Matricula: 1610014657
*   Professor: Wallace Bonfim
*   Disciplina: Estrutura de dados
*
*
*
*/

// Estrutura para armazenar disciplinas e notas
typedef struct disciplina{
    char disciplina[50];
    float nota;
    char matricula[50];
} t_disciplina;

// Lista encadeado com as disciplinas e ponteiro para proximo nó
typedef struct no{
    t_disciplina dado;
    struct no *prox;
} t_no;

typedef t_no *t_listaDisciplina;

typedef struct alunos{
    char matricula[50];
    t_no *disciplinas; // lista das disciplinas e notas
} t_alunos;


// Lista sequencial para armazenar os alunos
typedef struct listaAlunos{
    t_alunos vetor[MAX];//vetor que armazena elementos da lista
    int n; // posicao do ultimo elemento da lista
} t_listaAlunos; // tipo lista


t_no * criaNo();
int inserir(t_listaDisciplina *lista, int pos, t_disciplina dado);
t_disciplina * getElemento(t_listaDisciplina lista, int pos);
t_no * getNo(t_listaDisciplina lista, int pos);
int menu();




int main(){
    setlocale("LC_ALL", "portuguese");
    int percorreImprime, pegaOpc,opcSair, contador;
    pegaOpc = 0; /** recebe o retorno da funçao para fazer o controle no switch case*/
    opcSair = 0;/** Faz o controle da saida do segundo laço do while*/
    contador = 0; /** Insere o conteudo de matricula na lista t_disciplina no indice contador,
    está sendo usada dentro do case 1*/
    percorreImprime = 0;/** percorre indice a indice até que o final seja NULL faz o controle
    para imprimir tudo, está sendo ultilizada dentro do case 1 */


    t_listaDisciplina listaDisciplinas = NULL; /** lista encadeada de disciplinas **/

    t_disciplina disciplina; /** strutura que armazena disciplina e nota **/
    t_alunos alunos; /** lista sequencial de alunos **/

    t_listaDisciplina novo = NULL; /** Ponteiro para um t_no */

    do{
        pegaOpc = menu();
        switch(pegaOpc){
            case 1:

                do{
                printf("informe sua matricula: ");
                scanf("%s", &disciplina.matricula);


                printf("Informe sua disciplina: ");
                scanf("%s", &disciplina.disciplina);


                printf("informa a nota da disciplina %s: ", disciplina.disciplina);


                scanf("%f", &disciplina.nota);




                inserir(&listaDisciplinas, contador, disciplina);

                do{
                printf("Digite -1 para sair ou 2 para continuar ");
                scanf("%d", &opcSair);
                }while(opcSair != -1 && opcSair != 2);
                contador ++ ;

                }while(opcSair != -1);


                break;


                case 2:

                    novo = listaDisciplinas;



                    while(novo != NULL){
                        printf("\nSua nota na disciplina %s e %2.f", novo->dado.disciplina, novo->dado.nota); /** Estou usando das duas formas,
                        pois foi o unico jeito que achei de executar o programa da forma mais correta possivel. */


                        printf("\nO numero da sua matricula é %s", novo->dado.matricula);
                        printf("\n------------------------------------------------");




                        percorreImprime ++;
                        novo = novo->prox;

                    }

                    printf("\nPressione qualquer tecla...\n");
                    system("pause");

                    break;

        }
    }while(pegaOpc != 0);

    printf("Liberando espaço alocado...\n");
    free(novo);
    free(listaDisciplinas);
    getchar();


}


int menu(){
    int opc;

    printf("Aluno: Rafael Matheus\n");
    printf("Matricula : 1610014657\n");
    printf("Disciplina: Estrutura de dados\n");
    printf("Professor: Wallace Bonfim\n");
    printf("Pressione a tecla enter para continuar: ");
    getchar();

    system("cls || clear");

    printf("\t\t\t\tMatricula\n");

    do{
    printf("1- Inserir\n");
    printf("2- Exibir historico\n");
    printf("0- Sair\n");
    printf("Digite sua opção: ");
    scanf("%d", &opc);


    system("cls || clear");
    if(opc !=1 && opc !=2 && opc != 0) // verifica a opc
        printf("Informe um valor valido\n");
    }while(opc !=1 && opc !=2 && opc != 0 );
    return opc; //Retorna a opc que o usuario forneceu
}
/**
 * Cria um novo nó, aloca a sua regiao de memoria,
 * inicializa o ponteiro prox, e retorna o ponteiro o no criado.
 *
 * @return No alocada e inicializada
 */
t_no * criaNo() {
    t_no * no = (t_no*) malloc(sizeof(t_no));

    if (no)
        no->prox = NULL;

    return no;
}

/**
 * Obtem um elemento da lista especificado por pos. Utiliza a funcao getNo(),
 * para obter o no, e em seguida extrair o elemento do no.
 *
 * @param lista ponteiro para a lista
 * @param pos   posicao do elemento desejado
 *
 * @see getNo()
 *
 * @return ponteiro para o elemento desejado, caso a posicao seja invalida retorna 0.
 */
t_disciplina * getElemento(t_listaDisciplina lista, int pos){
    t_no * no = getNo(lista, pos);
    if (no != NULL)
        return &(no->dado);
    else
        return NULL;
}

/**
 * Percorre toda a lista ate chegar na posicao desejada, em seguida retorna
 * o endereco do no atual.
 *
 * @param lista ponteiro para a lista
 * @param pos   posicao do no desejado
 * @see getElemento()
 *
 * @return ponteiro para o elemento desejado, caso a posicao seja invalida retorna 0.
 */
t_no * getNo(t_listaDisciplina lista, int pos) {
    // Retorna 0 se posicao invalida. Do contrario, retorna o elemento
    int n = 0;

    if (pos<0)
        return 0; // erro: posicao invalida

    while (lista != NULL) {
        if (n==pos)
            return lista;
        lista = lista->prox;
        n++;
    }
    return 0; // erro: posicao invalida
}

/**
 * Insere um elemento (dado) em determinada posicao da lista.
 *
 * @param lista ponteiro para a lista
 * @param pos   posicao que o elemento que sera inserido ficara.
 * @param dado  elemento a ser inserido
 *
 * @return Falso(0) se a posição for invalida ou se a lista estiver cheia, caso contrario, retorna Verdadeiro(1).
 */
int inserir(t_listaDisciplina *lista, int pos, t_disciplina dado) {
    t_no * p, * novo;

    // inserção na primeira posicao ou em lista vazia
    if (pos == 0) {
        novo = criaNo();
        if (novo == NULL)
            return 0; // erro: memoria insuficiente
        novo->dado = dado;
        novo->prox = *lista;
        *lista = novo;
        return 1;
    }
    // insercao apos a primeira posicao em lista nao vazia
    p = getNo(*lista, pos-1);
    if (p == NULL)
         return 0; // erro: posicao invalida
    novo = criaNo();
    if (novo == NULL)
        return 0; // erro: memoria insuficiente
    novo->dado = dado;
    novo->prox = p->prox;
    p->prox = novo;

    return 1;
}
