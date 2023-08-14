// 202100878, 202100887
#include <stdio.h>

typedef struct {
    char titulo[100];
    int duracao;
    float popularidade;
    float genero;
} Filme;
//Função de pertinencia
Filme criarFilme(char titulo[], int duracao, float popularidade, float genero) {
    Filme novoFilme;
    strcpy(novoFilme.titulo, titulo);
    novoFilme.duracao = duracao;
    novoFilme.popularidade = popularidade;
    novoFilme.genero = genero;
    return novoFilme;
}

int main() {
    Filme filmes[5];
    
    // Criação dos filmes
    filmes[0] = criarFilme("Filme A", 0.9, 0.8, 1.0);
    filmes[1] = criarFilme("Filme B", 1.0, 0.7, 0.8);
    filmes[2] = criarFilme("Filme C", 0.5, 0.6, 0.0);
    filmes[3] = criarFilme("Filme D", 0.4, 0.9, 0.5);
    filmes[4] = criarFilme("Filme E", 0.6, 0.5, 0.4);
    
    // Perguntas ao usuário
    int duracaoPref;
    float popularidadePref, generoPref;
    printf("vc prefere um filme curto:0; grande:1; ou independe:0.5; ?: ");
    scanf("%d", &duracaoPref);
    printf("vc gosta de um filme muito popular:1; pouco popular:0;ou tanto faz:0.5  ");
    scanf("%f", &popularidadePref);
    printf("vc gosta de um filme com muito efeito especial:1.0;ou mais realista:0.0; ou talvez um que possa juntar um pouco de cada:0.5 ");
    scanf("%f", &generoPref);
    
    // Cálculo da pontuação para cada filme baseado nas preferências do usuário
    float pontuacao[5];
    for (int i = 0; i < 5; i++) {
        pontuacao[i] = fabs(filmes[i].duracao - duracaoPref) +
                       fabs(filmes[i].popularidade - popularidadePref) +
                       fabs(filmes[i].genero - generoPref);
    }
    
    //função de inferencia
    int filmeRecomendado = 0;
    float menorPontuacao = pontuacao[0];
    for (int i = 1; i < 5; i++) {
        if (pontuacao[i] < menorPontuacao) {
            filmeRecomendado = i;
            menorPontuacao = pontuacao[i];
        }
    }
    
    // Exibindo resultado
    printf("O filme recomendado é: %s\n", filmes[filmeRecomendado].titulo);
    
    return 0;
}