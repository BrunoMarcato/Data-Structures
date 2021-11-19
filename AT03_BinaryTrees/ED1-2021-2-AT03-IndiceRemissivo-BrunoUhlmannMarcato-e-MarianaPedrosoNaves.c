#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h> //uso da tolower
#include <string.h>

//----------------------------------------
//---------- DEFINIÇÃO DOS TAD -----------
//----------------------------------------

//Listas
typedef struct NodeList *Pointer;

typedef struct NodeList {
  int value;
  Pointer next;
  Pointer previous;
} NodeList;

typedef struct {
  Pointer first;
  Pointer end;
  int size;
} List;

//Objeto da árvore (lista e a palavra)

typedef struct {
  List list;
  char word[51];
} Object;

//Árvores
typedef struct TreeNode* PtrTreeNode;

typedef struct TreeNode {
    Object object;
    PtrTreeNode right;
    PtrTreeNode left;
} TreeNode;



//Funções de manipulação da Lista Duplamente Encadeada

//----------------------------------------
//----------- INICIAR LISTA -------------
//----------------------------------------

void initList(List *list) {
    list -> first = NULL;
    list -> end = NULL;
    list -> size = 0;
}//initList

//Funções de manipulação da Árvore binária

//----------------------------------------
//----------- INICIAR ÁRVORE -------------
//----------------------------------------

void inicializeTree(PtrTreeNode *tree) {
    *tree = NULL;
}

//----------------------------------------
//------ VERIFICAR SE ESTÁ VAZIA ---------
//----------------------------------------

bool isEmpty(PtrTreeNode *tree) {
    return (*tree == NULL);
}

//----------------------------------------
//--------- INSERIR NA ÁRVORE ------------
//----------------------------------------

bool push(PtrTreeNode *tree, char word[]) {
    //tree is empty (recursion stop condition)
    if(isEmpty(tree)) {
        (*tree) = malloc(sizeof(TreeNode));
        (*tree) -> right = (*tree) -> left = NULL;
        initList(&(*tree)->object.list); //cada nó será uma lista
        strcpy((*tree) -> object.word, word);
        return true;
    }

    //duplicate word (recursion stop condition)
    if(strcmp((*tree) -> object.word, word) == 0) {
        printf("Warning: Palavra já existente no índice\n");
        return false;
    }

    //recursion
    if(strcmp((*tree) -> object.word, word) < 0) {
        //a primeira letra não coincidente da palavra no objeto da árvore vem antes, na ordem alfabética, do que a palavra passada como argumento
        //go to right node
        return (push(&(*tree) -> right, word));
    } else {
        //go to left node
        return (push(&(*tree) -> left, word));
    }
}

//----------------------------------------
//--------- IMPRIMIR EM ORDEM ------------
//------------- NO ARQUIVO ---------------
//----------------------------------------

//a impressão ocorre entre as duas chamadas recursivas
//será impresso uma lista, portanto seguirá o mesmo código da impressão da lista

void inOrder(PtrTreeNode *tree, FILE* saida) {
    if((*tree) == NULL) return;

    inOrder(&(*tree) -> left, saida);

    //impressão da palavra do índice
    fprintf(saida, "%s,", (*tree)->object.word);

    //impressão da lista
    Pointer aux = (*tree)->object.list.first;

    while(aux != NULL){

      if(aux -> next == NULL) {
        fprintf(saida, "%d", aux -> value);
      } else {
        fprintf(saida, "%d,", aux -> value);
      }

      aux = aux->next;

    }

    fprintf(saida, "\n");


    inOrder(&(*tree) -> right, saida);

}

//----------------------------------------
//--------- INSERIR NA LISTA ------------
//----------------------------------------

void pushList(PtrTreeNode *tree, int page){
  Pointer newNode;
  newNode = (Pointer)malloc(sizeof(Pointer));
  newNode -> value = page;

  if((*tree) -> object.list.size == 0){ //se a lista estiver vazia
    
    (*tree) -> object.list.first = newNode;

    (*tree) -> object.list.end = newNode;

    newNode -> next = NULL;

  } else { //se não, insersão sempre será no final da lista (visto que o número de páginas sempre cresce)

    if((*tree) -> object.list.end -> value == page) return; //se já foi encontrada a palavra nesta página, não insere nada (evita páginas repetidas pra mesma palavra do índice)

    // Pointer aux = list -> end;
    // list -> end = newNode;
    // newNode -> next = NULL;
    // newNode -> previous = aux;
    // aux -> next = newNode;
    
    (*tree) -> object.list.end -> next = newNode;

    newNode -> previous = (*tree) -> object.list.end;

    (*tree) -> object.list.end = newNode;

    newNode -> next = NULL;
  
  }

  (*tree) -> object.list.size++;

}


