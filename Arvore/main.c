#include <stdio.h>
#include <stdlib.h>




 typedef struct elementos {
    char nome[100];	
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
int leituraEscrita(FILE *arquivo, t_arvore arvore);
int menu();

int main()
{
   FILE *arquivo = NULL;
   t_arvore arvore = NULL;
   int pegaOpc = 0;
   
   do{
   		pegaOpc = menu();
		   switch(pegaOpc){
				
				
				
				case 0:
					//sair 
					printf("Ola");
					break;
					
				case 1:
					//Inserir
					
					break;
				
				case 2:
					//remover apenas 1 no
					
					break;
				case 3:
					//pesquisar 
					break;
					
				case 4:
					//esvaziar a arvore
					
					break;
				case 5:
					//exibir arvore 
					break;	
			}
   }while(pegaOpc != 0 );
   
   leituraEscrita(arquivo, arvore);
 
    return 0;
}





t_no * criar ()
{
    t_no * no = (t_no*) malloc(sizeof(t_no));

    if (no)
        no->esq = no->dir = NULL;

    return no;
}

int compara(t_elemento dado, t_elemento item){
	return (strcmp(dado, item));
	
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


int leituraEscrita(FILE *arquivo, t_arvore arvore){
	char numeroArquivo;
	arquivo = fopen("Numeros.txt", "r");
	
	if(arquivo == NULL){
		printf("Erro ao abrir arquivo");
		return -1; //erro na abertura do arquivo
	}
	
	else{
		while(!feof(arquivo)){
			numeroArquivo = fgetc(arquivo);
		
		
	
		}		

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
