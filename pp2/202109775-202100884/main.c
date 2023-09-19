#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*Alunos: 202109775-202100884*/

int peso_max(int C, int N, int p1[], int v1[], int seleciona[]) { // Calcula o valor m�ximo alcan�avel dos itens
    int peso_total = 0;                                           // respeitando o limite de peso da mochila
    int valor_total = 0;

    for (int i = 0; i < N; i++) {
        if (seleciona[i]) {
            peso_total += p1[i];
            valor_total += v1[i];
        }
    }

    for (int i = 0; i < N; i++) {
        if (!seleciona[i] && peso_total + p1[i] <= C) {
            int new_peso = peso_total + p1[i];
            int new_valor = valor_total + v1[i];

            if (new_valor > valor_total) {
                peso_total = new_peso;
                valor_total = new_valor;
                seleciona[i] = 1;
            }
        }
    }

    return valor_total;
}

int main() {
    int C = 20; // Capacidade da mochila
    int N = 6; // N�mero de itens

    // Peso e valor para cada item
    int p1[] = {5, 7, 4, 5, 2, 1}; // Peso dos itens
    int v1[] = {8, 4, 5, 6, 3, 1}; // Valor dos itens

    int seleciona[N]; // Vetor para armazenar se cada item est� selecionado (1) ou n�o (0)
    for (int i = 0; i < N; i++)
        seleciona[i] = 0;

    srand(time(NULL));

    int interacoes = 1000; // N�mero de intera��es
    int melhor_valor = 0;

    for (int iter = 0; iter < interacoes; iter++) {
        int item = rand() % N;
        seleciona[item] = 1;

        int valor = peso_max(C, N, p1, v1, seleciona);

        if (valor > melhor_valor) {
            melhor_valor = valor;
        } else {
            seleciona[item] = 0;
        }
    }

    printf("Informa��es dos itens selecionados:\n", setlocale(LC_ALL,""));
    for (int i = 0; i < N; i++) {
        if (seleciona[i]) {
            printf("Item %d - Peso: %d, Valor: %d\n", i + 1, p1[i], v1[i]);
        }
    }

    printf("\nValor total: %d\n", melhor_valor);

    return 0;
}
