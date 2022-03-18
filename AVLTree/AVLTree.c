#include "AVLTree.h"

//---------------------------------------

void iniciaArvoreAVL(PtrNoAVL *node) {
    *node = NULL;
}

//---------------------------------------

// bool estaVaziaArvoreAVL(PtrNoAVL *node) {
//     return (*node == NULL);
// }

//---------------------------------------

void preOrdem(PtrNoAVL *node) {

    if(*node == NULL) return;
    printf("%d ", (*node)->chave);
    preOrdem(&(*node) -> esquerda);
    preOrdem(&(*node) -> direita);

}

//---------------------------------------

// void posOrdem(PtrNoAVL *node) {

//     if(*node == NULL) return;
//     posOrdem(&(*node) -> esquerda);
//     posOrdem(&(*node) -> direita);
//     printf("%d ", (*node)->chave);

// }

//---------------------------------------

// void emOrdem(PtrNoAVL *node) {

//     if(*node == NULL) return;
//     emOrdem(&(*node) -> esquerda);
//     printf("%d ", (*node)->chave);
//     emOrdem(&(*node) -> direita);

// }

//---------------------------------------

// bool pesquisaArvoreAVL(PtrNoAVL *node, int x) {
    
//     //casos base da recursão
//     if(*node == NULL) return false;
//     if((*node)->chave == x) return true;

//     if(x > (*node) -> chave) return (pesquisaArvoreAVL(&(*node) -> direita, x));
//     if(x < (*node) -> chave) return (pesquisaArvoreAVL(&(*node) -> esquerda, x));
// }

//---------------------------------------

void destruirArvoreAVL(PtrNoAVL *node) {

    if((*node) != NULL) {
        destruirArvoreAVL(&(*node) -> direita);
        destruirArvoreAVL(&(*node) -> esquerda);
        free(*node);
        (*node) = NULL;
    }

}

//---------------------------------------

int alturaArvoreAVL(PtrNoAVL *node) {
    if(*node == NULL) return 0;
    else return ((*node) -> altura);
}

//---------------------------------------

void rotacaoSimplesEsquerda(PtrNoAVL *node) {
    printf("Rotação simples p/ esquerda, com node: %d\n", (*node)->chave);

    PtrNoAVL u = (*node)->direita;
    (*node)->direita = u->esquerda;
    u->esquerda = (*node);

    //atualizar a altura dos nós modificados (node, u)
    (*node)->altura = atualizaAlturaArvoreAVL((*node)->esquerda, (*node)->direita);
    u->altura = atualizaAlturaArvoreAVL(u->esquerda, u->direita);

    //autualizacao da referencia do node
    (*node) = u;
}

//---------------------------------------

void rotacaoSimplesDireita(PtrNoAVL *node) {
    printf("Rotação simples p/ direita, com node: %d\n", (*node)->chave);

    PtrNoAVL u = (*node)->esquerda;
    (*node)->esquerda = u->direita;
    u->direita = (*node);

    //atualizar a altura dos nós modificados (node, u)
    (*node)->altura = atualizaAlturaArvoreAVL((*node)->esquerda, (*node)->direita);
    u->altura = atualizaAlturaArvoreAVL(u->esquerda, u->direita);

    //autualizacao da referencia do node
    (*node) = u;
}

//---------------------------------------

void rotacaoDuplaEsquerda(PtrNoAVL *node) {
    printf("Rotação dupla p/ esquerda, com node: %d\n", (*node)->chave);

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

//---------------------------------------

void rotacaoDuplaDireita(PtrNoAVL *node) {
    printf("Rotação dupla p/ direita, com node: %d\n", (*node)->chave);

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

//---------------------------------------

void aplicarRotacoes(PtrNoAVL *node) {
    int ae = alturaArvoreAVL((*node)->esquerda);
    int ad = alturaArvoreAVL((*node)->direita);

    int rotacao = ae - ad;
    if(rotacao == 2) { //rotação para esquerda (fator de balanceamento positivo)
        //determinar se a rotação é simples ou dupla
        PtrNoAVL temp = (*node) -> direita;
        int tempAD = alturaArvoreAVL(temp -> direita);
        int tempAE = alturaArvoreAVL(temp -> esquerda);

        if(tempAE > tempAD)  {
            rotacaoDuplaEsquerda(&(*node));
        } else {
            rotacaoSimplesEsquerda(&(*node));            
        }
    } else { //rotação para a direita (fator de balanceamento negativo)
        //determinar se a rotação é simples ou dupla
        PtrNoAVL temp = (*node) -> esquerda;
        int tempAD = alturaArvoreAVL(temp -> direita);
        int tempAE = alturaArvoreAVL(temp -> esquerda);

        if(tempAD > tempAE) {
            rotacaoDuplaDireita(&(*node));
        } else {
            rotacaoSimplesDireita(&(*node));
        }
    }
}

//---------------------------------------

int atualizaAlturaArvoreAVL(PtrNoAVL esq, PtrNoAVL dir) {
    int ae = alturaArvoreAVL(esq);
    int ad = alturaArvoreAVL(dir);

    if(ae > ad) return (ae + 1);
    else return (ad + 1);
}


//---------------------------------------

bool inserirArvoreAVL(PtrNoAVL *node, int x) {
    if(*node == NULL) {
        *node = (PtrNoAVL) malloc(sizeof(NoAVL));
        (*node) -> esquerda = (*node) -> direita = NULL;
        (*node) -> chave = x;
        (*node) -> altura = 1;
        return true;
    }

    if((*node)->chave = x) return false; //evita elementos repetidos na árvore

    bool inseriu;
    if(x > (*node)->chave) {
        inseriu = inserirArvoreAVL(&(*node)->direita, x);
    } else {
        inseriu = inserirArvoreAVL(&(*node)->esquerda, x);
    }

    if(inseriu == false) return false;

    int alturaEsquerda, alturaDireita;
    alturaEsquerda = alturaArvoreAVL((*node) -> esquerda);
    alturaDireita = alturaArvoreAVL((*node) -> direita);

    //identifica o desbalanceamento
    if(alturaDireita - alturaEsquerda == 2 || alturaDireita - alturaEsquerda == -2) {
        aplicarRotacoes(&(*node));
    }

    (*node)->altura = atualizaAlturaArvoreAVL(&(*node) -> esquerda, &(*node) -> direita);
    return true;
}

//---------------------------------------