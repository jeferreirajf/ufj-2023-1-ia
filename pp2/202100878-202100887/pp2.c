// 202100878, 202100887
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITENS 100

typedef struct {
    int peso;
    int valor;
} Item;

int calcular_valor(Item itens[], int solucao[], int num_itens) {
    int valor_total = 0;
    for (int i = 0; i < num_itens; i++) {
        valor_total += solucao[i] * itens[i].valor;
    }
    return valor_total;
}

void buscar_melhor_solucao(Item itens[], int solucao[], int num_itens, int capacidade_mochila) {
    int valor_total = 0;
    int pesos_totais = 0;

    for (int i = 0; i < num_itens - 1; i++) {
        for (int j = 0; j < num_itens - i - 1; j++) {
            float razao1 = (float)itens[j].valor / itens[j].peso;
            float razao2 = (float)itens[j + 1].valor / itens[j + 1].peso;
            if (razao1 < razao2) {
                Item temp = itens[j];
                itens[j] = itens[j + 1];
                itens[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < num_itens; i++) {
        if (pesos_totais + itens[i].peso <= capacidade_mochila) {
            solucao[i] = 1;
            pesos_totais += itens[i].peso;
            valor_total += itens[i].valor;
        } else {
            solucao[i] = 0;
        }
    }
}


int main() {
    Item itens[MAX_ITENS];
    int solucao[MAX_ITENS];
    int capacidade_mochila, num_itens;

  
    capacidade_mochila = 10;
    num_itens = 5;
    itens[0].peso = 3;
    itens[1].peso = 1;
    itens[2].peso = 5;
    itens[3].peso = 2;
    itens[4].peso = 4;

    itens[0].valor = 4;
    itens[1].valor = 2;
    itens[2].valor = 6;
    itens[3].valor = 3;
    itens[4].valor = 5;

  
    buscar_melhor_solucao(itens, solucao, num_itens, capacidade_mochila);


   



    printf("\nItens selecionados:\n");
    for (int i = 0; i < num_itens; i++) {
        if (solucao[i]) {
            printf("Item %d (Peso: %d, Valor: %d)\n", i + 1, itens[i].peso, itens[i].valor);
        }
    }

    int valor_total = calcular_valor(itens, solucao, num_itens);
    printf("\nValor máximo obtido: %d\n", valor_total);

    return 0;
}
