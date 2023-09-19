/*
Autor: 202001737
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

//#define PESO_MAXIMO 120
#define TESTES_MAXIMOS 1000
#define INICIO_TEMPERATURA 1000.0
#define TAXA_TEMPERATURA 0.95

typedef struct Item{
    int valor;
    int peso;
} Item;

void solucaoInicialAleatoria(int num_itens, int *atualSolucao) {
    for (int i = 0; i < num_itens; i++) {
        atualSolucao[i] = rand() % 2; // 0 ou 1
    }
}

int calc_valorTotal(int atualSolucao[], int num_itens, int pesoMaximo, Item *itens) {
    int valorTotal = 0;
    int pesoTotal = 0;

    for (int i = 0; i < num_itens; i++) {
        if (atualSolucao[i]) {
            valorTotal += itens[i].valor;
            pesoTotal += itens[i].peso;
        }
    }

    if (pesoTotal > pesoMaximo) {
        valorTotal = 0; 
    }

    return valorTotal;
}

int calc_pesoItensEscolhidos(int atualSolucao[], int num_itens, Item *itens){
    int pesoAtual = 0;

    for(int i = 0; i < num_itens; i++){
        if (atualSolucao[i]){
            pesoAtual += itens[i].peso;
        }
    }

    return pesoAtual;
}

double probabilidadeTroca(int valorNovo, int valorAtual, double temperatura) {
    if (valorNovo > valorAtual) {
        return 1.0;
    }

    printf("Temperatura: %lf\n", temperatura);
    printf("Probabilidade: %lf\n", exp((valorNovo - valorAtual) / temperatura));

    return exp((valorNovo - valorAtual) / temperatura);
}

void solucao(int num_itens, int pesoMaximo, int *atualSolucao, Item *itens) {
    srand(time(NULL)); //seed

    solucaoInicialAleatoria(num_itens, atualSolucao);
    int solucaoFinal[num_itens]; // armazena quais itens foram escolhidos com 0 ou 1 (não ou sim)
    int valorFinal = calc_valorTotal(atualSolucao, num_itens, pesoMaximo, itens);
    int valorAtual = valorFinal;
    int pesoFinal = calc_pesoItensEscolhidos(atualSolucao, num_itens, itens); // ligma
    int pesoAtual = pesoFinal;

    // testa uma determinada quantidade de soluções com o simulated annealing
    for (int i = 0; i < TESTES_MAXIMOS; i++) {
        double temperatura = INICIO_TEMPERATURA * pow(TAXA_TEMPERATURA, i);

        // trocar valor (0 ou 1) de um índice arbitrário 
        int iRandom = rand() % num_itens;
        atualSolucao[iRandom] = 1 - atualSolucao[iRandom];

        // guardar novo valor e peso após a troca
        int valorNovo = calc_valorTotal(atualSolucao, num_itens, pesoMaximo, itens);
        int pesoNovo = calc_pesoItensEscolhidos(atualSolucao, num_itens, itens);

        // testar troca
        if (probabilidadeTroca(valorNovo, valorAtual, temperatura) > ((double)rand() / RAND_MAX)) {
            valorAtual = valorNovo;
            pesoAtual = pesoNovo;

            // caso a solução seja melhor que uma solução anterior
            if (valorAtual > valorFinal) {
                valorFinal = valorAtual;
                pesoFinal = pesoAtual;
                for (int j = 0; j < num_itens; j++) {
                    solucaoFinal[j] = atualSolucao[j];
                }
            }
        } else {
            // desfaz a troca
            atualSolucao[iRandom] = 1 - atualSolucao[iRandom];
        }
    }

    printf("\n===== Solucao encontrada! =====\n");
    printf("Valor Final: %d\n", valorFinal);
    printf("Peso Final: %d\n", pesoFinal);
    printf("Peso maximo da mochila: %d\n\n", pesoMaximo);
    printf(" __________________________________________________\n");
    printf("|   Item   |   Escolhido?   |   Valor   |   Peso   |\n");
    printf("|__________|________________|___________|__________|\n");
    for (int i = 0; i < num_itens; i++) {
        if (solucaoFinal[i] == 1) { 
            printf("|    %d     |      sim       |    %d     |    %d    |\n", i + 1, itens[i].valor, itens[i].peso);
        } else {
            printf("|    %d     |      nao       |    %d     |    %d    |\n", i + 1, itens[i].valor, itens[i].peso);
        }
    }
    printf("|__________|________________|___________|__________|\n");

}

int main() {

    int num_itens, pesoMaximo;
    int valor, peso;
    scanf("%d %d\n", &num_itens, &pesoMaximo);
    
    // alocar vetor
    int *atualSolucao = malloc(num_itens * sizeof(*atualSolucao));
    if (!atualSolucao) {
        printf("Houve um problema com o malloc.");
        exit(EXIT_FAILURE);
    }

    // valor e peso de cada item
    Item itens[num_itens];
    for (int i = 0; i < num_itens; i++) {
            scanf("%d %d\n", &valor, &peso);

            itens[i].valor = valor;
            itens[i].peso = peso;
    }

    solucao(num_itens, pesoMaximo, atualSolucao, itens);

    return 0;
}