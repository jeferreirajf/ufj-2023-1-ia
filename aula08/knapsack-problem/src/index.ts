import { LocalSearchSolver } from "./local-search";
import { ProblemFactory } from "./problem-factory";
import { KnapSackSolver } from "./solver";

// Construção do cenário do problema
const aProblem = ProblemFactory.BuildProblem1();

// Imprime dados na tela
console.log(aProblem);

// Construção de um "resolvedor"
const aSolver = new LocalSearchSolver(aProblem, 1000);
const anotherSolver = new KnapSackSolver(aProblem);

// Chamada da construção da solução para o problema
const aSolution = aSolver.solve();
const bestSolution = anotherSolver.solve();

// Impressão da solução na tela
console.log("Solution: ", aSolution);

console.log("Best Solution: ", bestSolution);