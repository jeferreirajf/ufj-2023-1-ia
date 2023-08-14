#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// 202109968 e 202001716
// Tema:Sistema de Restaurante
// Define as funções de pertinência para as variáveis de entrada.

double rating_low(double rating) {
  if (rating < 2) {
    return 1;
  } else {
    return 0;
  }
}

double rating_medium(double rating) {
  if (rating >= 2 && rating < 4) {
    return 1;
  } else {
    return 0;
  }
}

double rating_high(double rating) {
  if (rating >= 4) {
    return 1;
  } else {
    return 0;
  }
}

// Define as funções de pertinência para a variável de saída.

double recommendation_low(double recommendation) {
  if (recommendation < 1) {
    return 1;
  } else {
    return 0;
  }
}

double recommendation_medium(double recommendation) {
  if (recommendation >= 1 && recommendation < 3) {
    return 1;
  } else {
    return 0;
  }
}

double recommendation_high(double recommendation) {
  if (recommendation >= 3) {
    return 1;
  } else {
    return 0;
  }
}

// Define a função de inferência fuzzy.

double fuzzy_inference(double rating_low_value, double rating_medium_value, double rating_high_value) {
  double recommendation;

  // Regras de inferência
  if (rating_low_value > 0.5) {
    recommendation = 2;
  } else if (rating_medium_value > 0.5) {
    recommendation = 3;
  } else if (rating_high_value > 0.5) {
    recommendation = 5;
  } else {
    recommendation = 0.0; // Caso contrário, não há recomendação
  }

  return recommendation;
}

int main() {
  double rating = 3.5;
  double recommendation = 2.8;

  double rating_low_value = rating_low(rating);
  double rating_medium_value = rating_medium(rating);
  double rating_high_value = rating_high(rating);

  double recommendation_output = fuzzy_inference(rating_low_value, rating_medium_value, rating_high_value);

  // Imprime o resultado
 printf("Resultado: %.2f\n", recommendation_output);
 printf("Recomendação para o restaurante: ");
 
  printf("Resultado: %.2f\n", recommendation_output);

if (recommendation_output <= 1) {
printf("Baixa\n");
} else if (recommendation_output <= 2) {
printf("Média\n");
} else if (recommendation_output >= 3) {
printf("Alta\n");
} else {
printf("Sem recomendação\n");
}

return 0;
}
