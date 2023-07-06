import { ProblemFactory } from "./problem-factory";
import { KnapSackSolver } from "./solver";

const aProblem = ProblemFactory.BuildProblem1();

console.log(aProblem);

const aSolver = new KnapSackSolver(aProblem);

const aSolution = aSolver.solve();

console.log("Solution: ", aSolution);