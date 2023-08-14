#include <stdio.h>

/*
Alunos: 202001737 e 202001721
*/

// nivel de poder
#define FRACO 0
#define MEDIO 1
#define FORTE 2

// Função de pertinencia
float Velocidade(float velocidade) {
    if (velocidade >= 0 && velocidade <= 50) {
        return velocidade / 50.0;
    } else if (velocidade > 50 && velocidade <= 100) {
        return 1.0;
    } else if (velocidade > 100 && velocidade <= 150) {
        return (150.0 - velocidade) / 50.0;
    } else {
        return 0.0;
    }
}

// Função de pertinência 
float Forca(float forca) {
    if (forca >= 0 && forca <= 50) {
        return forca / 50.0;
    } else if (forca > 50 && forca <= 100) {
        return 1.0;
    } else if (forca > 100 && forca <= 150) {
        return (150.0 - forca) / 50.0;
    } else {
        return 0.0;
    }
}

// Função de pertinência
float Inteligencia(float inteligencia) {
    if (inteligencia >= 0 && inteligencia <= 50) {
        return inteligencia / 50.0;
    } else if (inteligencia > 50 && inteligencia <= 100) {
        return 1.0;
    } else if (inteligencia > 100 && inteligencia <= 150) {
        return (150.0 - inteligencia) / 50.0;
    } else {
        return 0.0;
    }
}

// Função de pertinência 
float Magia(float magia) {
    if (magia >= 0 && magia <= 50) {
        return magia / 50.0;
    } else if (magia > 50 && magia <= 100) {
        return 1.0;
    } else if (magia > 100 && magia <= 150) {
        return (150.0 - magia) / 50.0;
    } else {
        return 0.0;
    }
}

// função de inferencia
int classificarPoder(float velocidade, float forca, float inteligencia, float magia) {
    float Fraco = 0.0;
    float Medio = 0.0;
    float Forte = 0.0;


    Fraco = (Velocidade(velocidade) + Forca(forca)) / 2.0;

    Medio = (Velocidade(velocidade) + Forca(forca) + Inteligencia(inteligencia)) / 3.0;

    Forte = (Forca(forca) + Inteligencia(inteligencia) + Magia(magia)) / 3.0;
   
    if (Fraco >= Medio && Fraco >= Forte) {
        return FRACO;
    } else if (Medio >= Fraco && Medio >= Forte) {
        return MEDIO;
    } else {
        return FORTE;
    }
}

int main() {

    float velocidade, forca, inteligencia, magia;

    printf("Digite o nivel de velocidade do personagem (0-150): ");
    scanf("%f", &velocidade);

    printf("Digite o nivel de força do personagem (0-150): ");
    scanf("%f", &forca);

    printf("Digite o nivel de inteligencia do personagem (0-150): ");
    scanf("%f", &inteligencia);

    printf("Digite o nivel de magia do personagem (0-150): ");
    scanf("%f", &magia);

    int nivelPoder = classificarPoder(velocidade, forca, inteligencia, magia);

    switch (nivelPoder) {
        case FRACO:
            printf("O personagem provavelmente deve ter um nivel de poder Fraco.\n");
            break;
        case MEDIO:
            printf("O personagem provavelmente deve ter um nivel de poder Medio.\n");
            break;
        case FORTE:
            printf("O personagem provavelmente deve ter um nivel de poder Forte.\n");
            break;
        default:
            printf("Nível de poder desconhecido.\n");
            break;
    }

    return 0;
}