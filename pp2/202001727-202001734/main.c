// 202001727-202001734

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Estrutura para representar um item da mochila
typedef struct {
  int weight;
  int value;
} Item;

// Função de comparação para ordenar os itens pelo valor-peso (valor dividido pelo peso)
int compare(const void *a, const void *b) {
  // Faz o cast dos itens
  Item *itemA = (Item *)a;
  Item *itemB = (Item *)b;

  // Calcula a relação entre (valor/peso)
  double ratioA = (double)itemA->value / itemA->weight;
  double ratioB = (double)itemB->value / itemB->weight;

  // Verifica se a taxa do item A é maior que do B
  if (ratioA > ratioB)
    return -1;
  else if (ratioA < ratioB)
    return 1;
  return 0;
}

// Função para resolver o problema da mochila usando o método GRASP
int solveKnapsackGRASP(Item items[], int n, int capacity, int maxIterations) {
  /*
    Alloca um array de inteiro. O mesmo será utilizado para armazenar a melhor solução.
    Ex.: Será colocado o número 1 na posição de cada item pegado.
  */
  int *bestSolution = (int *)calloc(n, sizeof(int));
  int bestValue = 0;  // Melhor valor

  /*
    Faz várias tentativas com o objetivo de tentar pegar uma solução melhor do que a existente.
    Porém as tentativas estão limitadas a um valor.
  */
  for (int iter = 0; iter < maxIterations; iter++) {
    /*
      Alloca um array de inteiro. O mesmo será utilizado para armazenar a solução atual.
      Ex.: Será colocado o número 1 na posição de cada item pegado.
    */
    int *currentSolution = (int *)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
      /*
        Para incluir um item aleatório na mochila poderia apenas utilizar "rand() % 2",
        porém não é um método muito eficaz.
      */
      double randomValue = (double)rand() / RAND_MAX;  // Randomiza um valor entre 0 e 1
      double inclusionProbability = 0.5;               // Define um valor para a probabilidade de inclusão

      /*
        Se o valor aleatório for menor que a probabilidade de inclusão o item é pegado.
        Obs.: Não será pego itens repitidos.
      */
      if (randomValue < inclusionProbability) {
        // Verifica se o valor do item é menor ou igual que a capacidade atual da mochila
        if (items[i].weight <= capacity) {
          currentSolution[i] = 1;       // Marca a posição do item pegado
          capacity -= items[i].weight;  // Decrementa a capacidade da mochila
        }
      }
    }

    // Calcula o valor da solução atual
    int currentValue = 0;
    for (int i = 0; i < n; i++) {
      if (currentSolution[i])
        currentValue += items[i].value;
    }

    // Atualiza a melhor solução se a atual for melhor
    if (currentValue > bestValue) {
      bestValue = currentValue;
      for (int i = 0; i < n; i++) {
        bestSolution[i] = currentSolution[i];
      }
    }

    free(currentSolution);
  }

  // Exibe a melhor solução
  printf("Melhor solução (peso, valor): ");
  for (int i = 0; i < n; i++) {
    if (bestSolution[i]) {
      printf("(%d, %d), ", items[i].weight, items[i].value);
    }
  }
  printf("\n");

  free(bestSolution);
  return bestValue;
}

int main() {
  srand(time(NULL));  // Muda a seed

  Item items[] = {{2, 10}, {3, 5}, {5, 15}, {7, 7}, {1, 6}, {4, 18}, {1, 3}};  // Itens para serem pegados {peso, valor}

  int n = sizeof(items) / sizeof(items[0]);  // Quantidade total de itens para serem pegados
  int capacity = 15;                         // Capacidade da mochila
  int maxIterations = 1000;                  // Limite de interações

  qsort(items, n, sizeof(Item), compare);  // Orderna os itens por (valor/peso)

  int maxValue = solveKnapsackGRASP(items, n, capacity, maxIterations);  // Solução utilizando GRASP

  printf("Valor máximo da mochila: %d\n", maxValue);
  return 0;
}
