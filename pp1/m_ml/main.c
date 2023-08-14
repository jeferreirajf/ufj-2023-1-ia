/*Em síntese, Grifinória (Gryffindor) é o lar dos corajosos.
Na Sonserina (Slytherin) moram os astutos e ambiciosos.
Corvinal (Ravenclaw) é a morada dos que se destacam pela inteligência e priorizam o aprendizado.
Em Lufa-Lufa (Hufflepuff) residem os mais leais e justos.

202001742 e 202001744

Nosso programa utiliza a logica Fuzzy para descobrir qual a sua casa em Hogwarts

*/
#include <stdio.h>
#include <string.h>
// Função para determinar o grau de pertinência
float fuzzyGrade(float value, float x0, float x1) {
    if (value <= x0) {
        return 0.0;
    } else if (value >= x1) {
        return 1.0;
    } else {
        return (value - x0) / (x1 - x0);
    }
}
float max(float a, float b) {
    return (a > b) ? a : b;
}
int main() {
    float coragem, inteligencia, lealdade, astucia, justica, ousadia;
     printf("\n|-----------------------------------------------------------|");
    printf("\n\tDescobrindo qual é sua casa em Hogwarts");
    printf("\n\tDigite todas as respostas de 1 a 10");
    printf("\n\tSendo 1 não me identifico e 10 sendo me indentifico muito");
    printf("\n\t5 mais ou menos");
    printf("\n|-----------------------------------------------------------|");
    printf("\nO quanto você se acha corajoso: ");
    scanf("%f", &coragem);
    printf("O quanto você se acha inteligente: ");
    scanf("%f", &inteligencia);
    printf("O quanto você se acha leal: ");
    scanf("%f", &lealdade);
    printf("O quanto você se acha astuto: ");
    scanf("%f", &astucia);
    printf("O quanto você se acha justo: ");
    scanf("%f", &justica);
    printf("O quanto você se acha ousadia: ");
    scanf("%f", &ousadia);

    float grifinoria = fuzzyGrade(coragem, 8.0, 10.0);
    float corvinal = fuzzyGrade(inteligencia, 6.0, 9.0);
    float lufa_lufa = fuzzyGrade(max(lealdade, justica), 7.0, 10.0);
    float sonserina = fuzzyGrade(max(astucia, ousadia), 7.0, 10.0);

    // Inferência fuzzy
    float inferencia_grifinoria = coragem;
    float inferencia_corvinal = inteligencia;
    float inferencia_lufa_lufa = max(lealdade, justica);
    float inferencia_sonserina = max(astucia, ousadia);

    // Imprimindo os graus de inferência
   /* printf("Graus de inferência:\n");
    printf("Grifinória: %.2f\n", inferencia_grifinoria);
    printf("Corvinal: %.2f\n", inferencia_corvinal);
    printf("Lufa-Lufa: %.2f\n", inferencia_lufa_lufa);
    printf("Sonserina: %.2f\n", inferencia_sonserina);*/

    // Determinando a casa de Hogwarts
    float maxGrade = inferencia_grifinoria;
    char casa[20] = "Grifinória";

    if (inferencia_corvinal > maxGrade) {
        maxGrade = inferencia_corvinal;
        strcpy(casa, "Corvinal");
    }
    if (inferencia_lufa_lufa > maxGrade) {
        maxGrade = inferencia_lufa_lufa;
        strcpy(casa, "Lufa-Lufa");
    }
    if (inferencia_sonserina > maxGrade) {
        maxGrade = inferencia_sonserina;
        strcpy(casa, "Sonserina");
    }

    printf("A sua casa de Hogwarts seria: %s\n", casa);

    return 0;
}