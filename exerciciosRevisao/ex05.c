/*
    @file ex05.c
    @author Bruno Marcato
    @date 27-09-2021
    @brief Exercício 5 da Lista_diagnostica_revisao
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>

typedef struct {
    char nome[51];
    char tipo_musica[21];
    int num_integrantes;
    int ranking;
} Banda;

//cabeçalho da função para preencher as infos das bandas, recebe o vetor de bandas como parâmetro
void preencherBandas(int n, Banda bands[]) {
    for(int i = 0; i < n; i++) {

        //Informar o nome da banda
        printf("\n-------------------\n");
        printf("Nome da %d banda:", i+1);
        fgets(bands[i].nome, 51, stdin);
        bands[i].nome[strcspn(bands[i].nome, "\n")] = '\0';
        setbuf(stdin, NULL);

        //Informar o tipo de musica que a banda toca
        printf("Tipo da %d banda: ", i+1);
        fgets(bands[i].tipo_musica, 51, stdin);
        bands[i].tipo_musica[strcspn(bands[i].tipo_musica, "\n")] = '\0';
        setbuf(stdin, NULL);

        //Informar o número de integrantes da banda
        printf("Numero de integrantes da %d banda: ", i+1);
        scanf("%d", &bands[i].num_integrantes);
        setbuf(stdin, NULL);

        //Informar o ranking da banda
        printf("Ranking atual da %d banda: ", i+1);
        scanf("%d", &bands[i].ranking);
        setbuf(stdin, NULL);
    }//for
}//preencherBandas

//cabeçalho da função para exibir as infos das bandas, recebe o vetor de bandas como parâmetro
void exibirBandas(int n, Banda bands[]) {
    for(int i = 0; i < n; i++) {

        //exibir as informações
        printf("\n=========%d banda========\n", i+1);
        printf("Nome: %s\n", bands[i].nome);
        printf("Tipo de música: %s\n", bands[i].tipo_musica);
        printf("Número de integrantes: %d\n", bands[i].num_integrantes);
        printf("Ranking: %d\n", bands[i].ranking);

    }//for
}//exibirBandas

void infoBandas(int rank, int n, Banda bands[]) {
    for(int i = 0; i < n; i++) {
        if(bands[i].ranking == rank) {
            printf("================\n");
            printf("Nome: %s\n", bands[i].nome);
            printf("Tipo de música: %s\n", bands[i].tipo_musica);
            printf("Número de integrantes: %d\n", bands[i].num_integrantes);
        }//if
    }//for
}//infoBandas

int main(void) {
    setlocale(LC_ALL, "Portuguese");

    //Declaração do vetor de bandas
    Banda bandas[5];
    int ranking;

    //chamar a função para preencher os campos das structs
    preencherBandas(5, bandas);

    //exibir os campos das structs
    printf("Exibindo as informações...");
    sleep(3);
    exibirBandas(5, bandas);

    printf("\n\nRanking da banda para pesquisar infos: ");
    scanf("%d", &ranking);
    infoBandas(ranking, 5, bandas);

    return 0;
}//main