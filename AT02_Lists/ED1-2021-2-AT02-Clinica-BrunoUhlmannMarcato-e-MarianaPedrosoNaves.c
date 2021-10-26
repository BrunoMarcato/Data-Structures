#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//================================================
//Definição dos registros
//================================================

typedef struct {
    int codigo; //devemos ter um campo único para o código para operações de consulta / ordenação
    char infos[301]; //como as outras informações não são utilizadas para manipulação das listas, elas serão dadas em uma única string
} Registro;


//================================================
//Definição dos TAD lista
//================================================

typedef struct NoLista *PtrNoLista;

typedef struct NoLista {
    Registro registro;
    PtrNoLista proximo;
    PtrNoLista anterior;
} NoLista;

typedef struct {
    PtrNoLista primeiro;
    PtrNoLista ultimo;
    int tamanho;
} Lista;

//================================================

//Definição das funções de manipulação/consulta da lista

//================================================

//================================================
//===============FUNÇÃO DE INICIAR================
//================================================

void iniciarLista(Lista *lista) {
    lista -> primeiro = NULL;
    lista -> tamanho = 0;
}//iniciarLista

//================================================
//===============FUNÇÃO DE VERIFICAR==============
//==================SE ESTA VAZIA=================
//================================================

bool estaVazia(Lista *lista) {
    return (lista -> tamanho == 0);
    //return (lista -> primeiro == NULL);
}//estaVazia

//================================================
//===============FUNÇÃO DE RETORNAR===============
//===================O TAMANHO====================
//===================DA LISTA=====================
//================================================

int tamanhoLista(Lista *lista) {
    return (lista -> tamanho);
}//tamanhoLista

//================================================
//===============FUNÇÃO DE IMPRIMIR===============
//===================NO ARQUIVO===================
//================================================

void imprimirLista(Lista *lista, FILE* saida) {
    PtrNoLista percorre;
    for(percorre = lista -> primeiro; percorre != NULL; percorre = percorre -> proximo) { 
        //imprime no arquivo os dados obtidos, do inicio ao final
        fprintf(saida, "{%d,%s\n", percorre -> registro.codigo, percorre -> registro.infos);
    }
}//imprimirLista

//================================================
//===============FUNÇÃO DE IMPRIMIR===============
//===================NO ARQUIVO===================
//====================INVERSA=====================
//================================================

void imprimirListaReversa(Lista *lista, FILE* saida) {
    PtrNoLista percorre;
    for(percorre = lista -> ultimo; percorre != NULL; percorre = percorre -> anterior) {
        //imprime no arquivo na ordem inversa, do final ao inicio
        fprintf(saida, "{%d,%s\n", percorre -> registro.codigo, percorre -> registro.infos);
    }
}//imprimirListaReversa

//================================================
//===============FUNÇÃO DE DESTRUIR===============
//================================================
void destruirLista(Lista *lista) {
    printf("Destruindo lista...\n");
    PtrNoLista percorre;
    for(percorre = lista -> primeiro; percorre != NULL; percorre = percorre -> proximo) {
        free(percorre);
    }
    printf("Lista destruida!\n");
}//destroyList

//================================================
//===============FUNÇÃO DE PESQUISA===============
//================================================

bool pesquisa(Lista *lista, int chave, FILE* saida) {
    if(!estaVazia(lista)) {
        PtrNoLista aux = lista -> primeiro;
        while(aux != NULL && chave > aux -> registro.codigo) {
            aux = aux -> proximo;
        }
        if(aux == NULL || aux -> registro.codigo > chave) {
            printf("Registro nao esta na lista!\n");
            fprintf(saida, "Registro não cadastrado!");
            return false;
        }
        printf("Registro encontrado!\n");
        fprintf(saida, "{%d, %s", aux-> registro.codigo, aux-> registro.infos);
        return true;
    } else {
        printf("Lista vazia!\n");
        fprintf(saida,"Lista vazia!");
        return false;
    }
}//pesquisa

