#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
//-------------------------------------------------

//Iniciar a Pilha
void iniciaPilha(PilhaEstatica *pilha) {
    pilha -> topo = 0;
}//iniciaPilha

//-------------------------------------------------

//Verificar se a pilha está vazia (retorna true se a pilha estiver com o topo na primeira posição do vetor)
bool estaVazia(PilhaEstatica *pilha) {
    return (pilha -> topo == 0);
}//bool

//-------------------------------------------------

//Verificar se a pilha está cheia (retorna true se a pilha atingiu MAXTAM - 1, pois se trata de um vetor)
bool estaCheia(PilhaEstatica *pilha) {
    return (pilha -> topo == MAXTAM);
}//estaCheia

//-------------------------------------------------
// 1) Verificar se a pilha está cheia;
//   1.1) Se sim, imprima um Warning na tela (pois não é possível inserir mais elementos em uma pilha(vetor) que já tem todos os campos preenchidos);
//   1.2) Se não, inicia (2);
// 2) A posição da pilha indicada pelo topo recebe o valor passado pelo usuário;
// 3) Incrementa-se o topo para que ele indique a próxima posição da pilha.

void empilhaEstatica(int item, PilhaEstatica *pilha) {

    if(!isFull(pilha)) {
        pilha -> array[pilha -> topo] = item;
        pilha -> topo++;
    } else {
        printf("Warning: A pilha já está cheia!\n");
    }
}//empilhaEstatica

//-------------------------------------------------
// 1) Criar uma variável auxiliar (int) (ela deve receber algum valor na declaração para o caso de não ser alterada durante a execução, pois será retornada ao final da função);
// 2) Verificar se a pilha está vazia;
//   2.1) Se sim, imprima um Warning na tela (pois não é possível remover elementos de uma pilha(vetor) que não possui elemento algum);
//   2.2) Se não, inicia (3);
// 3) A variável auxiliar recebe o valor da pilha indicada pela posição anterior ao topo (pois ele está sempre uma posição a frente da última casa preenchida);
// 4) Decrementa-se o topo para invalidar a posição da pilha que está sendo removida;
// 5) Retorna o valor da variável auxiliar (que guardou o valor da posição removida).

int desempilharEstatica(PilhaEstatica *pilha) {

    int aux = -9999;

    if(!isEmpty(pilha)) {
        aux = pilha -> array[pilha -> topo - 1];
        pilha -> topo--;
    } else {
        printf("Warning: A pilha está vazia!\n");
    }

    return aux;
}//desempilhaEstatica

//-------------------------------------------------











//Funções de manipulação/Consulta da Pilha Dinâmica
//-------------------------------------------------






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

  FILE* entrada = fopen(argv[1], "r");
  FILE* saida   = fopen(argv[2], "w");

  // checar erros de abertura de arquivo
  if(entrada == NULL || saida == NULL) {
     printf("Erro: algum dos arquivos não pode ser criado corretamente\n");
     return 0;
  }

  char ch;
  while(!feof(entrada)) {
    // obtendo caracter do arquivo de entrada
    ch = fgetc(entrada);
    // escrever esse caracter no arquivo de saida (que vai ser criado)
    fprintf(saida, "%c", ch);
  }

  fclose(entrada);
  fclose(saida);
  // chamar o destrutor da pilha dinamica
  return 0;
}