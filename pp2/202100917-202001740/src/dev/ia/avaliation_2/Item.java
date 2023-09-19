package dev.ia.avaliation_2;

public class Item {

    private final float weight, value;

    public Item(float weight, float value) {
        this.weight = weight;
        this.value = value;
    }

    public float getValue() {
        return value;
    }

    public float getWeight() {
        return weight;
    }
}
