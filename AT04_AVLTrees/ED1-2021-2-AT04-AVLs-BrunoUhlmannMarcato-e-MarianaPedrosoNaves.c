#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//---------------------------------------
//----------DEFINIÇÃO DO TAD-------------
//---------------------------------------

typedef struct NoAVL* PtrNoAVL;

typedef struct NoAVL {
    int chave;
    PtrNoAVL direita;
    PtrNoAVL esquerda;
    int altura;
} NoAVL;

//----------------------------------------
//------- FUNÇÕES DE MANIPULAÇÃO ---------
//------------- DA ARVORE ----------------
//----------------------------------------

//---------------------------------------

void iniciaArvoreAVL(PtrNoAVL *node) {
 *node = NULL;
}

bool estaVaziaAVL(PtrNoAVL *node) {
  return((*node) == NULL);
}

// -------------------------------
// -------------------------------

void emOrdem(PtrNoAVL *node) {
  if((*node) == NULL) return;
  emOrdem(&(*node)->esquerda);
  printf("%d ", (*node)->chave);
  emOrdem(&(*node)->direita);
}

void preOrdem(PtrNoAVL *node) {
  if((*node) == NULL) return;
  printf("%d ", (*node)->chave);
  preOrdem(&(*node)->esquerda);
  preOrdem(&(*node)->direita);
}

// -------------------------------
// -------------------------------

int alturaArvoreAVL(PtrNoAVL node) {
  if(node == NULL) {
    return (0);
  } else {
    return ((node)->altura);
  }
}

// -------------------------------
// -------------------------------

int atualizaAlturaArvoreAVL(PtrNoAVL esq, PtrNoAVL dir) {

  int ae = alturaArvoreAVL(esq);
  int ad = alturaArvoreAVL(dir);

  if(ae > ad) {
    return(ae + 1);
  } else {
    return(ad + 1);
  }
}

void rotacaoSimplesDireita(PtrNoAVL *node) {
  printf("Rotacao simples p/ direita, com node: %d\n", (*node)->chave);

  PtrNoAVL u = (*node)->esquerda;
  (*node)->esquerda = u->direita;
  u->direita = (*node);

  //atualizar a altura dos nós modificados (node, u)
  (*node)->altura = atualizaAlturaArvoreAVL((*node)->esquerda, (*node)->direita);
  u->altura = atualizaAlturaArvoreAVL(u->esquerda, u->direita);

  //autualizacao da referencia do node
  (*node) = u;
}

void rotacaoSimplesEsquerda (PtrNoAVL *node) {
  printf("Rotacao simples p/ esquerda, com node: %d\n", (*node)->chave);

  PtrNoAVL u = (*node)->direita;
  (*node)->direita = u->esquerda;
  u->esquerda = (*node);

  //atualizar a altura dos nós modificados (node, u)
  (*node)->altura = atualizaAlturaArvoreAVL((*node)->esquerda, (*node)->direita);
  u->altura = atualizaAlturaArvoreAVL(u->esquerda, u->direita);

  //autualizacao da referencia do node
  (*node) = u;
}

void rotacaoDuplaEsquerda (PtrNoAVL *node) {
  printf("Rotacao dupla p/ esquerda, com node: %d\n", (*node)->chave);

  PtrNoAVL u, v;
  u = (*node)->direita;
  v = u->esquerda;

  (*node)->direita = v->esquerda;
  u->esquerda = v->direita;
  v->esquerda = (*node);
  v->direita = u;

  //atualizar a altura dos nós modificados (node, u, v)
  (*node)->altura = atualizaAlturaArvoreAVL((*node)->esquerda, (*node)->direita);
  u->altura = atualizaAlturaArvoreAVL(u->esquerda, u->direita);
  v->altura = atualizaAlturaArvoreAVL(v->esquerda, v->direita);

  //autualizacao da referencia do node
  (*node) = v;
}

void rotacaoDuplaDireita (PtrNoAVL *node) {
  printf("Rotacao dupla p/ direita, com node: %d\n", (*node)->chave);

  PtrNoAVL u, v;
  u = (*node)->esquerda;
  v = u->direita;

  (*node)->esquerda = v->direita;
  u->direita = v->esquerda;

  v->direita = (*node);
  v->esquerda = u;

  //atualizar a altura dos nós modificados (node, u, v)
  (*node)->altura = atualizaAlturaArvoreAVL((*node)->esquerda, (*node)->direita);
  u->altura = atualizaAlturaArvoreAVL(u->esquerda, u->direita);
  v->altura = atualizaAlturaArvoreAVL(v->esquerda, v->direita);

  //autualizacao da referencia do node
  (*node) = v;
}

// -------------------------------
// -------------------------------

