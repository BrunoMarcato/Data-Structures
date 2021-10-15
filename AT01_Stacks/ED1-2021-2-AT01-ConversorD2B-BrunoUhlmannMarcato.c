#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAXTAM 100

//Definição Pilha Estática
typedef struct {
    int array[MAXTAM];
    int topo;
} PilhaEstatica;


//Definição Pilha Dinâmica
typedef struct NoPilha *PtrNoPilha;

typedef struct NoPilha{
  int chave;
  PtrNoPilha proximo;
} NoPilha;

typedef struct {
  PtrNoPilha topo;
  int tamanho;
} PilhaDinamica;


//Funções de manipulação/Consulta da Pilha Estática
//------------------------------------------------
//------------------------------------------------

//Iniciar a Pilha Estática
void iniciaEstatica(PilhaEstatica *pilha) {
    pilha -> topo = 0;
}//iniciaEstatica

//------------------------------------------------
//------------------------------------------------

//Verificar se a pilha está vazia (retorna true se a pilha estiver com o topo na primeira posição do vetor)
bool estaVaziaEstatica(PilhaEstatica *pilha) {
    return (pilha -> topo == 0);
}//estaVaziaEstatica

//------------------------------------------------
//------------------------------------------------

//Verificar se a pilha está cheia (retorna true se a pilha atingiu MAXTAM)
bool estaCheiaEstatica(PilhaEstatica *pilha) {
    return (pilha -> topo == MAXTAM);
}//estaCheiaEstatica

//------------------------------------------------
//------------------------------------------------

// 1) Verificar se a pilha está cheia;
//   1.1) Se sim, imprima um Warning na tela (pois não é possível inserir mais elementos em uma pilha(vetor) que já tem todos os campos preenchidos);
//   1.2) Se não, inicia (2);
// 2) A posição da pilha indicada pelo topo recebe o valor passado pelo usuário;
// 3) Incrementa-se o topo para que ele indique a próxima posição da pilha.

void empilhaEstatica(int item, PilhaEstatica *pilha) {

    if(!estaCheiaEstatica(pilha)) {
        pilha -> array[pilha -> topo] = item;
        pilha -> topo++;
    } else {
        printf("Warning: A pilha ja esta cheia!\n");
    }
}//empilhaEstatica

//------------------------------------------------
//------------------------------------------------

// 1) Criar uma variável auxiliar (int) (ela deve receber algum valor na declaração para o caso de não ser alterada durante a execução, pois será retornada ao final da função);
// 2) Verificar se a pilha está vazia;
//   2.1) Se sim, imprima um Warning na tela (pois não é possível remover elementos de uma pilha que não possui elemento algum);
//   2.2) Se não, inicia (3);
// 3) A variável auxiliar recebe o valor da pilha indicada pela posição anterior ao topo (pois ele está sempre uma posição a frente da última casa preenchida);
// 4) Decrementa-se o topo para invalidar a posição da pilha que está sendo removida;
// 5) Retorna o valor da variável auxiliar (que guardou o valor da posição removida).

int desempilhaEstatica(PilhaEstatica *pilha) {

    int aux = -9999;

    if(!estaVaziaEstatica(pilha)) {
        aux = pilha -> array[pilha -> topo - 1];
        pilha -> topo--;
    } else {
        printf("Warning: A pilha ja esta vazia!\n");
    }

    return aux;
}//desempilhaEstatica

//------------------------------------------------
//------------------------------------------------

int tamanhoPilhaEstatica(PilhaEstatica *pilha) {
    return (pilha -> topo);
}//tamanhoPilhaEstatica

//------------------------------------------------
//------------------------------------------------

void printStack(PilhaEstatica *pilha) {
    printf("{ ");
    for(int i = 0; i < pilha -> topo; i++) {
        printf("%d ", pilha -> array[i]);
    }//for
    printf("}\n");
}//printStack




//Funções de manipulação/Consulta da Pilha Dinâmica
//------------------------------------------------
//------------------------------------------------

//iniciar a Pilha Dinâmica
void iniciaDinamica(PilhaDinamica *pilha) {
    pilha -> topo = NULL;
    pilha -> tamanho = 0;
}//iniciaDinamica

//------------------------------------------------
//------------------------------------------------

//Verifica se a pilha está vazia (retorna true se o tamanho for 0)
bool estaVaziaDinamica(PilhaDinamica *pilha) {
    return (pilha -> tamanho == 0);
}//estaVaziaDinamica

//------------------------------------------------
//------------------------------------------------

// 1) Criar um nó de pilha auxiliar e alocar memória para ele;
// 2) A chave do nó auxiliar recebe o valor passado para o usuário e aponta para o nó apontado pelo topo;
// 3) O topo da pilha aponta para o novo nó;
// 4) Incrementa-se o tamanho da pilha

