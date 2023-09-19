#include <stdio.h>
#include <stdlib.h>

// Definindo a estrutura para representar um Item da mochila
typedef struct {
    int pi;
    int vi;
} Item;

// Função para ler informações dos itens da mochila
void lerItens(Item *itens, int numItens) {
    for (int i = 0; i < numItens; i++) {
        printf("Digite o pi do item %d: ", i + 1);
        scanf("%d", &itens[i].pi);
        printf("Digite o vi do item %d: ", i + 1);
        scanf("%d", &itens[i].vi);
    }
}

// Função para realizar a busca local na mochila
void buscaLocal(int c, Item *itens, int numItens, int *mochila) {
    int piAtual = 0;
    int viAtual = 0;

    // Preenchendo a mochila com uma solução inicial
    for (int i = 0; i < numItens; i++) {
        if (piAtual + itens[i].pi <= c) {
            mochila[i] = 1;
            piAtual += itens[i].pi;
            viAtual += itens[i].vi;
        }
    }

    int melhoriaEncontrada = 1;
    while (melhoriaEncontrada) {
        melhoriaEncontrada = 0;

        // Percorrendo os itens na mochila e realizando movimentos para melhorar a solução
        for (int i = 0; i < numItens; i++) {
            if (mochila[i] == 1) {
                int piAnterior = piAtual;
                int viAnterior = viAtual;
                mochila[i] = 0;
                piAtual -= itens[i].pi;
                viAtual -= itens[i].vi;

                for (int j = 0; j < numItens; j++) {
                    if (mochila[j] == 0 && piAtual + itens[j].pi <= c) {
                        mochila[j] = 1;
                        piAtual += itens[j].pi;
                        viAtual += itens[j].vi;
                    }
                }

                if (viAtual > viAnterior) {
                    melhoriaEncontrada = 1;
                } else {
                    mochila[i] = 1;
                    piAtual = piAnterior;
                    viAtual = viAnterior;
                }
            }
        }
    }
}

// Função para exibir os itens na mochila e informações relevantes
void exibirItensNaMochila(int *mochila, Item *itens, int numItens) {
    printf("\nItens na mochila:\n");
    int piAtual = 0;
    int viAtual = 0;

    for (int i = 0; i < numItens; i++) {
        if (mochila[i] == 1) {
            printf("Item %d: pi = %d, vi = %d\n", i + 1, itens[i].pi, itens[i].vi);
            piAtual += itens[i].pi;
            viAtual += itens[i].vi;
        }
    }

    printf("Capacidade utilizada: %d\n", piAtual);
    printf("vi total na mochila: %d\n", viAtual);
}

int main() {
    printf("Joao Vitor Leao Marques e Paulo Ricardo Alves Faria\n\n");

    int c;
    printf("Digite a capacidade da mochila: ");
    scanf("%d", &c);

    int numItens;
    printf("Digite o número de itens: ");
    scanf("%d", &numItens);

    // Alocando memória para os itens e a mochila
    Item *itens = (Item *)malloc(numItens * sizeof(Item));
    lerItens(itens, numItens);

    int *mochila = (int *)malloc(numItens * sizeof(int));
    for (int i = 0; i < numItens; i++) {
        mochila[i] = 0;
    }

    // Realizando a busca local
    buscaLocal(c, itens, numItens, mochila);

    // Exibindo os resultados
    exibirItensNaMochila(mochila, itens, numItens);

    // Liberando memória alocada
    free(itens);
    free(mochila);

    return 0;
}