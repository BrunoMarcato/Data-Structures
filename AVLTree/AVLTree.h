#ifndef ArvoreAVL_h
#define ArvoreAVL_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/******************************************************************************/
/******************************************************************************/

typedef struct NoAVL* PtrNoAVL;

typedef struct NoAVL {
    int chave;
    PtrNoAVL direita;
    PtrNoAVL esquerda;
    int altura;
} NoAVL;

/******************************************************************************/
/******************************************************************************/

void iniciaArvoreAVL(PtrNoAVL *node);
bool estaVaziaArvoreAVL(PtrNoAVL *node);

void preOrdem(PtrNoAVL *node);
void posOrdem(PtrNoAVL *node);
void emOrdem(PtrNoAVL *node);

int alturaArvoreAVL(PtrNoAVL *node);
int atualizaAlturaArvoreAVL(PtrNoAVL esq, PtrNoAVL dir);

bool pesquisaArvoreAVL(PtrNoAVL *node);
void destruirArvoreAVL(PtrNoAVL *node);

void aplicarRotacoes(PtrNoAVL *node);

void rotacaoSimplesEsquerda(PtrNoAVL *node);
void rotacaoSimplesDireita(PtrNoAVL *node);
void rotacaoDuplaEsquerda(PtrNoAVL *node);
void rotacaoDuplaDireita(PtrNoAVL *node);

bool inserirArvoreAVL(PtrNoAVL *node, int x);
void imprimeArvoreAVLNivel(PtrNoAVL *node);


/******************************************************************************/
/******************************************************************************/

#endif