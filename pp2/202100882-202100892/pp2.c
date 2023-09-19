#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ITENS 100
#define PESO_MAXIMO 1000
#define MAX_ITERACOES 1000

typedef struct {
    int peso;
    int valor;
} Item;

void inicializarItens(Item itens[], int n) {
    for (int i = 0; i < n; i++) {
        itens[i].peso = rand() % 50 + 1;
        itens[i].valor = rand() % 100 + 1;
    }
}

int calcularValorMochila(Item itens[], int n, int solucao[]) {
    int valorTotal = 0;
    for (int i = 0; i < n; i++) {
        valorTotal += solucao[i] * itens[i].valor;
    }
    return valorTotal;
}

int calcularPesoMochila(Item itens[], int n, int solucao[]) {
    int pesoTotal = 0;
    for (int i = 0; i < n; i++) {
        pesoTotal += solucao[i] * itens[i].peso;
    }
    return pesoTotal;
}

void hillClimbingMochila(Item itens[], int n, int capacidade) {
    int solucaoAtual[MAX_ITENS];
    int melhorSolucao[MAX_ITENS];
    int pesoAtual = 0;
    int valorAtual = 0;
    int melhorValor = 0;

    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        if (pesoAtual + itens[i].peso <= capacidade) {
            solucaoAtual[i] = rand() % 2;
            pesoAtual += solucaoAtual[i] * itens[i].peso;
            valorAtual += solucaoAtual[i] * itens[i].valor;
        } else {
            solucaoAtual[i] = 0;
        }
    }

    for (int iteracao = 0; iteracao < MAX_ITERACOES; iteracao++) {
        int vizinho[MAX_ITENS];
        for (int i = 0; i < n; i++) {
            vizinho[i] = solucaoAtual[i];
        }
        
        int itemAleatorio = rand() % n;
        vizinho[itemAleatorio] = 1 - vizinho[itemAleatorio];

        int pesoVizinho = calcularPesoMochila(itens, n, vizinho);

        if (pesoVizinho <= capacidade) {
            int valorVizinho = calcularValorMochila(itens, n, vizinho);

            if (valorVizinho > melhorValor) {
                for (int i = 0; i < n; i++) {
                    solucaoAtual[i] = vizinho[i];
                }
                valorAtual = valorVizinho;
                pesoAtual = pesoVizinho;
                melhorValor = valorAtual;
            }
        }
    }

    printf("\nItens disponíveis na casa:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d - Peso: %d, Valor: %d\n", i + 1, itens[i].peso, itens[i].valor);
    }
    
    printf("\nUma melhor solução:\n");
    for (int i = 0; i < n; i++) {
        if (solucaoAtual[i] == 1) {
            printf("Item %d - Peso: %d, Valor: %d\n", i + 1, itens[i].peso, itens[i].valor);
        }
    }
    printf("Valor total dos itens na melhor solução: %d\n", melhorValor);
    printf("Peso total dos itens na melhor solução: %d\n", calcularPesoMochila(itens, n, solucaoAtual));
}

int main() {
    int n;
    int capacidade = 80;
    printf("A capacidade da mochila é %d\n", capacidade);
    printf("Digite o número de itens disponíveis na casa: ");
    scanf("%d", &n);

    if (n > MAX_ITENS || capacidade > PESO_MAXIMO) {
        printf("A quantidade de itens não pode ser maior que 100, tente novamente com um valor menor.\n");
        return 1;
    }

    Item itens[MAX_ITENS];
    inicializarItens(itens, n);

    hillClimbingMochila(itens, n, capacidade);

    return 0;
}