//================================================
//===============FUNÇÃO DE INSERIR================
//===================NA LISTA=====================
//================================================

void inserir(Lista *lista, Registro newReg) {

    //Crie um ponteiro para listar o nó e vincular o valor passado como argumento como uma chave deste novo nó  
    PtrNoLista novoNo = (PtrNoLista)malloc(sizeof(NoLista));
    novoNo -> registro = newReg;


    //case 1: Primeiro Elemento
    if(estaVazia(lista)) {

        novoNo -> proximo = lista -> primeiro;
        novoNo -> anterior = NULL;
        lista -> primeiro = novoNo;
        lista -> ultimo = novoNo; //para a duplamente encadeada, teremos um ponteiro para o fim da lista, como se trata do primeiro elemento, ele recebe tanto o inicio quanto o fim


    } else if(newReg.codigo < lista -> primeiro -> registro.codigo) {

        //case 2: codigo passado como argumento menor que o codigo do primeiro registro na lista
        novoNo -> proximo = lista -> primeiro;
        novoNo -> anterior = lista -> primeiro -> anterior;
        lista -> primeiro -> anterior = novoNo;
        lista -> primeiro = novoNo;

    } else {

        //case 3: Não é o primeiro registro a ser inserido na lista 
        //case 3.1: O novo registro é o último a ser inserido na lista (código do registro maior que o código de todos os outros registros)
        if(newReg.codigo > lista -> ultimo -> registro.codigo) {
            PtrNoLista aux = lista -> ultimo; //O auxiliar recebe o nó que o ponteiro último aponta
            lista -> ultimo = novoNo; //O ponteiro final apontará para o novo nó
            novoNo -> proximo = NULL;
            novoNo -> anterior = aux; //O ponteiro anterior do novo nó aponta pro nó auxiliar (o antigo último nó)
            aux -> proximo = novoNo;

        } else {

            //case 3.2: Elemento intermediário (solução é praticamente a mesma da lista simplesmente encadeada pois, para esse caso, não se altera com o ponteiro que aponta pro último elemento)
            //única alteração é a manipulação do ponteiro que aponta pro nó anterior
            PtrNoLista aux = lista -> primeiro;
            while(aux -> proximo != NULL && newReg.codigo > aux -> proximo -> registro.codigo) {
                aux = aux -> proximo;
            }
            novoNo -> proximo = aux -> proximo;
            novoNo -> anterior = aux; // para a duplamente encadeada, o ponteiro anterior do novo nó aponta para o nó apontado pelo auxiliar como o ponto de "encaixe"
            aux -> proximo = novoNo;
            novoNo -> proximo -> anterior = novoNo;

        }    
    }

    //Increase the size list
    lista -> tamanho++;

}

//================================================
//===============FUNÇÃO DE REMOVER================
//===================DA LISTA=====================
//================================================

//4 casos:
//1) Lista vazia
//2) Elemento a ser removido é menor que o primeiro da lista
//3) Elemento a ser removido é o primeiro
//4) Elemento a ser removido é o primeiro e único na lista
//5) Elemento a ser removido não é o primeiro 
//  5.1) Elemento não está na lista depois de percorrer
//  5.2) Elemento está na lista depois de percorrer
//  5.2.1) Elemento é o último da lista
//  5.2.2) Elemento não é o último da lista