void aplicarRotacoes(PtrNoAVL *node) {

  int ad = alturaArvoreAVL((*node)->direita);
  int ae = alturaArvoreAVL((*node)->esquerda);

  // Verificar se é rotacao para direita
  if(ae > ad) {
    PtrNoAVL temp = (*node)->esquerda;
    int temp_ad = alturaArvoreAVL(temp->direita);
    int temp_ae = alturaArvoreAVL(temp->esquerda);
    // temp_ae > ou >= temp_ad
    if(temp_ae > temp_ad) {
      rotacaoSimplesDireita(&(*node));
    } else {
      rotacaoDuplaDireita(&(*node));
    }
  }
  // Senao é rotacao para esquerda
  else { //(ad > ae)
    PtrNoAVL tmp2 = (*node)->direita;
    int tmp2_ad = alturaArvoreAVL(tmp2->direita);
    int tmp2_ae = alturaArvoreAVL(tmp2->esquerda);

    if(tmp2_ad > tmp2_ae){
      rotacaoSimplesEsquerda(&(*node));
    } else {
      rotacaoDuplaEsquerda(&(*node));
    }
  }
}

// -------------------------------
// -------------------------------

// *** Inserção
bool inserirArvoreAVL(PtrNoAVL *node, int x) {

  //1. condicao final da recusao (positiva)
  if((*node) == NULL) {
    (*node) = (PtrNoAVL)malloc(sizeof(NoAVL));
    (*node)->direita = (*node)->esquerda = NULL;
    (*node)->chave = x;
    (*node)->altura = 1;
    return true;
  }

  //2. elemento ja existe
  if((*node)->chave == x) return false;

  bool auxiliar;

  // 3. Laço de chamadas recusivas
  if(x < (*node)->chave) {
    auxiliar = inserirArvoreAVL(&(*node)->esquerda, x);
  } else {
    auxiliar = inserirArvoreAVL(&(*node)->direita, x);
  }

  // Daqui para baixo começa o codigo só tem na AVL
  // 4. Se o auxiliar for falso, nao houve mudança na arvore
  if(!auxiliar) return (false);

  // Se houve modificacao na arvore
  // Precisamos checar o desbalanceamento
  int ae; // altura da sub-arvore da esquerda
  int ad; // altura da sub-arvore da direita

  // 5. Calculando as alturas das sub-arvores
  ae = alturaArvoreAVL((*node)->esquerda);
  ad = alturaArvoreAVL((*node)->direita);

  // 6. Verificando desbalanceamento
  if((ad - ae) == +2 || (ad - ae) == -2) {
    // desbalancemaneto
    aplicarRotacoes(&(*node));
  }

  //7. ajuste da altura do no corrente
  (*node)->altura = atualizaAlturaArvoreAVL((*node)->esquerda, (*node)->direita);
  return(true);
}

//---------------------------------------
//---------------------------------------

PtrNoAVL maior(PtrNoAVL *node) {

    PtrNoAVL retorno;
    // caso base da recursao
    // se filho direita do node == NULL => maior elemento achado
    if ((*node)->direita == NULL)
    {
        retorno = (*node);
        (*node) = (*node)->esquerda;
        return (retorno);
    }
    return (maior(&(*node)->direita));
}

//---------------------------------------
//---------------------------------------

PtrNoAVL menor(PtrNoAVL *node) {

    PtrNoAVL retorno;
    // criterio de parada da recursao
    // se filho direita do node == NULL => menor elemento achado
    if ((*node)->esquerda == NULL)
    {
        retorno = (*node);
        // ajuste para remocao funcionar
        // remover o elemento da sub-arvore de node
        (*node) = (*node)->direita;
        return (retorno);
    }
    return (menor(&(*node)->esquerda));
}

//---------------------------------------
//---------------------------------------

bool removerAVL(PtrNoAVL *node, int valor, char z) {
    //1.Se o node é nulo
    if ((*node) == NULL)
        return (false);

    //2.se node->chave existe
    if ((*node)->chave == valor) {
        PtrNoAVL tmp = (*node);
        //2.1 verifica se é sub-arvore da esquerda
        if ((*node)->esquerda == NULL) {
            (*node) = (*node)->direita;
        } else if ((*node)->direita == NULL) { //2.2verifica se é sub-arvore da direita
            (*node) = (*node)->esquerda;
        } else { //2.3 Nó intermediario, nem folha nem raiz -> meio
            //verifica se qual operaçao fazer 'e' ou 'd'
            if (z == 'e') {
                //se for 'e' pega o maior valor
                tmp = maior(&(*node)->esquerda);
            } else {
                //se for 'd' pega o menor valor
                tmp = menor(&(*node)->direita);
            }
            //node = tmp
            (*node)->chave = tmp->chave;
        }
        free(tmp);
        return (true);
    }
    //variavel T ou F para auxiliar
    bool aux;
    //3. Se valor < node->elemento
    if (valor < (*node)->chave) {
        aux = removerAVL(&(*node)->esquerda, valor, z);
    } else {
        aux = removerAVL(&(*node)->direita, valor, z);
    }
    //4.Se o auxiliar for falso, nao houve mudança na arvore
    if (aux == false)
        return (false);

    // 5. Calculando as alturas das sub-arvores
    int AltEsq = alturaArvoreAVL((*node)->esquerda);
    int AltDir = alturaArvoreAVL((*node)->direita);
    // 6. Verificando desbalanceamento
    if ((AltEsq - AltDir) >= +2 || (AltEsq - AltDir) <= -2) {
        aplicarRotacoes(&(*node));
    }
    //7. ajuste da altura do no corrente
    (*node)->altura = atualizaAlturaArvoreAVL((*node)->direita, (*node)->esquerda);
    return (true);
}

