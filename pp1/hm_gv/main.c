#include <stdio.h>
#include <string.h>
#include <locale.h>

//TRABALHO PRATICO DE INTELIGENCIA ARTIFICIAL
//Alunos: 202109775 e 202100884
//13/07/2023



// Fun��o de pertin�ncia para g�nero
float pertinenciaGenero(float valor, const char* genero) {
    if (strcmp(genero, "rock") == 0) {
        if (valor <= 3.0) {
        return 0.0;
        } else if (valor <= 7.0) {
        return (valor - 3.0) / 4.0;
        } else {
        return 1.0;
        }
            } else if (strcmp(genero, "pop") == 0) {
                if (valor <= 3.0) {
                return 0.0;
                } else if (valor <= 7.0) {
                return (valor - 3.0) / 4.0;
                } else {
                return 1.0;
                }
                        } else if (strcmp(genero, "jazz") == 0) {
                            if (valor <= 3.0) {
                            return 0.0;
                            } else if (valor <= 7.0) {
                            return (valor - 3.0) / 4.0;
                            } else {
                            return 1.0;
                            }
                        }
}

// Fun��o de pertin�ncia para ritmo
float pertinenciaRitmo(float valor, const char* ritmo) {
    if (strcmp(ritmo, "lento") == 0) {
        if (valor <= 2.0) {
        return 1.0;
        } else if (valor <= 5.0) {
        return (5.0 - valor) / 3.0;
        } else {
        return 0.0;
        }
            } else if (strcmp(ritmo, "moderado") == 0) {
                if (valor <= 2.0) {
                return 1.0;
                } else if (valor <= 5.0) {
                return (5.0 - valor) / 3.0;
                } else {
                return 0.0;
                }
                        } else if (strcmp(ritmo, "r�pido") == 0) {
                            if (valor <= 2.0) {
                            return 1.0;
                            } else if (valor <= 5.0) {
                            return (5.0 - valor) / 3.0;
                            } else {
                            return 0.0;
                            }
                        }
}

// Fun��o de pertin�ncia para instrumento
float pertinenciaInstrumento(float valor, const char* instrumento) {
    if (strcmp(instrumento, "guitarra") == 0) {
        if (valor <= 3.0) {
        return 0.0;
        } else if (valor <= 7.0) {
        return (valor - 3.0) / 4.0;
        } else {
        return 1.0;
        }
            } else if (strcmp(instrumento, "piano") == 0) {
                if (valor <= 3.0) {
                return 0.0;
                } else if (valor <= 7.0) {
                return (valor - 3.0) / 4.0;
                } else {
                return 1.0;
                }
                        } else if (strcmp(instrumento, "bateria") == 0) {
                            if (valor <= 3.0) {
                            return 0.0;
                            } else if (valor <= 7.0) {
                            return (valor - 3.0) / 4.0;
                            } else {
                            return 1.0;
                            }
                                 }
}

// Fun��o para calcular a recomenda��o fuzzy
float calcularRecomendacao(float genero, float ritmo, float instrumento) {

    float pertinenciaGeneroRock = pertinenciaGenero(genero, "rock");
    float pertinenciaGeneroPop = pertinenciaGenero(genero, "pop");
    float pertinenciaGeneroJazz = pertinenciaGenero(genero, "jazz");

    float pertinenciaRitmoLento = pertinenciaRitmo(ritmo, "lento");
    float pertinenciaRitmoModerado = pertinenciaRitmo(ritmo, "moderado");
    float pertinenciaRitmoRapido = pertinenciaRitmo(ritmo, "r�pido");

    float pertinenciaInstrumentoGuitarra = pertinenciaInstrumento(instrumento, "guitarra");
    float pertinenciaInstrumentoPiano = pertinenciaInstrumento(instrumento, "piano");
    float pertinenciaInstrumentoBateria = pertinenciaInstrumento(instrumento, "bateria");



    float mediaPertinencias = (pertinenciaGeneroRock + pertinenciaGeneroPop + pertinenciaGeneroJazz +
                               pertinenciaRitmoLento + pertinenciaRitmoModerado + pertinenciaRitmoRapido +
                               pertinenciaInstrumentoGuitarra + pertinenciaInstrumentoPiano +
                               pertinenciaInstrumentoBateria) / 9.0;

    return mediaPertinencias;
}

// Fun��o para recomendar uma m�sica com base nas prefer�ncias do usu�rio
void recomendarMusica(float preferenciaGenero, float preferenciaRitmo, float preferenciaInstrumento) {

    // Calcular a recomenda��o fuzzy
    float recomendacao = calcularRecomendacao(preferenciaGenero, preferenciaRitmo, preferenciaInstrumento);

    // Verificar o grau de pertin�ncia da recomenda��o e apresentar a m�sica recomendada
    if (recomendacao >= 0.8) {
        printf("Recomenda��o: M�sica A\n");
        printf("G�nero: Rock\n");
        printf("Ritmo: Lento\n");
        printf("Instrumento: Guitarra\n");
            } else if (recomendacao >= 0.5) {
                printf("Recomenda��o: M�sica B\n");
                printf("G�nero: Pop\n");
                printf("Ritmo: Moderado\n");
                printf("Instrumento: Piano\n");
                            } else if (recomendacao >= 0.3) {
                                printf("Recomenda��o: M�sica C\n");
                                printf("G�nero: Jazz\n");
                                printf("Ritmo: R�pido\n");
                                printf("Instrumento: Bateria\n");
                            } else {
                                            printf("N�o foi poss�vel encontrar uma recomenda��o adequada.\n");
                                        }
                                        printf("Com base nas suas prefer�ncias, recomendamos a m�sica com grau de pertin�ncia %.2f\n", recomendacao);
                                    }

int main() {
    setlocale(LC_ALL, "Portuguese");

    float preferenciaGenero;
    float preferenciaRitmo;
    float preferenciaInstrumento;

    // Obter as prefer�ncias do usu�rio
    printf("Informe sua prefer�ncia para o g�nero (0-10): ");
    scanf("%f", &preferenciaGenero);
    printf("Informe sua prefer�ncia para o ritmo (0-10): ");
    scanf("%f", &preferenciaRitmo);
    printf("Informe sua prefer�ncia para o instrumento (0-10): ");
    scanf("%f", &preferenciaInstrumento);

    // Recomendar uma m�sica com base nas prefer�ncias do usu�rio
    recomendarMusica(preferenciaGenero, preferenciaRitmo, preferenciaInstrumento);

    return 0;
}
