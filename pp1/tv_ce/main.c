// Alunos:202013022 e 202012985
// Tema:Locadora onde ela com base nos filmes que você aluga ela recomenda os filmes com os generos dos filmes escolhidos pra você.



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define T_NOME 60
#define T_GENERO 90

#define Q_FILMES 6

struct container_filme
{
    char nome[T_NOME];
    char genero[T_GENERO];
    int codigo;
    int disponivel;
    float avaliacao;
    int vezes_alugado;
};

// mostra os dados dos filmes
void inicia_filmes(struct container_filme *f)
{
    // Definição dos filmes com seus respectivos gêneros, códigos, disponibilidade e avaliações
    sprintf(f[0].nome, "Tubalhao A ssasino");
    sprintf(f[0].genero, "Terror, acao, suspense");
    f[0].codigo = 302;
    f[0].disponivel = 1;
    f[0].avaliacao = 4.5;
    f[0].vezes_alugado = 0;

    sprintf(f[1].nome, "Pneu assasino, a onda de atropelamentos");
    sprintf(f[1].genero, "Terror, comedia");
    f[1].codigo = 343;
    f[1].disponivel = 5;
    f[1].avaliacao = 3.8;
    f[1].vezes_alugado = 0;

    sprintf(f[2].nome, "Stuck guy");
    sprintf(f[2].genero, "Comedia, acao, aventura");
    f[2].codigo = 375;
    f[2].disponivel = 3;
    f[2].avaliacao = 4.2;
    f[2].vezes_alugado = 0;

    sprintf(f[3].nome, "A.I, inteligencia artificial");
    sprintf(f[3].genero, "Ficcao cientifica, suspense");
    f[3].codigo = 356;
    f[3].disponivel = 2;
    f[3].avaliacao = 4.0;
    f[3].vezes_alugado = 0;

    sprintf(f[4].nome, "Crepusculo, a guerra de lob lob");
    sprintf(f[4].genero, "Ficcao cientifica, romance, acao");
    f[4].codigo = 316;
    f[4].disponivel = 4;
    f[4].avaliacao = 4.1;
    f[4].vezes_alugado = 0;

    sprintf(f[5].nome, "Rio, o cantar das araras azuis");
    sprintf(f[5].genero, "Musical, acao, aventura, infantil");
    f[5].codigo = 366;
    f[5].disponivel = 0;
    f[5].avaliacao = 3.5;
    f[5].vezes_alugado = 0;
}

// uma funçãozinha para listar os filmes
void listar_filmes(struct container_filme *filmes, int qtd_filmes)
{
    for (int contador = 0; contador < qtd_filmes; contador++)
    {
        printf("Informações do filme\n");
        printf("Nome: %s\n", filmes[contador].nome);
        printf("Gênero: %s\n", filmes[contador].genero);
        printf("Código: %i\n", filmes[contador].codigo);
        if (filmes[contador].disponivel)
        {
            printf("Tem sim meu bacana!\n");
        }
        else
        {
            printf("Cabo o estoque, mete marcha!\n");
        }
        printf("\n");
    }
}

// Função para calcular a pontuação fuzzy de recomendação de filmes com base no gênero alugado
float fuzzy_recomendar_filme(struct container_filme *filmes, int qtd_filmes, const char *genero_alugado)
{
    float grau_pertinencia = 0.0;

    for (int contador = 0; contador < qtd_filmes; contador++)
    {
        if (strcmp(filmes[contador].genero, genero_alugado) == 0 && filmes[contador].disponivel)
        {
            grau_pertinencia += filmes[contador].avaliacao;
        }
    }

    return grau_pertinencia;
}

// Função para recomendar filmes com base no gênero mais alugado pelo usuario ou sei lá mais quem vai usar
void recomendar_filmes(struct container_filme *filmes, int qtd_filmes)
{
    int max_alugueis = -1;
    int indice_max_alugueis = -1;

    // Encontra o gênero mais alugado pelo usuário
    for (int contador = 0; contador < qtd_filmes; contador++)
    {
        if (filmes[contador].vezes_alugado > max_alugueis)
        {
            max_alugueis = filmes[contador].vezes_alugado;
            indice_max_alugueis = contador;
        }
    }

    // Verifica se há um gênero mais alugado
    if (indice_max_alugueis != -1)
    {
        printf("Recomendação de filmes com base nos seus aluguéis anteriores:\n");
        printf("Gênero: %s\n", filmes[indice_max_alugueis].genero);

        // Calcula a pontuação fuzzy de recomendação
        float recom = fuzzy_recomendar_filme(filmes, qtd_filmes, filmes[indice_max_alugueis].genero);

        // Verifica se há filmes recomendados com base na pontuação fuzzy
        if (recom > 0)
        {
            printf("Filmes recomendados:\n");
            for (int contador = 0; contador < qtd_filmes; contador++)
            {
                if (strcmp(filmes[contador].genero, filmes[indice_max_alugueis].genero) == 0 && filmes[contador].disponivel)
                {
                    printf("Nome: %s (Avaliação: %.1f)\n", filmes[contador].nome, filmes[contador].avaliacao);
                }
            }
        }
        else
        {
            printf("Não há filmes recomendados para o gênero \"%s\".\n", filmes[indice_max_alugueis].genero);
        }
    }
    else
    {
        printf("Você ainda não alugou nenhum filme. Não há recomendações disponíveis.\n");
    }
}

int main(void)
{
    int opcao;
    struct container_filme filmes[Q_FILMES];

    // Inicializa os filmes com seus respectivos dados
    inicia_filmes(filmes);

    do {
        printf("Digite uma das opções abaixo\n");
        printf("1 - Listar filmes no sistema\n");
        printf("2 - Alugar filme\n");
        printf("3 - Recomendar filme\n");
        printf("4 - Sair\n");
        scanf("%i%*c", &opcao);

        switch (opcao) {
            case 1:
                listar_filmes(filmes, Q_FILMES);
                break;

            case 2:
                listar_filmes(filmes, Q_FILMES);

                printf("Digite o código do filme que você deseja alugar: ");
                int codigo;
                scanf("%i%*c", &codigo);

                int filme_encontrado = 0;
                for (int contador = 0; contador < Q_FILMES; contador++)
                {
                    if (codigo == filmes[contador].codigo && filmes[contador].disponivel)
                    {
                        filme_encontrado = 1;
                        filmes[contador].disponivel = 0;
                        printf("Filme \"%s\" alugado com sucesso!\n", filmes[contador].nome);
                        filmes[contador].vezes_alugado++;
                        break;
                    }
                }

                if (!filme_encontrado)
                {
                    printf("Filme não encontrado ou indisponível para alugar.\n");
                }
                break;

            case 3:
                recomendar_filmes(filmes, Q_FILMES);
                break;
        }
    } while (opcao != 4);

    return 0;
}