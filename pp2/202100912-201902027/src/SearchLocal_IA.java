import java.util.ArrayList;
import java.util.List;

public class SearchLocal_IA {
    public static void main(String[] args) throws Exception {
        Bag bag = new Bag(10);
        List<Item> items = new ArrayList<>();
        items.add(new Item(2, 2));
        items.add(new Item(3, 1));
        items.add(new Item(5, 10));
        items.add(new Item(5, 10));
        items.add(new Item(19, 1));
        Search search = new Search(items, bag);
        System.out.println(bag);

    }
}
