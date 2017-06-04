#include <stdio.h>
#include <stdlib.h>




 typedef struct elementos {
    int numeroArquivo ;
} t_elemento;

typedef struct no {
    struct no * esq;
    t_elemento dado;
    struct no * dir;
} t_no;

typedef t_no* t_arvore;




t_no * criar ();
int compara(t_elemento dado, t_elemento item);
int inserir (t_arvore *tree, t_elemento item);
int menu();
int converter(char str[], int *numeroConvertido[]);
int lerArquivo(FILE* arquivo, char str[]);

int main()
{
   FILE *arquivo = NULL;
   t_arvore arvore = NULL;
   int pegaOpc = 0;
   char str[100];
   int numeroConvertido[100];

   lerArquivo(arquivo, &str);
   converter(str, &numeroConvertido);

   printf("%s", numeroConvertido);

    return 0;
}





t_no * criar ()
{
    t_no * no = (t_no*) malloc(sizeof(t_no));

    if (no)
        no->esq = no->dir = NULL;

    return no;
}

int compara(t_elemento dado1, t_elemento dado2){


    if(dado1.numeroArquivo == dado2.numeroArquivo)
        return 0;
    else if(dado1.numeroArquivo < dado2.numeroArquivo)
        return -1;
    else
        return 1;



}


int inserir (t_arvore *tree, t_elemento item)
{
    int ok;
    // se a raiz for nula, entao insere na raiz
    if (*tree == NULL) {
        *tree = criar();
        if (*tree == NULL)
            return 0;
        (*tree)->dado = item;
        return 1;
    }
    if (compara((*tree)->dado, item)<0)
        ok = inserir (&((*tree)->dir), item);
    else
        if (compara((*tree)->dado, item)>0)
            ok = inserir (&((*tree)->esq), item);
        else
            ok = 0;
    return ok;
}

int converter(char str[], int *numeroConvertido[]){
	int i;
	char endereco;

	    endereco= strtok(str, ";");


	    while(endereco != NULL){

	        numeroConvertido[i] = atoi(endereco);
	        endereco= strtok(NULL, ";");
	        i++;

	    }
	    return 0;
	}



int lerArquivo(FILE* arquivo, char str[]){

	arquivo = fopen("Numeros.txt", "r");
	char c;

	if(!arquivo){
		printf("Arquivo invalido");
		return -1; //erro
	}

	else{
		fscanf(arquivo,"%s", str);
		return 0;
	}



}

int menu(){
 	int opc = 0 ;
 	printf("Aluno: Rafael Matheus\n");
 	printf("Disciplina: Estrutura de dados\n");
 	printf("Matricula: 1610014657\n\n");

	printf("1 - Inserir\n");
	printf("2 - Remover apenas um no\n");
	printf("3 - Pesquisar\n");
	printf("4 - Esvaziar a arvore\n");
	printf("5 - Exibir arvore\n");
	printf("0 - sair\n");
	scanf("%d", &opc);
	return opc;
}
