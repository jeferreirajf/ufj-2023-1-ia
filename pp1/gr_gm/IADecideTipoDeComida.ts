//202001727 e 202001726 - Adivinha Tipo da Comida

const horaSet = new Map();
horaSet.set("Café da manhã", 0);
horaSet.set("Lanche da manhã", 0.25);
horaSet.set("Almoço", 0.5);
horaSet.set("Lanche da tarde", 0.75);
horaSet.set("Janta", 0.9);

const tipoPreparoSet = new Map();
tipoPreparoSet.set("Crú", 0);
tipoPreparoSet.set("Cozido", 0.25);
tipoPreparoSet.set("Assado", 0.5);
tipoPreparoSet.set("Frito", 0.75);
tipoPreparoSet.set("Picante", 1.0);

const regiaoTipicaSet = new Map();
regiaoTipicaSet.set("Japão", 0);
regiaoTipicaSet.set("Itália", 0.25);
regiaoTipicaSet.set("Brasil", 0.5);
regiaoTipicaSet.set("USA", 0.75);
regiaoTipicaSet.set("México", 1.0);

const gostoComidaSet = new Map();
gostoComidaSet.set("Agridoce", 0);
gostoComidaSet.set("Salgado", 0.75);
gostoComidaSet.set("Doce", 3.0);

type Answer = {
    hora: string,
    tipoPreparo: string,
    regiaoTipica: string,
    gostoComida: string,
}

//Função de Pertinência
function fuzzyPertinenceInfer(hora: number,
    tipoPreparo: number, regiaoTipica: number,
    gostoComida: number): number {

    return (hora + tipoPreparo + regiaoTipica + gostoComida) / 4; 
}

//Função de Inferência
function tipoComidaInfer(pertinence: number): string {
    if (pertinence < 0.25) {
        return "Natural";
    }
    else if (pertinence < 0.55) {
        return "Massa";
    }
    else if (pertinence < 0.75) {
        return "Carnes";
    } else if (pertinence < 1.0) {
        return "FastFood";
    } else {
        return "Sobremesa";
    }
}

function decideTipoComida(answer: Answer): string {
    const horaPertinence = horaSet.get(answer.hora);
    const tipoPreparoPertinence = tipoPreparoSet.get(answer.tipoPreparo);
    const regiaoTipicaPertinence = regiaoTipicaSet.get(answer.regiaoTipica);
    const gostoComidaPertinence = gostoComidaSet.get(answer.gostoComida);

    const pertinence = fuzzyPertinenceInfer(horaPertinence, tipoPreparoPertinence,
        regiaoTipicaPertinence, gostoComidaPertinence);

    console.log("Pertinence: ", pertinence);

    return tipoComidaInfer(pertinence);
}

const answers = {
    hora: "Janta",
    tipoPreparo: "Crú",
    regiaoTipica: "Japão",
    gostoComida: "Agridoce",
};

console.log(decideTipoComida(answers));