void empilhaDinamica(int item, PilhaDinamica *pilha) {
    PtrNoPilha aux = (PtrNoPilha) malloc(sizeof(NoPilha));
    aux -> chave = item;
    aux -> proximo  = pilha -> topo;
    pilha -> topo = aux;
    pilha -> tamanho++;
}//empilhaDinamica

//------------------------------------------------
//------------------------------------------------

// 1) Criar uma variável de retorno na qual recebe um valor na declaração para o caso dela não ser alterada durante a execução da função;
// 2) Verifica se a pilha está vazia:
//    2.1) Se sim, imprima um de warning (pois não é possível remover elementos de uma pilha que não possui elemento algum);
//    2.2) Se não, inicia (3);
// 3) Cria um nó de pilha auxiliar que irá receber o nó apontado pelo topo;
// 4) O topo aponta para o próximo nó ;
// 5) Libera-se a memória alocada pela variável auxiliar e decrementa-se o tamanho da pilha.

int desempilhaDinamica(PilhaDinamica *pilha) {
    int ret = -9999;

    if(!estaVaziaDinamica(pilha)) {
        PtrNoPilha aux = pilha -> topo;
        pilha -> topo = aux -> proximo;
        ret = aux -> chave;
        free(aux);
        pilha -> tamanho--;
    } else {
        printf("Warning: A pilha já está vazia!");
    }

    return ret;
}//desempilhaDinamica

//------------------------------------------------
//------------------------------------------------

// 1) Criar um nó de pilha para percorrer por toda a pilha usando um loop;
// 2) A cada iteração do loop, desaloca-se a memória do nó atual.
void destruirPilha(PilhaDinamica *pilha) {
    printf("Destruindo pilha...\n");

    while(!estaVaziaDinamica(pilha)) {
        desempilhaDinamica(pilha);
    }

}//destruirPilha

//------------------------------------------------
//------------------------------------------------

int tamanhoPilhaDinamica(PilhaDinamica *pilha) {
    return (pilha -> tamanho);
}//tamanhoPilhaDinamica

//------------------------------------------------
//------------------------------------------------
//--FUNÇÕES DE TRANSFORMAÇÃO DECIMAL PRA BINÁRIO--
//------------------------------------------------
//------------------------------------------------

void DecToBinEstatica(FILE* entrada, FILE* saida) {


    //============DECLARAÇÃO DE VARIÁVEIS=====================
    PilhaEstatica PilhaEstaticaDTB;//pilha para manipulação do D2B
    PilhaEstatica PilhaEstaticaArq;//pilha para impressão no arquivo na ordem contrária
    float nf; //variável para testar se o número lido do arquivo é float ou int
    int ni, resto, desempilhado; //ni = converter o número lido para inteiro; resto = recebe o resto da divisão na conversão de decimal pra binário; desempilhado = recebe o valor desempilhado da pilha
    //========================================================


    iniciaEstatica(&PilhaEstaticaArq);

    while(!feof(entrada)) {
        fscanf(entrada, "%f", &nf);
        if(nf == (int)nf && nf >= 0) {//se a conversão do float para int for igual ao float original, então n já era int e portanto válido
            ni = (int)nf; //converter o float para int
            //inicialização da pilha estática de conversão
            iniciaEstatica(&PilhaEstaticaDTB);
            //converter o inteiro decimal n para binário e empilhar os digitos
            if(ni == 0) {
                empilhaEstatica(ni, &PilhaEstaticaArq);
            } else {
                while(ni > 0) {
                    resto = ni % 2;
                    ni /= 2;
                    empilhaEstatica(resto, &PilhaEstaticaDTB);
                }

                //colocar os números binários na pilha de troca de ordem
                int tam = tamanhoPilhaEstatica(&PilhaEstaticaDTB); //tamanho da pilha
                int numerosDesempilhados = 0; //variável para transformar todos os valores desempilhados em um único número 
                while(!estaVaziaEstatica(&PilhaEstaticaDTB)) {
                    desempilhado = desempilhaEstatica(&PilhaEstaticaDTB);
                    numerosDesempilhados += desempilhado * pow(10, tam-1); //detecta se o valor é uma unidade/dezena/centena/... (imaginando o binário como se fosse um decimal)
                    tam -= 1;
                }
                empilhaEstatica(numerosDesempilhados, &PilhaEstaticaArq); //empilha o binário na pilha de troca de ordem
                numerosDesempilhados = 0; //reseta o valor pra 0
            }

        } else printf("Erro! %.1f e um valor invalido!!\nOs outros valores ainda serao exibidos...\n\n", nf); //warning para caso o valor seja negativo ou não inteiro
    }

    //desempilhar os valores da pilha de troca de ordem e imprimir no arquivo de saída
    while(!estaVaziaEstatica(&PilhaEstaticaArq)) {
        desempilhado = desempilhaEstatica(&PilhaEstaticaArq);
        fprintf(saida, "%d\n", desempilhado);
    }
}//DecToBinEstatica

