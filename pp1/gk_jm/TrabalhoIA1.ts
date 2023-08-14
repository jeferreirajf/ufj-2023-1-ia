// 202100882 e 202100892

const febreSet = new Map();
febreSet.set("Baixo", 1);
febreSet.set("Medio", 0.5);
febreSet.set("Alto", 0);

const dorDeCabecaSet = new Map();
dorDeCabecaSet.set("Baixo", 1.0);
dorDeCabecaSet.set("Medio", 0.5);
dorDeCabecaSet.set("Alto", 0.0);

const tosseSet = new Map();
tosseSet.set("Pouco frequente", 1.0);
tosseSet.set("Mediano", 0.5);
tosseSet.set("Constantemente", 0.0);

const dorNoCorpoSet = new Map();
dorNoCorpoSet.set("Baixo", 1.0);
dorNoCorpoSet.set("Medio", 0.5);
dorNoCorpoSet.set("Alto", 0.0);

type Answer = {
    febre: string,
    dorDeCabeca: string,
    tosse: string,
    dorNoCorpo: string,
}

function fuzzyPertinenceInfer(febre: number, 
    dorDeCabeca: number, tosse: number, 
    dorNoCorpo: number): number{
    
    return (febre + dorDeCabeca + tosse + dorNoCorpo) / 4; 
}

function sintomasInfer(pertinence: number) : string{
    if(pertinence < 0.3){
        return "Grave - O pacente deve ser atendido urgentemente";
    }
    else if(pertinence < 0.70){
        return "Media - O paciente deve ser atendido com certa rapidez";
    }
    else{
        return "Leve - O paciete pode aguardar o atendimento";
    }
}

function decideSintomas(answer: Answer) : string {
    const febrePertinence = febreSet.get(answer.febre);
    const dorDeCabecaPertinence = dorDeCabecaSet.get(answer.dorDeCabeca);
    const tossePertinence = tosseSet.get(answer.tosse);
    const dorNoCorpoPertinence = dorNoCorpoSet.get(answer.dorNoCorpo);

    const pertinence = fuzzyPertinenceInfer(febrePertinence, dorDeCabecaPertinence,
            tossePertinence, dorNoCorpoPertinence);

    console.log("Pertinence: ", pertinence);

    return sintomasInfer(pertinence);
}


const answers = {
    febre: "Alto",
    dorDeCabeca: "Alto",
    tosse: "Pouco frequente",
    dorNoCorpo: "Alto",
};

console.log(decideSintomas(answers));