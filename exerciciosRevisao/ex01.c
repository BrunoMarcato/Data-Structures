/* -------------------------
    @file ex01.c
    @author Bruno Uhlmann Marcato
    @date 27-09-2021
    @brief Exercício 1 da lista_diagnostica_revisao 
*/

#include <stdio.h>
#include <stdlib.h>

//cabeçalho da função recebendo 3 parâmetros, sendo 2 por referência para alterar as variáveis e exibi-las formatadas
void formatarMinutoHora(int totalMinutos, int *minutos, int *horas) {
    //se o total de minutos for maior que 60, subtraia esse valor do total e some em 1 a variável horas
    //com isso teremos as duas condições sendo cumpridas
    while(totalMinutos >= 60) { 
        totalMinutos -= 60;
        ++*horas;
    }
    //a variável minutos recebe o restante dos minutos que não foram incluidos na estrutura while, caso existam.
    *minutos = totalMinutos;
}//formatarMinutoHora

int main(void) {
    //declaração de variáveis
    int minutos_totais, minutos_formatados, horas_formatadas;
    //solicitação dos minutos totais a serem formatados
    printf("Digite o total de minutos: ");
    scanf("%d", &minutos_totais);
    //chamada da função, usando o operador & para se referir ao endereço de memória das variáveis que devem ser passadas por referência
    formatarMinutoHora(minutos_totais, &minutos_formatados, &horas_formatadas);
    //exibição do total de minutos formatados
    printf("\n%dh:%dmin", horas_formatadas, minutos_formatados);
    return 0;
}//main

// -------------------------