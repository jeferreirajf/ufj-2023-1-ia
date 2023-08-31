import { Problem } from "./problem";

interface Solution {
    bag: number[];
    totalWeight: number;
    totalValue: number;
}

export class LocalSearchSolver {

    private problem: Problem;
    private maxIterations: number;

    constructor(aProblem: Problem, aMaxIterations: number = 1000) {
        this.problem = aProblem;
        this.maxIterations = aMaxIterations;
    }

    private generateInitialSolution(): number[] {
        let solution: number[] = [];

        for (let i = 0; i < this.problem.nItems(); i++) {
            const aQtd = Math.floor(
                Math.random() * (this.problem.itemTotalCount(i))
            );

            solution.push(aQtd);
        }

        return solution;
    }

    private executeAddMovement(solution: number[]): number[] {

        var aNewSolution = solution.slice();

        const i = Math.floor(
            Math.random() * (this.problem.nItems())
        );

        // Max items constraint
        if (aNewSolution[i] == this.problem.itemTotalCount(i)) {
            return aNewSolution;
        }

        aNewSolution[i]++;

        const usedCapacity = this.calculateSolutionCapacity(aNewSolution);

        // Max capacity constraint
        if (usedCapacity > this.problem.suportedWeight()) {
            return solution;
        }

        return aNewSolution;
    }

    private executeRemoveMovement(solution: number[]): number[] {

        var aNewSolution = solution.slice();

        const i = Math.floor(
            Math.random() * (this.problem.nItems())
        );

        // Max items constraint
        if (aNewSolution[i] == this.problem.itemTotalCount(i)) {
            return aNewSolution;
        }

        if (aNewSolution[i] == 0)
            return aNewSolution;

        aNewSolution[i]--;

        return aNewSolution;
    }

    private executeRemoveAddMovement(solution: number[]): number[] {
        var aNewSolution = this.executeRemoveMovement(solution);
        var aNewSolution = this.executeAddMovement(aNewSolution);

        return aNewSolution;
    }

    private calculateSolutionCapacity(solution: number[]): number {
        // const usedCapacity = solution.reduce((acc, curr, i) => 
        //     acc + curr * this.problem.itemWeight(i), 0);

        var usedCapacity = 0;

        for (var i = 0; i < solution.length; i++) {
            usedCapacity += solution[i] * this.problem.itemWeight(i);
        }

        return usedCapacity;
    }

    private generateRandomNeighbor(solution: number[]): number[] {
        const movementNumber = Math.floor(3);

        if (movementNumber == 0)
            return this.executeAddMovement(solution);
        else if (movementNumber == 1)
            return this.executeRemoveMovement(solution);
        else
            return this.executeRemoveAddMovement(solution);
    }

    public solve(): Solution {

        var currentSolution = this.generateInitialSolution();

        var bestSolution = currentSolution.slice();

        var bestSolutionFitness = this.calculateFitness(bestSolution);

        for (var i = 0; i < this.maxIterations; i++) {

            var bestNeighbor = this.generateRandomNeighbor(currentSolution);
            var bestNeighborFitness = this.calculateFitness(bestNeighbor);

            for (var j = 0; j < this.maxIterations - 1; j++) {
                var aNewSolution = this.generateRandomNeighbor(currentSolution);

                const newSolutionFitness = this.calculateFitness(aNewSolution);

                if (bestNeighborFitness < newSolutionFitness) {
                    bestNeighbor = aNewSolution.slice();
                    bestNeighborFitness = newSolutionFitness;
                }
            }

            currentSolution = bestNeighbor.slice();

            if (bestSolutionFitness < bestNeighborFitness) {
                bestSolutionFitness = bestNeighborFitness;
                bestSolution = bestNeighbor.slice();
            }
        }

        return this.generateFinalSolution(bestSolution);
    }

    private calculateFitness(aSolution: number[]): number {
        var fitness = 0;

        for(var i = 0; i < aSolution.length; i++){
            fitness += aSolution[i] * this.problem.itemValue(i);
        }

        return fitness;
    }

    private generateFinalSolution(aSolution: number[]){
        var solution: Solution;

        var totalWeight = 0;

        for(var i = 0; i < aSolution.length; i++){
            totalWeight += aSolution[i] * this.problem.itemWeight(i);
        }

        solution = {
            bag: aSolution.slice(),
            totalValue: this.calculateFitness(aSolution),
            totalWeight
        };

        return solution;
    }

}