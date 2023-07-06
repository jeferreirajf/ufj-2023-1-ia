import { ProblemFactory } from "./problem-factory";
import { KnapSackSolver } from "./solver";

// Construção do cenário do problema
const aProblem = ProblemFactory.BuildProblem1();

// Imprime dados na tela
console.log(aProblem);

// Construção de um "resolvedor"
const aSolver = new KnapSackSolver(aProblem);

// Chamada da construção da solução para o problema
const aSolution = aSolver.solve();

// Impressão da solução na tela
console.log("Solution: ", aSolution);