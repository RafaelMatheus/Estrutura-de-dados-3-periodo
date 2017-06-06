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

void exibir(t_arvore arvore);
t_no * busca(t_arvore tree, t_elemento dado);
void pesquisar(t_elemento dado, t_arvore tree);
t_no * buscaSetPai(t_arvore tree, t_elemento dado, t_no ** pai);
int remover (t_arvore *tree, t_elemento item);
void exibirPosOrdem(t_arvore tree);
t_no * criar ();
int compara(t_elemento dado, t_elemento item);
int inserir (t_arvore *tree, t_elemento item);
int menu();
void lerArquivo(t_arvore* arvore);
void exibirInOrdem(t_arvore tree);
void exibirPreOrdem(t_arvore tree);
void apagar();

int main()
{
	
	FILE *arquivo = NULL;
	t_arvore arvore = NULL;
	int pegaOpc = 0;
	char str[100];
	int numeroConvertido[100];
	t_elemento dado;
	
	do{
		pegaOpc = menu();
		
		switch(pegaOpc){
			
			case 1:
				lerArquivo(&arvore);
				break;
		//	case 2:
				
			case 3:
				printf("Informe o dado que voce deseja pesquisar: ");
				scanf("%s",&dado.nome);
				pesquisar(dado, arvore);
				break;
			
			case 5:
				exibir(arvore);
		}
		
	
			
		
	}while(pegaOpc != 0);
	
	
	

/** Observar a saida nesse ponto **/

return 0;
}


t_no * buscaSetPai(t_arvore tree, t_elemento dado, t_no ** pai)
{

    if (tree == NULL) {
        *pai = NULL;
        return NULL;
    }
    if (compara(tree->dado, dado)==0)
        return tree;

    if (compara(tree->dado, dado)>0) {
        *pai = tree;
        return buscaSetPai(tree->esq, dado, pai);
    }
    else {
        *pai = tree;
        return buscaSetPai(tree->dir, dado, pai);
    }
}

/**
int remover (t_arvore *tree, t_elemento item) {
    t_no *no, // no aponta para o no a ser removido
        *pai, // pai aponta para o pai do no
        *sub, // sub aponta que ira substituir o no no
        *paiSuce, // pai do no sucessor
        *suce; // sucessor do no no
    no = *tree; pai=NULL;
    // procura o no a ser removido, e seta o seu pai.
    no = buscaSetPai(*tree, item, &pai);
    if (no==NULL)
        return 0; // a chave nao existe na arvore, nao conseguiu remover
    // agora iremos ver os dois primeiros casos, o no tem um filho no maximo
    if (no->esq == NULL)
        sub = no->dir;
    else {
        if (no->dir == NULL)
           sub = no->esq;
        else { // caso em que o no tem dois filhos
       }}
    // insere sub na posicao ocupada anteriormente por no
    if (pai == NULL) // no eh a raiz, nao tem pai
       *tree = sub;
    else
        // verifica se o no eh o filho da esquerda ou da direita
        if (no == pai->esq)
            pai->esq = sub;
        else
            pai->dir = sub;
    free(no); // libera o no
    
    return 1;
    
            else { // caso em que o no tem dois filhos
             paiSuce=no;
             sub = no->dir;
             suce = sub->esq;   // suce eh sempre o filho esq de sub
             while (suce != NULL) {
                   paiSuce = sub;
                   sub = suce;
                   suce = sub->esq;
             }
             // neste ponto, sub eh o sucessor em ordem de no
             if (paiSuce != no) {
                //  no nao e o pai de sub, e sub == paiSuce->esq
                paiSuce->esq = sub->dir;
                // remove o no sub de sua atual posicao e o
                // substitui pelo filho direito de sub
                // sub ocupa o lugar de no
                sub->dir = no->dir;
             }
             // define o filho esquerdo de sub de modo que sub
             // ocupe o lugar de no
             sub->esq = no->esq;
        }
}
*/
t_no * busca(t_arvore tree, t_elemento dado)
{

    if (tree == NULL) 
        return NULL;
    if (compara(tree->dado, dado)==0)
        return tree;

    if (compara(tree->dado, dado)>0)
        return busca(tree->esq, dado);
    else
        return busca(tree->dir, dado);
}


void pesquisar(t_elemento dado, t_arvore tree)	
{
	t_no *retorno;
	
	retorno = busca(tree, dado);
	
	if(retorno == NULL){
		printf("Conteudo nao existe na arvore: \n ");
		
	}
	
	else{
		printf("tudo bem");
	}



	
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

void exibirInOrdem(t_arvore tree)
{
    if (tree!=NULL) {
        exibirInOrdem(tree->esq);
        printf("%s ", tree->dado.nome);
        exibirInOrdem(tree->dir);
    }
}

void exibirPreOrdem(t_arvore tree)
{
    if (tree!=NULL) {
        printf("%s ", tree->dado.nome);
        exibirPreOrdem(tree->esq);
        exibirPreOrdem(tree->dir);
    }
}


void exibirPosOrdem(t_arvore tree)
{
    if (tree!=NULL) {
        exibirPosOrdem(tree->esq);
        exibirPosOrdem(tree->dir);
        printf("%s ", tree->dado.nome);
    }
}

void exibir(t_arvore arvore){
	
	printf("Exibicao em ordem: ");
	exibirPreOrdem(arvore);
	printf("\n\n");
	printf("Exibicao pos ordem: ");
	exibirPosOrdem(arvore);
	printf("\n\n");
	printf("Exibicao in ordem: ");
	exibirInOrdem(arvore);
	printf("\n\n");
	
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
