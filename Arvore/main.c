#include <stdio.h>
#include <stdlib.h>

typedef struct elementos {
	char nome[100] ;
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
void lerArquivo(t_arvore* arvore);


int main()
{
	
	FILE *arquivo = NULL;
	t_arvore arvore = NULL;
	int pegaOpc = 0;
	char str[100];
	int numeroConvertido[100];

	lerArquivo(&arvore);

/** Observar a saida nesse ponto **/

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

	return (strcmp(dado1.nome, dado2.nome));

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


void lerArquivo(t_arvore* arvore){
	t_elemento elemento;
	char url[]="Numeros.txt";
	char ch;
	int i=0;
	FILE *arq;

	arq = fopen(url, "r");
	if(arq == NULL){
	printf("Erro, nao foi possivel abrir o arquivo\n");

} 
	else {
	while( (ch=fgetc(arq))!= EOF ){
		if(ch == ';'){
		elemento.nome[i] = '\0';
		printf("%s\n", elemento.nome);	
		inserir(arvore, elemento);
		i=0;
} 
else {
	elemento.nome[i] = ch;
	i++;
		}
	}
}
	fclose(arq);
}
