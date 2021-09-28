//----------------------------
/*
    @file ex02.c
    @author Bruno Uhlmann Marcato
    @date 28-09-2021
    @brief Segundo exercício da Lista_diagnostica_revisao
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    //declaração de variáveis
    FILE *arq, *new_arq;
    char c, nome_arq[21], string[300];
    int resultado, cont_linhas = 0;
    
    //solicitação do nome do arquivo
    printf("Digite o nome/caminho do arquivo: ");
    fgets(nome_arq, 21, stdin);
    nome_arq[strcspn(nome_arq, "\n")] = '\0';
    setbuf(stdin, NULL);

    //abertura do arquivo
    arq = fopen(nome_arq, "r");
    if(arq == NULL) {
        printf("falha na abertura do arquivo!");
        exit(1);
    }//if

    //ler a string do arquivo aberto e trocar todas as vogais por asteriscos
    fread(string, sizeof(char), 300, arq);	
    for(int i = 0; i < strlen(string); i++) {

        if(string[i] == 'a' || string[i] == 'A'||string[i] == 'e'||string[i] == 'E'||string[i] == 'i'||string[i] == 'I'
        ||string[i] == 'o'||string[i] == 'O'||string[i] == 'u'||string[i] == 'U') {
            string[i] = '*';
        }//if

        //contar o número de linhas do arquivo, sempre somando +1 quando encontrar uma quebra de linha (\n)
        if(string[i] == '\n') {
            cont_linhas++;
        }//if

    }//for

    //Imprimir o número de linhas do arquivo
    //Soma-se 1 a quantidade total de linhas para que seja considerada a primeira linha, já que não há uma quebra de linha para iniciá-la
    printf("O arquivo possui %d linhas.", cont_linhas + 1);
    
    //abertura do novo arquivo
    new_arq = fopen("novo_arquivo.txt", "a");
    if(new_arq == NULL) {
        printf("falha na criação do novo arquivo!");
        exit(1);
    }//if

    //escrita da nova string com asteriscos no novo arquivo aberto
    resultado = fputs(string, new_arq);
    if(resultado == EOF) {
            printf("Erro na abertura do arquivo");
            exit(1);
    }//if

    //fechamento dos arquivos
    fclose(arq);
    fclose(new_arq);

    return 0;
}//main

//----------------------------