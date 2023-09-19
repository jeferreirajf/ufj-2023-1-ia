package main;

import java.util.*;

public class BackPackLocalSearch {
    public static void main(String[] args) {
        System.out.println("202001742 & 202001744\n");
        Scanner scanner = new Scanner(System.in);

        // Solicitar a capacidade da mochila ao usuário
        System.out.print("Digite a capacidade da mochila: ");
        int capacityBP = scanner.nextInt();

        // Solicitar o número de itens ao usuário
        System.out.print("Digite o número de itens: ");
        int numItems = scanner.nextInt();

        // Ler informações dos itens da mochila
        List<Item> items = readItems(scanner, numItems);

        // Resolver o problema da mochila usando busca local
        List<Item> selectedItems = localSearchKnapsack(capacityBP, items);

        // Exibir itens na mochila e informações relevantes
        showSelectedItems(selectedItems);

        scanner.close();
    }

    // Método para ler informações dos itens da mochila
    private static List<Item> readItems(Scanner scanner, int numItems) {
        List<Item> items = new ArrayList<>();
        for (int i = 0; i < numItems; i++) {
            System.out.print("Digite o peso do item " + (i + 1) + ": ");
            int weight = scanner.nextInt();
            System.out.print("Digite o valor do item " + (i + 1) + ": ");
            int value = scanner.nextInt();
            items.add(new Item(weight, value));
        }
        return items;
    }

    // Método para resolver o problema da mochila usando busca local
private static List<Item> localSearchKnapsack(int capacityBP, List<Item> items) {
    List<Item> solution = new ArrayList<>(items);
    solution.sort(Comparator.comparingDouble((Item item) -> (double) item.value / item.weight).reversed());

    int totalWeight = 0;
    int totalValue = 0;
    Iterator<Item> iterator = solution.iterator();

    while (iterator.hasNext()) {
        Item item = iterator.next();
        if (totalWeight + item.weight <= capacityBP) {
            totalWeight += item.weight;
            totalValue += item.value;
        } else {
            iterator.remove();
        }
    }

    return solution;
}

    // Método para exibir os itens selecionados na mochila e informações relevantes
    private static void showSelectedItems(List<Item> selectedItems) {
        System.out.println("\nItens na mochila:");
        int totalWeight = 0;
        int totalValue = 0;

        for (Item item : selectedItems) {
            System.out.println("Item: Peso = " + item.weight + ", Valor = " + item.value);
            totalWeight += item.weight;
            totalValue += item.value;
        }

        System.out.println("Capacidade utilizada: " + totalWeight);
        System.out.println("Valor total na mochila: " + totalValue);
    }
}