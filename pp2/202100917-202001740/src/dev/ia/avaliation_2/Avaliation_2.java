package dev.ia.avaliation_2;

public class Avaliation_2 {

    public static void execute() {

        Bag bag = new Bag();
        bag.init(12);
        bag.pickupItems();
        bag.listBagItems();

        for (int i = 0; i < 50; i++)
            bag.localSearch();

        bag.listBagItems();
    }

}
