import { Problem } from "./problem";

interface Solution {
    bag: number[];
    totalWeight: number;
    totalValue: number;
}

export class KnapSackSolver {

    private _problem: Problem;

    constructor(aProblem: Problem) {
        this._problem = aProblem;
    }

    private generateHeuristicItemsPreferedOrder(): number[] {
        let values: { value: number, item: number }[] = Array();
        
        for (let i = 0; i < this._problem.nItems(); i++) {
            var itemValue = this._problem.itemValue(i);
            var itemWeight = this._problem.itemWeight(i);
            
            values.push({ value: itemValue / itemWeight, item: i });
        }

        const sortedValues = values.sort((a, b) => b.value - a.value);

        return sortedValues.map(value => value.item);
    }

    public solve(): Solution {

        let bag = Array();

        const heuristicItemsOrdered = this.generateHeuristicItemsPreferedOrder();

        var bagCapacityLefting = this._problem.suportedWeight();

        const asd: Solution = {
            bag: [],
            totalValue: 0,
            totalWeight: 0
        }

        var i = 0;
        var item = heuristicItemsOrdered[i];

        var itemsLefting = this._problem.itemTotalCount(item);
        var itemWeight = this._problem.itemWeight(item);

        while (i < this._problem.nItems()) {
            if (itemsLefting == 0) {
                i++;

                if (i < this._problem.nItems()) {
                    item = heuristicItemsOrdered[i];
                    itemsLefting = this._problem.itemTotalCount(item);
                    itemWeight = this._problem.itemWeight(item);
                }
            }
            else if (itemWeight > bagCapacityLefting) {
                i++;

                if (i < this._problem.nItems()) {
                    item = heuristicItemsOrdered[i];
                    itemsLefting = this._problem.itemTotalCount(item);
                    itemWeight = this._problem.itemWeight(item);
                }
            }
            else {
                bag.push(item);
                itemsLefting--;
                bagCapacityLefting -= itemWeight;
            }
        }

        const totalWeight = bag.reduce((totalWeight, item) => totalWeight + this._problem.itemWeight(item), 0);
        const totalValue = bag.reduce((totalValue, item) => totalValue + this._problem.itemValue(item), 0);

        const solution: Solution = {
            bag,
            totalWeight,
            totalValue
        }

        return solution;
    }
}