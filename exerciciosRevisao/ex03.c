/*
    @file ex03.c
    @author Bruno Uhlmann Marcato
    @date 27-09-2021
    @brief Exercício 3 da Lista_diagnostica_revisao
*/

#include <stdio.h>
#include <stdlib.h>

//cabeçalho da função, x é a base e y o expoente
int pow(int x, int y) {
    if(y == 0) { //caso base da recursão, expoente igual a 0
        return 1;
    }//if
    //uso da recursão para multiplicar a base x por y vezes, diminuindo o valor de y a cada repetição e usando 0 como base.
    return x * pow(x, y - 1); 
}//pow

int main(void) {
    
    return 0;
}//main