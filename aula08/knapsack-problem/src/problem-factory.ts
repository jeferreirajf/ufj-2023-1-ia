import { Problem } from "./problem";

export class ProblemFactory {

    public static BuildProblem1() {

        var nItems = 10;
        var itemValue = Array(nItems);
        var itemQuantity = Array(nItems);
        var itemWeight = Array(nItems);

        const minimumValue = 1;
        const maximumValue = 10;

        for (var i = 0; i < nItems; i++) {
            itemValue[i] = Math.floor(
                Math.random() * (maximumValue - minimumValue) + minimumValue
            );
        }

        const minimumQuantity = 1;
        const maximumQuantity = 3;

        for (var i = 0; i < nItems; i++) {
            itemQuantity[i] = Math.floor(
                Math.random() * (maximumQuantity - minimumQuantity) + minimumQuantity
            );
        }

        const minimumItemWeight = 1;
        const maxItemWeight = 5;

        for (var i = 0; i < nItems; i++) {
            itemWeight[i] = Math.floor(
                Math.random() * (maxItemWeight - minimumItemWeight) + minimumItemWeight
            );
        }

        const suportedWeight = 25;

        return new Problem({ nItems, itemValue, itemQuantity, itemWeight, suportedWeight });

    }

}