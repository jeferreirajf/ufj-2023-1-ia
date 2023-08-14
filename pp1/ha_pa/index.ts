// 202100889 e 202109946

const produtividadeSet = new Map();
produtividadeSet.set("low", 1);
produtividadeSet.set("low-medium", 0.75);
produtividadeSet.set("medium", 0.5);
produtividadeSet.set("medium-high", 0.25);
produtividadeSet.set("high", 0);
//Aqui definimos o nível de produtividade da pessoa de 0 a 1

const usoDoCelularSet = new Map();
usoDoCelularSet.set("low", 0);
usoDoCelularSet.set("low-medium", 0.25);
usoDoCelularSet.set("medium", 0.5);
usoDoCelularSet.set("medium-high", 0.75);
usoDoCelularSet.set("high", 1);
//Aqui definimos o nível de uso do celular da pessoa de 0 a 1

const usoDeJogosSet = new Map();
usoDeJogosSet.set("low", 0);
usoDeJogosSet.set("low-medium", 0.25);
usoDeJogosSet.set("medium", 0.5);
usoDeJogosSet.set("medium-high", 0.75);
usoDeJogosSet.set("high", 1);
//Aqui definimos o nível de uso de jogos eletrônicos da pessoa de 0 a 1

const ansiedadeSet = new Map();
ansiedadeSet.set("low", 0);
ansiedadeSet.set("low-medium", 0.25);
ansiedadeSet.set("medium", 0.5);
ansiedadeSet.set("medium-high", 0.75);
ansiedadeSet.set("high", 1);
//Aqui definimos o nível de ansiedade da pessoa de 0 a 1

const organizacaoSet = new Map();
organizacaoSet.set("low", 1);
organizacaoSet.set("low-medium", 0.75);
organizacaoSet.set("medium", 0.5);
organizacaoSet.set("medium-high", 0.25);
organizacaoSet.set("high", 0);
//Aqui definimos o nível de organização da pessoa de 0 a 1

type Answer = {
  produtividade: string;
  celular: string;
  jogosEletronicos: string;
  ansiedade: string;
  organizacao: string;
};

function fuzzyPertinenceInfer(
  produtividade: number,
  celular: number,
  jogosEletronicos: number,
  ansiedade: number,
  organizacao: number
): number {
  return (
    (produtividade + celular + jogosEletronicos + ansiedade + organizacao) / 5
  );
}

function procastinacaoLevelInfer(pertinence: number): string {
  if (pertinence < 0.25) {
    return "baixo";
  } else if (pertinence < 0.75) {
    return "médio";
  } else {
    return "alto";
  }
}

function evaluateprocastinacao(answer: Answer): string {
  const produtividadePertinence = produtividadeSet.get(answer.produtividade);
  const celularPertinence = usoDoCelularSet.get(answer.celular);
  const jogosEletronicosPertinence = usoDeJogosSet.get(answer.jogosEletronicos);
  const ansiedadePertinence = ansiedadeSet.get(answer.ansiedade);
  const organizacaoPertinence = organizacaoSet.get(answer.organizacao);

  const pertinence = fuzzyPertinenceInfer(
    produtividadePertinence,
    celularPertinence,
    jogosEletronicosPertinence,
    ansiedadePertinence,
    organizacaoPertinence
  );

  console.log("Pertinência: ", pertinence);

  return procastinacaoLevelInfer(pertinence);
}

const answers: Answer = {
  produtividade: "low-medium",
  celular: "high",
  jogosEletronicos: "medium-high",
  ansiedade: "medium-high",
  organizacao: "low-medium",
};

console.log("Nível de procrastinação: ", evaluateprocastinacao(answers));
