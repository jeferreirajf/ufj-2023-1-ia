import { ProblemFactory } from "./problem-factory";
import { KnapSackSolver } from "./solver";

const aProblem = ProblemFactory.BuildProblem1();

const totalWeight = aProblem.getWeightOfAllItems();

console.log(aProblem);

console.log("Maximum Weight: " + totalWeight);

const aSolver = new KnapSackSolver(aProblem);

const aSolution = aSolver.solve();

console.log("Solution: ", aSolution);