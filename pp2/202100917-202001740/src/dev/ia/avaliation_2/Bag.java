package dev.ia.avaliation_2;

import java.util.*;

public class Bag {

    private final float maxWeight = 20.0F;

    private final List<Item> pickUpItems, items;
    private float bestValue = 0.0F, bagWeight = 0.0F;

    public Bag() {
        items = new ArrayList<>();
        pickUpItems = new ArrayList<>();
    }

    /*
     * ADICIONANDO OS ITENS COM PESO E VALOR
     * */

    public void init(int itemAmount) {

        for (int i = 1; i <= itemAmount; i++)
            items.add(new Item(new Random().nextInt(10), new Random().nextInt(30)));

        items.forEach(item -> System.out.println("Valor -> " + item.getValue() + " - Peso -> " + item.getWeight()));

    }

    /*
     * ESCOLHENDO OS ITENS
     * */

    public void pickupItems() {

        Item actualItem = null;

        while (bagWeight < maxWeight) {

            float totalWeight = 0.0F;

            for (Item item : pickUpItems)
                totalWeight += item.getWeight();

            for (Item item : items) {

                if (maxWeight - (item.getWeight() + totalWeight) >= 0) {

                    if (actualItem == null || actualItem.getValue() < item.getValue())
                        actualItem = item;

                }

            }

            if (actualItem != null) {

                items.remove(actualItem);
                pickUpItems.add(actualItem);

                bagWeight += actualItem.getWeight();
                actualItem = null;

            } else {
                break;
            }

        }

        if (!pickUpItems.isEmpty()) {

            for (Item item : pickUpItems)
                bestValue += item.getValue();

        }

    }

    public void listBagItems() {

        if (!pickUpItems.isEmpty()) {

            System.out.println("Itens na mochila: ");
            System.out.println("Bag Weight: " + bagWeight);

            for (Item item : pickUpItems)
                System.out.println("Valor->" + item.getValue() + ", Peso->" + item.getWeight());

        } else {
            System.out.println("Mochila vazia!");
        }

    }

    public void localSearch() {

        Item newItem = null, removeItem = null;

        for (Item item : pickUpItems) {

            float currentValue = bestValue - item.getValue();
            float currentWeight = bagWeight - item.getWeight();

            for (Item currentItem : items) {

                if ((currentWeight + currentItem.getWeight()) > maxWeight)
                    continue;

                float newValue = currentValue + currentItem.getValue();

                if (newValue > bestValue) {
                    removeItem = item;
                    newItem = currentItem;
                    break;
                }

            }

        }

        if (newItem != null) {

            pickUpItems.remove(removeItem);
            pickUpItems.add(newItem);

            bestValue += newItem.getValue() - removeItem.getValue();
            bagWeight += newItem.getWeight() - removeItem.getWeight();

        } else {

            perturb();

        }

    }

    private void perturb() {

        if (!pickUpItems.isEmpty()) {

            int randomIndex = new Random().nextInt(pickUpItems.size());

            Item removedItem = pickUpItems.remove(randomIndex);
            Item addedItem = getRandomItemWithSpace(removedItem.getWeight());

            if (addedItem != null) {
                pickUpItems.add(addedItem);
                bestValue = bestValue - removedItem.getValue() + addedItem.getValue();
                bagWeight = bagWeight - removedItem.getWeight() + addedItem.getWeight();
            } else {
                pickUpItems.add(removedItem);
            }
        }
    }

    private Item getRandomItemWithSpace(float currentWeight) {

        List<Item> validItems = new ArrayList<>();

        for (Item item : items) {

            if (((bagWeight - currentWeight) + item.getWeight()) <= maxWeight && !pickUpItems.contains(item))
                validItems.add(item);

        }

        if (!validItems.isEmpty())
            return validItems.get(new Random().nextInt(validItems.size()));

        return null;
    }

}
