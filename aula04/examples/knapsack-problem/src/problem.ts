interface ProblemProps {
    nItems: number;
    itemValue: number[];
    itemQuantity: number[];
    itemWeight: number[];
    suportedWeight: number;
}

export class Problem {

    private _nItems: number;
    private _itemValue: number[];
    private _itemTotalCount: number[];
    private _itemWeight: number[];
    private _suportedWeight: number;

    constructor({ nItems, itemValue, itemQuantity, itemWeight, suportedWeight }: ProblemProps) {
        this._nItems = nItems;
        this._itemValue = itemValue;
        this._itemTotalCount = itemQuantity;
        this._itemWeight = itemWeight;
        this._suportedWeight = suportedWeight;
    }

    public nItems(): number {
        return this._nItems;
    }

    public itemValue(i: number): number {
        return this._itemValue[i];
    }

    public itemTotalCount(i: number): number {
        return this._itemTotalCount[i];
    }

    public itemWeight(i: number): number {
        return this._itemWeight[i];
    }

    public suportedWeight(): number {
        return this._suportedWeight;
    }

    public getWeightOfAllItems(): number {
        var totalWeight = 0;

        for (var i = 0; i < this._nItems; i++) {
            totalWeight += this._itemTotalCount[i] +
                this._itemWeight[i];
        }

        return totalWeight;
    }

}