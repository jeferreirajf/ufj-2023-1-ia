import java.util.List;

public class Search {
    private List<Item> items;

    public Search(List<Item> items, Bag bag) {
        this.items = items;
        hillClimbing(bag);
    }

    public void hillClimbing(Bag bag) {
        boolean improved;
        do {
            improved = false;
            for (Item item : items) {
                if (Additem(bag, item)) {
                    improved = true;
                }
            }
        } while (improved);
    }

    public boolean Additem(Bag bag, Item item) {
        if (bag.getTotalWeight() + item.getWeight() <= bag.getCapacity()) {
            bag.getItems().add(item);
            return true;
        } else {
            Item replaceableItem = null;
            for (Item existingItem : bag.getItems()) {
                if (existingItem.getValue() < item.getValue() && bag.getTotalWeight() - existingItem.getWeight() + item.getWeight() <= bag.getCapacity()) {
                    if (replaceableItem == null || existingItem.getValue() < replaceableItem.getValue()) {
                        replaceableItem = existingItem;
                    }
                }
            }
            if (replaceableItem != null) {
                bag.getItems().remove(replaceableItem);
                bag.getItems().add(item);
                return true;
            }
        }
        return false;
    }
}

