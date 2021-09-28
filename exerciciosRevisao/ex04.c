/*
    @file ex04.c
    @author Bruno Uhlmann Marcato
    @date 28-09-2021
    @brief Quarto exercício da Lista_diagnostica_revisao
*/

#include <stdio.h>
#include <stdlib.h>

//cabeçalho da função, recebe o tamanho do vetor e o vetor em si como argumentos
void preencherVetor(int num_elementos,int vet[]) {
    //preenchimento do vetor
    for(int i = 0; i < num_elementos; i++) {
        printf("Digite o %d elemento do vetor: ", i+1);
        scanf("%d", &vet[i]);
    }//for
}//preencherVetor

int main(void) {
    //declaração de variáveis
    int N, *p;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &N);
    p = (int *) malloc(N*sizeof(int));//alocação dinâmica para um número N de elementos do tipo int

    preencherVetor(N, p);

    //imprimir os valores do vetor
    printf("Valores do vetor: ");
    for(int i = 0; i < N; i++) {
        printf("%d ", p[i]);
    }//for

    free(p); //liberar memória
    return 0;
}//main