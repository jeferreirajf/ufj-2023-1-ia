#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Item {
    int weight;
    int value;
};

int knapsackValue(const vector<Item>& items, const vector<bool>& solution) {
    int totalValue = 0;
    for (int i = 0; i < items.size(); ++i) {
        if (solution[i]) {
            totalValue += items[i].value;
        }
    }
    return totalValue;
}
int totalWeight(const vector<bool>& solution, const vector<Item>& items) {
    int weight = 0;
    for (int i = 0; i < items.size(); ++i) {
        if (solution[i]) {
            weight += items[i].weight;
        }
    }
    return weight;
}

vector<bool> randomSolution(int numItems) {
    vector<bool> solution(numItems);
    for (int i = 0; i < numItems; ++i) {
        solution[i] = rand() % 2;
    }
    return solution;
}

vector<bool> hillClimb(const vector<Item>& items, int maxWeight, int iterations) {
    vector<bool> bestSolution = randomSolution(items.size());
    int bestValue = knapsackValue(items, bestSolution);

    for (int i = 0; i < iterations; ++i) {
        vector<bool> neighborSolution = bestSolution;
        int randIndex = rand() % items.size();
        neighborSolution[randIndex] = !neighborSolution[randIndex];

        int neighborValue = knapsackValue(items, neighborSolution);

        if (neighborValue > bestValue && totalWeight(neighborSolution, items) <= maxWeight) {
            bestSolution = neighborSolution;
            bestValue = neighborValue;
        }
    }

    return bestSolution;
}

int main() {
    srand(time(nullptr));

    vector<Item> items = {{2, 10}, {3, 15}, {5, 30}, {7, 40}, {9, 50}};
    int maxWeight = 10;
    int iterations = 1000;

    vector<bool> solution = hillClimb(items, maxWeight, iterations);

    cout << "Itens selecionados:\n";
    for (int i = 0; i < items.size(); ++i) {
        if (solution[i]) {
            cout << "Item " << i + 1 << ": Peso=" << items[i].weight << ", Value=" << items[i].value << "\n";
        }
    }

    cout << "Valor total: " << knapsackValue(items, solution) << endl;

    return 0;
}