//----------------------------------------
//----- PROCURAR ELEMENTO NA ÁRVORE ------
//----------------------------------------

bool search(PtrTreeNode *tree, int page, char word[]) {
    //did not find the element (end case of recursion -> negative)
    if((*tree) == NULL) return (false);

    //found the element (end case of recursion -> positive)
    if(strcmp((*tree) -> object.word, word) == 0) {
        //inserir na lista de ocorrência da palavra
        pushList(&(*tree), page);
        return (true);
    }

    //recursion
    if(strcmp((*tree) -> object.word, word) < 0) {
        search(&(*tree) -> right, page , word);
    } else {
        search(&(*tree) -> left, page, word);
    }
}

//----------------------------------------
//----------- DESTRUIR ÁRVORE ------------
//----------------------------------------

void destroy(PtrTreeNode *tree) {
    if((*tree) != NULL) {
        destroy(&(*tree) -> left);
        destroy(&(*tree) -> right);
        free(*tree);
        (*tree) = NULL;
    }
}

//----------------------------------------

int main(int argc, const char * argv[]) {
    
    // usando o argc 
    printf("Numero de parametros fornecidos: %d\n", argc);

    if(argc != 3) { 
        printf("Quantidade de parametros invalida!\n");
        return 0;
    }  

    for(int i = 0; i < argc; i++) {
        printf("argv[%d] = %s\n", i, argv[i]);
    }


    //declaração das variáveis
    char* identificacao; //String que será separada para localizar o número das páginas ou as palavras do índice
    
    char* palavra; //palavras a serem colocadas no índice
    
    char text[1001]; //texto coletado para a verificação
    
    int cont_pagina = 0; //número da página onde se localiza uma determinada palavra

    //declaração da árvore
    PtrTreeNode root;

    //inicialização da árvore
    inicializeTree(&root);

    //abertura dos arquivos
    FILE *entrada = fopen(argv[1], "r");
    FILE *saida = fopen(argv[2], "w");

    //Verificação de erro de abertura dos arquivos
    if (entrada == NULL || saida == NULL){
      printf("Erro: algum dos arquivos nao pode ser aberto corretamente!\n");
      return 0;
    }

    //leitura da primeira linha do arquivo
    fscanf(entrada, "%s", &text);

    //verifica-se o id (se é preciso separar string em uma substring, para localizar os termos, as palavras e as páginas)
    identificacao = strtok(text, " <>:,;.()\n");

    if(strcmp(identificacao, "termos") == 0){ //caso a substring seja "termos" serão separadas as palavras a serem incluídas no índice

      do {
        
        palavra = strtok(0, " <>:,;.()\n"); //separa as palavras a serem colocadas no índice (usando a vírgula como delimitador)
        
        if(palavra == NULL) break; //se chegar ao final das palavras, sai do loop
        
        //converte a palavra para minúscula
        for(int i = 0; i < strlen(palavra); i++) {
            palavra[i] = tolower(palavra[i]);
        }

        push(&root, palavra); //se não, insere a palavra na árvore
      
      } while(1);

    }

    while(fgets(text, 1001, entrada) != NULL){ //enquanto existir texto para ser lido... (fgets retorna null quando falha na leitura da linha)
    
      identificacao = strtok(text, " <>:,;.()\n"); //separa as palavras do texto 
      do {

        if(identificacao == NULL) break; //se não encontrar mais id's...

        //converte a palavra para minúscula
        for(int i = 0; i < strlen(identificacao); i++) {
            identificacao[i] = tolower(identificacao[i]);
        }
        
        if(strcmp(identificacao, "page") == 0) cont_pagina++; //se encontrar um "page" significa que estamos em uma nova página
        
        search(&root, cont_pagina, identificacao); //procura pela palavra nos "termos", se encontrar, inclui o número da página na fila de ocorrência dessa palavra 
        
        identificacao = strtok(0, " <>:,;.()\n"); //ler o próximo id

      } while(1);

    }

    inOrder(&root, saida); //printar no arquivo os termos junto com a fila de ocorrência do termo

    printf("Sucesso!\n");

    //destruição da árvore
    destroy(&root);
    printf("Arvore cortada!");

    //fechamento dos arquivos
    fclose(entrada);
    fclose(saida);
    return 0;
}

//--------------------FIM DO PROGRAMA--------------------
