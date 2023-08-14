/*
Trabalho prático - IA
Integrantes: 202001719 e 201902024 
Tema: Descubra qual tipo de filme é mais seu estilo: Barbie ou Oppenhaimer?
*/

const filme1 = new Map();
const filme2 = new Map();
const filme3 = new Map();
const serie1 = new Map();
const serie2 = new Map();

filme1.set("1917", 1.0);
filme1.set("O resgate do soldado Ryan", 2.0);
filme1.set("Legalmente Loira", 3.0);
filme1.set("Meninas Malvadas", 4.0);

filme2.set("Até o último homem", 1.0);
filme2.set("O pianista", 2.0);
filme2.set("As patricinhas de Beverly Hills", 3.0);
filme2.set("As Branquelas", 4.0);

filme3.set("A Origem", 1.0);
filme3.set("Dunkirk", 2.0);
filme3.set("De repente 30", 3.0);
filme3.set("Garota Mimada", 4.0);

serie1.set("Peaky Blinders", 1.0);
serie1.set("Irmãos de Guerra", 2.0);
serie1.set("Gossip Girl", 3.0);
serie1.set("The Vampire Diaries", 4.0);

serie2.set("Narcos", 1.0);
serie2.set("Os Sopranos", 2.0);
serie2.set("Pretty Little Liars", 3.0);
serie2.set("One Tree Hill", 4.0);

function funcaoPertinencia(pertinenciaFilme1, pertinenciaFilme2, pertinenciaFilme3, pertinenciaSerie1, pertinenciaSerie2) {
    return (pertinenciaFilme1 + pertinenciaFilme2 + pertinenciaFilme3 + pertinenciaSerie1 + pertinenciaSerie2) / 5;
}

function funcaoInferencia(pertinencia) {
    if (pertinencia <= 2) {
        return "Parabéns, você possui uma vibe mais Oppenhaimer"
    } else {
        return "Parabéns, você possui uma vibe mais Barbie"
    }
}

function decidirEstilo(filmeUm, filmeDois, filmeTres, serieUm, serieDois) {
    const pertinenciaFilme1 = filme1.get(filmeUm);
    const pertinenciaFilme2 = filme2.get(filmeDois);
    const pertinenciaFilme3 = filme3.get(filmeTres);
    const pertinenciaSerie1 = serie1.get(serieUm);
    const pertinenciaSerie2 = serie2.get(serieDois);

    const pertinencia = funcaoPertinencia(pertinenciaFilme1, pertinenciaFilme2, pertinenciaFilme3, pertinenciaSerie1, pertinenciaSerie2);

    console.log("Pertinência: ", pertinencia);

    return funcaoInferencia(pertinencia);
}

function main() {
    const decidirFilme1 = "O resgate do soldado Ryan";
    const decidirFilme2 = "O pianista";
    const decidirFilme3 = "De repente 30";
    const decidirSerie1 = "Irmãos de Guerra";
    const decidirSerie2 = "Narcos";

    console.log(decidirEstilo(decidirFilme1, decidirFilme2, decidirFilme3, decidirSerie1, decidirSerie2));
}

main();