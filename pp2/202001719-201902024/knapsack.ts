function totalValue(solution, items) {
    let accumulator = 0;
    for(let i = 0; i < solution.length; i++) {
        for (let j = 0; j < items.length; j++) {
            if(solution[i] === items[j].name){
                accumulator += items[j].value;
            }
        }
    }
    
    return accumulator;
}

function totalWeight(solution, items) {
    let accumulator = 0;
    for(let i = 0; i < solution.length; i++) {
        for (let j = 0; j < items.length; j++) {
            if(solution[i] === items[j].name){
                accumulator += items[j].weight;
            }
        }
    }
    
    return accumulator;
}
  
function objectiveFunction(solution, items, maxWeight) {
    const valueTotal = totalValue(solution, items);
    const weightTotal = totalWeight(solution, items);
    if (weightTotal > maxWeight) {
        return 0;  // Penalização de soluções inválidas
    }
    return valueTotal;
}
  
function solucaoInicial(n) {
    return Array.from({ length: n }, () => Math.random() < 0.5 ? 1 : 0);
}
  
function adjacent(solution) {
    return solution.map((_, i) => {
        const newSolution = [...solution];
        newSolution[i] = 1 - newSolution[i];
        return newSolution;
    });
}
  
function localSearch(items, maxWeight) {
    const n = items.length;
    let s = solucaoInicial(n);
    let fo = objectiveFunction(s, items, maxWeight);
    let improvement = true;
    const selectedItems = [];

    while (improvement) {
        improvement = false;
        const v = adjacent(s);
        for (const sLine of v) {
            const ofLine = objectiveFunction(sLine, items, maxWeight);
            if (ofLine > fo) {
                s = sLine;
                fo = ofLine;
                improvement = true;
                break;
            }
        }
    }

    for (let i = 0; i < s.length; i++) {
        if (s[i] === 1) {
            selectedItems.push(items[i].name);
        }
    }

    return selectedItems;
}
  
const items = [
    { 
        name: "item1",
        value: 2,
        weight: 1 
    },
    { 
        name: "item2",
        value: 4,
        weight: 2 
    },
    { 
        name: "item3",
        value: 6, 
        weight: 3 
    },
    { 
        name: "item4",
        value: 8, 
        weight: 4 
    },
    { 
        name: "item5",
        value: 10, 
        weight: 5 
    },
    {
        name: "item6",
        value: 12, 
        weight: 6
    }
];
  
const maxWeight = 20;

const solution = localSearch(items, maxWeight);

console.log(`Itens selecionados: ${solution}`);
console.log(`Lucro total: ${totalValue(solution, items)}`);
console.log(`Peso dos itens da mochila: ${totalWeight(solution, items)}`);
console.log(`Peso total permitido: ${maxWeight}`)function totalValue(solution, items) {
    let accumulator = 0;
    for(let i = 0; i < solution.length; i++) {
        for (let j = 0; j < items.length; j++) {
            if(solution[i] === items[j].name){
                accumulator += items[j].value;
            }
        }
    }
    
    return accumulator;
}

function totalWeight(solution, items) {
    let accumulator = 0;
    for(let i = 0; i < solution.length; i++) {
        for (let j = 0; j < items.length; j++) {
            if(solution[i] === items[j].name){
                accumulator += items[j].weight;
            }
        }
    }
    
    return accumulator;
}
  
function objectiveFunction(solution, items, maxWeight) {
    const valueTotal = totalValue(solution, items);
    const weightTotal = totalWeight(solution, items);
    if (weightTotal > maxWeight) {
        return 0;  // Penalização de soluções inválidas
    }
    return valueTotal;
}
  
function solucaoInicial(n) {
    return Array.from({ length: n }, () => Math.random() < 0.5 ? 1 : 0);
}
  
function adjacent(solution) {
    return solution.map((_, i) => {
        const newSolution = [...solution];
        newSolution[i] = 1 - newSolution[i];
        return newSolution;
    });
}
  
function localSearch(items, maxWeight) {
    const n = items.length;
    let s = solucaoInicial(n);
    let fo = objectiveFunction(s, items, maxWeight);
    let improvement = true;
    const selectedItems = [];

    while (improvement) {
        improvement = false;
        const v = adjacent(s);
        for (const sLine of v) {
            const ofLine = objectiveFunction(sLine, items, maxWeight);
            if (ofLine > fo) {
                s = sLine;
                fo = ofLine;
                improvement = true;
                break;
            }
        }
    }

    for (let i = 0; i < s.length; i++) {
        if (s[i] === 1) {
            selectedItems.push(items[i].name);
        }
    }

    return selectedItems;
}
  
const items = [
    { 
        name: "item1",
        value: 2,
        weight: 1 
    },
    { 
        name: "item2",
        value: 4,
        weight: 2 
    },
    { 
        name: "item3",
        value: 6, 
        weight: 3 
    },
    { 
        name: "item4",
        value: 8, 
        weight: 4 
    },
    { 
        name: "item5",
        value: 10, 
        weight: 5 
    },
    {
        name: "item6",
        value: 12, 
        weight: 6
    }
];
  
const maxWeight = 20;

const solution = localSearch(items, maxWeight);

console.log(`Itens selecionados: ${solution}`);
console.log(`Lucro total: ${totalValue(solution, items)}`);
console.log(`Peso dos itens da mochila: ${totalWeight(solution, items)}`);
console.log(`Peso total permitido: ${maxWeight}`)