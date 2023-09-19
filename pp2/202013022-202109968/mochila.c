//Alunos: 202013022-202109968
//Segue o codigo em C que resolve o problema da mochila.
//-----------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ITEMS 5

typedef struct {
    int weight;
    int value;
} Item;

int totalValue(Item items[], int selection[]) {
    int total = 0;
    for (int i = 0; i < NUM_ITEMS; i++) {
        if (selection[i]) {
            total += items[i].value;
        }
    }
    return total;
}

int totalWeight(Item items[], int selection[]) {
    int total = 0;
    for (int i = 0; i < NUM_ITEMS; i++) {
        if (selection[i]) {
            total += items[i].weight;
        }
    }
    return total;
}

void localSearch(Item items[], int knapsackCapacity) {
    int selection[NUM_ITEMS];
    srand(time(NULL));

    for (int i = 0; i < NUM_ITEMS; i++) {
        selection[i] = rand() % 2;
    }

    int iterations = 1000;
    for (int k = 0; k < iterations; k++) {
        int bestValue = totalValue(items, selection);
        int bestNeighbor[NUM_ITEMS];

        int randomItem = rand() % NUM_ITEMS;
        for (int i = 0; i < NUM_ITEMS; i++) {
            int neighbor[NUM_ITEMS];
            for (int m = 0; m < NUM_ITEMS; m++) {
                neighbor[m] = selection[m];
            }
            neighbor[randomItem] = !neighbor[randomItem];
            int newValue = totalValue(items, neighbor);

            if (newValue > bestValue) {
                int totalWeightNeighbor = totalWeight(items, neighbor);
                if (totalWeightNeighbor <= knapsackCapacity) {
                    bestValue = newValue;
                    for (int p = 0; p < NUM_ITEMS; p++) {
                        bestNeighbor[p] = neighbor[p];
                    }
                }
            }
        }

        for (int q = 0; q < NUM_ITEMS; q++) {
            selection[q] = bestNeighbor[q];
        }
    }

    printf("Selected items: ");
    for (int r = 0; r < NUM_ITEMS; r++) {
        printf("%d ", selection[r]);
    }
    printf("\nTotal value: %d\n", totalValue(items, selection));
    printf("Total weight: %d\n", totalWeight(items, selection));
}

int main() {
    Item items[NUM_ITEMS] = {{2, 10}, {3, 5}, {5, 15}, {7, 7}, {1, 6}};
    int knapsackCapacity = 10;

    localSearch(items, knapsackCapacity);

    return 0;
}