//------------------------------------------------
//------------------------------------------------

void DecToBinDinamica(FILE* entrada, FILE* saida) {


    //============DECLARAÇÃO DE VARIÁVEIS=====================
    PilhaDinamica PilhaDinamicaDTB;//pilha para manipulação do D2B
    PilhaEstatica PilhaDinamicaArq;//pilha para impressão no arquivo na ordem contrária
    float nf; //variável para testar se o número lido do arquivo é float ou int
    int ni, resto, desempilhado; //ni = converter o número lido para inteiro; resto = recebe o resto da divisão na conversão de decimal pra binário; desempilhado = recebe o valor desempilhado da pilha
    //========================================================


    iniciaDinamica(&PilhaDinamicaArq);

    while(!feof(entrada)) {
        fscanf(entrada, "%f", &nf);
        if(nf == (int)nf && nf >= 0) {//se a conversão do float para int for igual ao float original, então n já era int e portanto válido
            ni = (int)nf; //converter o float para int
            //inicialização da pilha estática de conversão
            iniciaDinamica(&PilhaDinamicaDTB);
            //converter o inteiro decimal n para binário e empilhar os digitos
            if(ni == 0) {
                empilhaDinamica(ni, &PilhaDinamicaArq);
            } else {
                while(ni > 0) {
                    resto = ni % 2;
                    ni /= 2;
                    empilhaDinamica(resto, &PilhaDinamicaDTB);
                }

                //colocar os números binários na pilha de troca de ordem
                int tam = tamanhoPilhaDinamica(&PilhaDinamicaDTB); //tamanho da pilha
                int numerosDesempilhados = 0; //variável para transformar todos os valores desempilhados em um único número 
                while(!estaVaziaDinamica(&PilhaDinamicaDTB)) {
                    desempilhado = desempilhaDinamica(&PilhaDinamicaDTB);
                    numerosDesempilhados += desempilhado * pow(10, tam-1); //detecta se o valor é uma unidade/dezena/centena/... (imaginando o binário como se fosse um decimal)
                    tam -= 1;
                }
                empilhaDinamica(numerosDesempilhados, &PilhaDinamicaArq); //empilha o binário na pilha de troca de ordem
                numerosDesempilhados = 0; //reseta o valor pra 0
            }

        } else printf("Erro! %.1f e um valor invalido!!\nOs outros valores ainda serao exibidos...\n\n", nf); //warning para caso o valor seja negativo ou não inteiro
    }

    //desempilhar os valores da pilha de troca de ordem e imprimir no arquivo de saída
    while(!estaVaziaDinamica(&PilhaDinamicaArq)) {
        desempilhado = desempilhaDinamica(&PilhaDinamicaArq);
        fprintf(saida, "%d\n", desempilhado);
    }

    //destruição das pilhas dinâmicas
    destruirPilha(&PilhaDinamicaDTB);
    destruirPilha(&PilhaDinamicaArq);
    
}//DecToBinDinamica

//------------------------------------------------
//------------------------------------------------

//-------------------------------------------------
//--------------------MAIN-------------------------
//-------------------------------------------------

int main(int argc, const char * argv[]) {

    // usando o argc 
    printf("Numero de parametros fornecidos: %d\n", argc);

    if(argc != 3) { 
        printf("Quantidade de parametros invalida!\n");
        return 0;
    }  

    int i = 0;
    for(i = 0; i < argc; i++) {
        printf("argv[%d] = %s\n", i, argv[i]);
    }

    // abertura dos arquivos
    FILE* entrada = fopen("entrada01.txt", "r");
    FILE* saida   = fopen("saida01.txt", "w");

    if(entrada == NULL || saida == NULL) {
        printf("Erro: algum dos arquivos não pode ser criado corretamente!\n");
        exit(1);
    }

    char ch;
    while((ch = fgetc(entrada)) != EOF) {
        switch (ch) {
            case 'e':
                DecToBinEstatica(argv[1], argv[2]); //chamando a função de conversão pra pilha estática
                return 0;
            case 'd':
                DecToBinEstatica(argv[1], argv[2]); //chamando a função de conversão pra pilha dinâmica
                return 0;

            case '\n':
                continue; //caso encontre um '\n' apenas continue o loop

            default:
                printf("Modo de criacao de pilha invalido!\n");
                return 0;
        }
    }

    //fechamento dos arquivos
    fclose(entrada);
    fclose(saida);



    return 0;
}//main

//---------------FIM DE PROGRAMA----------------------------