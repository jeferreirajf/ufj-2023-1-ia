/*
  Nome: 202001715 e 202001728
  Tema: Grau de severidade de sintomas respiratórios
  Descrição: O usuário usa o AnswerAntecedent com base nas categorias dentro dos conjuntos,
  e com isso o sistema utiliza uma base de conhecimento prévia e infere o grau de severidade
  dos sintomas respiratórios informados.
  Obs.: O sistema foi feito utilizando uma base de conhecimento real porém com algumas adaptações.
*/

// scale: 0-30
const frequencyOfDailySymptoms = new Map();
frequencyOfDailySymptoms.set('never', { min: 0, max: 2 });
frequencyOfDailySymptoms.set('seldom', { min: 0, max: 3 });
frequencyOfDailySymptoms.set('sometimes', { min: 2, max: 6 });
frequencyOfDailySymptoms.set('often', { min: 4, max: 10 });
frequencyOfDailySymptoms.set('frequenttly', { min: 8, max: 17 });
frequencyOfDailySymptoms.set('always', { min: 12, max: 30 });

// scale: 0-30
const frequencyOfNocturnalSymptoms = new Map();
frequencyOfNocturnalSymptoms.set('never', { min: 0, max: 1 });
frequencyOfNocturnalSymptoms.set('seldom', { min: 0, max: 4 });
frequencyOfNocturnalSymptoms.set('sometimes', { min: 1, max: 7 });
frequencyOfNocturnalSymptoms.set('often', { min: 4, max: 12 });
frequencyOfNocturnalSymptoms.set('frequenttly', { min: 8, max: 16 });
frequencyOfNocturnalSymptoms.set('always', { min: 12, max: 30 });

// scale: 0-10
const dyspnoeaInExercice = new Map();
dyspnoeaInExercice.set('very-low', { min: 0, max: 1.5 });
dyspnoeaInExercice.set('low', { min: 0, max: 3.5 });
dyspnoeaInExercice.set('medium-low', { min: 2, max: 6.5 });
dyspnoeaInExercice.set('medium', { min: 4.25, max: 7.75 });
dyspnoeaInExercice.set('medium-high', { min: 6, max: 9.5 });
dyspnoeaInExercice.set('high', { min: 7.75, max: 10 });

type AnswerAntecedent = {
  frequencyOfDailySymptoms: string;
  frequencyOfNocturnalSymptoms: string;
  dyspnoeaInExercice: string;
};

// função de pertinência
function getPertinence(answer: AnswerAntecedent): number {
  return (
    ((frequencyOfDailySymptoms.get(answer.frequencyOfDailySymptoms).min +
      frequencyOfDailySymptoms.get(answer.frequencyOfDailySymptoms).max) /
      2 /
      30 +
      (frequencyOfNocturnalSymptoms.get(answer.frequencyOfNocturnalSymptoms)
        .min +
        frequencyOfNocturnalSymptoms.get(answer.frequencyOfNocturnalSymptoms)
          .max) /
        2 /
        30 +
      (dyspnoeaInExercice.get(answer.dyspnoeaInExercice).min +
        dyspnoeaInExercice.get(answer.dyspnoeaInExercice).max) /
        2 /
        10) /
    3
  );
}

// função de inferência
function getInference(pertinence: number): string[] {
  let result = [];

  if (pertinence >= 0 && pertinence <= 0.1) result.push('normal');
  if (pertinence >= 0 && pertinence <= 0.3) result.push('mild');
  if (pertinence >= 0.1 && pertinence <= 0.5) result.push('mild-to-moderate');
  if (pertinence >= 0.35 && pertinence <= 0.6) result.push('moderate');
  if (pertinence >= 0.47 && pertinence <= 0.8) result.push('moderate-to-more');
  if (pertinence >= 0.64 && pertinence <= 1.0) result.push('more');

  return result;
}

function decideSeverity(answer: AnswerAntecedent) {
  const inference = getInference(getPertinence(answer));

  if (inference.length == 0) {
    console.log(
      "Error: the data couldn't infere anything about your symptoms."
    );
  } else if (inference.length == 1) {
    console.log('Your degree of respiratory symptoms severity is: ');
    console.log(inference[0]);
  } else if (inference.length == 2) {
    console.log('Your degree of respiratory symptoms severity is between: ');
    console.log(inference[0] + ' and ' + inference[1]);
  } else {
    console.log(
      "The data couldn't infere precisely based on your symptoms, but is between: "
    );
    console.log(inference[0] + ' and ' + inference[inference.length - 1]);
  }
}

const answerAntecedent = {
  frequencyOfDailySymptoms: 'often',
  frequencyOfNocturnalSymptoms: 'always',
  dyspnoeaInExercice: 'medium-high',
};

decideSeverity(answerAntecedent);