bool removerElemento(Lista *lista, int chave, Registro *registroRemovido) {
    //case 1 and 2
    if(estaVazia(lista) || chave < lista -> primeiro -> registro.codigo) {
        printf("Incapaz de remover o elemento (lista vazia ou elemento nao existente)\n");
        return false;     
    }
    //case 3
    if(lista -> primeiro -> registro.codigo == chave) {
        if(lista -> tamanho == 1) { //para a duplamente encadeada, devemos tratar do caso da fila ter apenas 1 elemento, afim de evitar o caso do 'anterior' do NULL apontar para NULL
            //case 4
            *registroRemovido = lista -> primeiro -> registro;
            free(lista -> primeiro);
            lista -> primeiro = NULL;
            lista -> ultimo = NULL;
            lista -> tamanho--;
            return true;
        }
        PtrNoLista aux = lista -> primeiro;
        lista -> primeiro = aux -> proximo;
        lista -> primeiro -> anterior = NULL; //para a duplamente encadeada, precisamos fazer o ponteiro 'anterior' do novo primeiro elemento apontar para NULL
        *registroRemovido = aux -> registro;
        free(aux);
        lista -> tamanho--;
        return true;
    }
    //case 5
    PtrNoLista percorre = lista -> primeiro;
    while(percorre -> proximo != NULL && (chave > percorre -> proximo -> registro.codigo)) {
        percorre = percorre -> proximo;
    }
    //case 5.1
    if(percorre == NULL || chave < percorre -> proximo -> registro.codigo) {
        printf("O elemento não existe na lista\n");
        return false;
    }
    //case 5.2
    //case 5.2.1
    PtrNoLista aux = percorre -> proximo;
    if(lista -> ultimo -> registro.codigo == chave) {
        percorre -> proximo = aux -> proximo;
        lista -> ultimo = percorre; // na duplamente encadeada, precisamos fazer o ponteiro para o final receber o elemento anterior ao que estamos retirando
        *registroRemovido = aux -> registro;
        free(aux);
    } else {
        //case 5.2.2
        percorre -> proximo = aux -> proximo;
        percorre -> proximo -> anterior = percorre;
        *registroRemovido = aux -> registro;
        free(aux);
    }
    lista -> tamanho--;
    return true;
}//removerElemento

//================================================
//======================MAIN======================
//================================================

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
    FILE *entrada = fopen(argv[1], "r");
    FILE* saida   = fopen(argv[2], "w");

    if(entrada == NULL || saida == NULL) {
        printf("Erro: algum dos arquivos nao pode ser criado corretamente!\n");
        exit(1);
    }

    //VARIÁVEIS
    Lista lista;
    Registro registro;
    int op; //código de operação
    int codPesquisa; //para caso seja a operação número 3, a variável guardará o código a ser pesquisado na lista

    //=======================================
    //INICIAR A LISTA
    //=======================================
    iniciarLista(&lista);

    char ch;
    while((ch = fgetc(entrada)) != EOF) { 

        if(ch == '{') {
            fscanf(entrada,"%d,%[^\n]\n", &registro.codigo, registro.infos); //pegar os dados dos registros
            printf("{%d,%s\n", registro.codigo, registro.infos);

            //insere na lista os dados coletados
            inserir(&lista,registro);
        } else {
            //Se não encontrar, o valor será o código de comando (1, 2 ou 3)
            if(ch == '1' || ch == '2' || ch == '3') {
                op = ch - '0'; //recebe o código de operação e converte para inteiro
                printf("Tipo de operacao: %d\n", op);
            } 

            //caso seja a operação de pesquisa, ler o próximo valor do arquivo para realizar a pesquisa
            if(op == 3) {
                fscanf(entrada, "%d", &codPesquisa);
                printf("Codigo de pesquisa: %d\n", codPesquisa);
            }
        }
    }


    switch (op) {
        case 1: //operação 1: imprimir os registros em ordem crescente de código 
            imprimirLista(&lista, saida);
            break;
        case 2: //operação 2: imprimir os registros em ordem decrescente de código
            imprimirListaReversa(&lista, saida);
            break;
        case 3: //operação 3: imprimir o registro com o código passado
            pesquisa(&lista, codPesquisa, saida);
            break;
            default:
            //caso não seja nenhuma das 3 operações válidas, exibir mensagem de erro
            printf("Codigo de operacao invalido!\n");
        }

    //fechamento dos arquivos
    fclose(entrada);
    fclose(saida);

    //destruição da lista
    destruirLista(&lista);

    return 0;
}