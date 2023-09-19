import java.util.ArrayList;
import java.util.List;

public class Bag {
    private int capacity;
    private List<Item> items;

    public Bag(int capacity) {
        this.capacity = capacity;
        this.items = new ArrayList<>();
    }

    public List<Item> getItems() {
        return items;
    }

    public int getCapacity() {
        return capacity;
    }

    public int getTotalWeight() {
        int totalWeight = 0;
        for (Item item : items) {
            totalWeight += item.getWeight();
        }
        return totalWeight;
    }

    public int getTotalValue() {
        int totalValue = 0;
        for (Item item : items) {
            totalValue += item.getValue();
        }
        return totalValue;
    }

    @Override
    public String toString() {
        StringBuilder aux = new StringBuilder();
        for (int i = 0; i < items.size(); i++) {
            aux.append("Items: ").append(i).append(" - Weight: ").append(items.get(i).getWeight()).append(" - Value: ").append(items.get(i).getValue()).append("\n");
        }
        return aux.toString();
    }
}