//----------------------------------------
//----------------------------------------

void destruirArvoreAVL(PtrNoAVL *node) {
    // percurso
    //percorrer a arvore e desalocar memoria de traz p frente
    if ((*node) != NULL) {
        destruirArvoreAVL(&(*node)->esquerda);
        destruirArvoreAVL(&(*node)->direita);
        free(*node);
        (*node) = NULL;
    }
}

//---------------------------------------
//        FUNÇÕES PARA MANIPULAÇÃO
//             DA ATIVIDADE
//---------------------------------------


//---------------------------------------
//imprimir o número e o grau dos nós no arquivo
void grau(PtrNoAVL *node, int altura, FILE* saida) {

    if(*node == NULL) return;

    if(altura == 1) {
        //calculo do grau de desbalanceamento
        int alturaEsquerda = alturaArvoreAVL((*node) -> esquerda);
        int alturaDireita = alturaArvoreAVL((*node) -> direita);
        int grau = alturaDireita - alturaEsquerda;

        fprintf(saida, "%d (%d), ", (*node) -> chave, grau); //printar a chave e o grau de desbalanceamento no formato do arquivo
    } else {
        if(altura > 1) {
            grau(&(*node) -> esquerda, altura - 1, saida);
            grau(&(*node) -> direita, altura - 1, saida);
        }
    }
}

//---------------------------------------

void formatarArquivo(PtrNoAVL *node, FILE* saida) {
    for(int i = 1; i < (((*node) -> altura) + 1); i++) {
        grau(&(*node), i, saida);
        fprintf(saida, "\n");
    }
}

//---------------------------------------
//               MAIN
//---------------------------------------

int main(int argc, const char * argv[]) {

    // usando o argc 
    printf("Numero de parametros fornecidos: %d\n", argc);
    
    if(argc!= 3) {
      printf("Quantidade de parametros invalida\n");
      return 0;
    }  

    int i = 0;
    for(i = 0; i < argc; i++) {
      printf("argv[%d] = %s\n", i, argv[i]);
    }
    
    //Abertura dos arquivos
    FILE *entrada = fopen(argv[1], "r");
    FILE *saida = fopen(argv[2], "w");

    //verificação de falha na abertura dos arquivos
    if(entrada == NULL || saida == NULL) {
        printf("Erro na abertura dos arquivos!\n");
        exit(1);
    } else {
        printf("Arquivo aberto com sucesso!\n");
    }

    //iniciar árvore
    PtrNoAVL raiz;
    iniciaArvoreAVL(&raiz);

    //leitura do arquivo
    char l1[500];
    char l2[500];
    char tipoRemocao;

    fscanf(entrada, "%s\n", &l1); //leitura da linha de elementos a serem inseridos na árvore
    fscanf(entrada, "%s\n", &l2); //leitura da linha de elementos a serem removidos da árvore
    tipoRemocao = fgetc(entrada); //leitura do tipo de remoção a se fazer

    printf("Tipo de remocao: %c\n", tipoRemocao);

    //se o arquivo tiver o tipo válido
    if(tipoRemocao == 'd' || tipoRemocao == 'e') {

        NoAVL novoNo;

        char *tok = strtok(l1, ","); //separar os números, a serem inseridos (l1), em substrings usando a vírgula como delimitador

        int push;
        while(tok != NULL) {   //enquanto ainda tiver números a serem inseridos...
            push = atoi(tok); //converter o numero lido para inteiro
            novoNo.chave = push;
            inserirArvoreAVL(&raiz, novoNo.chave); //inserir na árvore
            tok = strtok(NULL, ","); //separar o próximo número
        }

        //imprimir a primeira parte do arquivo de saída (árvore antes da remoção)
        fprintf(saida,"[*]antes\n");
        formatarArquivo(&raiz, saida);


        char *tok2 = strtok(l2, ","); //separar os números, a serem removidos (l2), em substrings usando a vírgula como delimitador

        int pop;
        while(tok2 != NULL) {
            pop = atoi(tok2);
            novoNo.chave = pop;
            removerAVL(&raiz, novoNo.chave, tipoRemocao); //remover da árvore
            tok2 = strtok(NULL, ","); //separar o próximo número
        }

        //imprimir a segunda parte do arquivo de saída (árvore após a remoção)
        fprintf(saida, "\n[*]depois\n");
        formatarArquivo(&raiz, saida);


    } else {

        fprintf(saida, "Arquivo inválido!\n");

    }


    //fechamento dos arquivos
    fclose(entrada);
    fclose(saida);

    //destruição da árvore
    destruirArvoreAVL(&raiz);

    return 0;
}

//--------------- FIM DO PROGRAMA ----------------
