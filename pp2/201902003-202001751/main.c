#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CAPACIDADE_MOCHILA 50

//**201902003** e **202001751**.

typedef struct
{
    int peso;
    int valor;
} Item;

int valorTotal(Item itens[], int n)
{
    int total = 0;

    for (int i = 0; i < n; i++)
        total += itens[i].valor;

    return total;
}

int pesoTotal(Item itens[], int n)
{
    int total = 0;

    for (int i = 0; i < n; i++)
        total += itens[i].peso;

    return total;
}

void buscaVizinhaMochila(Item itens[], int n)
{
    int melhorValor = valorTotal(itens, n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                Item itemTemp = itens[i];
                itens[i] = itens[j];
                itens[j] = itemTemp;

                int novoValor = valorTotal(itens, n);

                if (novoValor > melhorValor && pesoTotal(itens, n) <= CAPACIDADE_MOCHILA)
                    melhorValor = novoValor;
                else
                {
                    itemTemp = itens[i];
                    itens[i] = itens[j];
                    itens[j] = itemTemp;
                }
            }
        }
    }
}

int main()
{
    srand(time(NULL));
    int n;

    printf("Digite a quantidade de itens: ");
    scanf("%d", &n);

    Item *itens = malloc(n * sizeof(Item));

    printf("\nDigite o peso e o valor de cada item:\n");

    for (int i = 0; i < n; i++)
    {
        printf("\nItem %d:\n", i + 1);
        printf("Peso: ");
        scanf("%d", &itens[i].peso);

        printf("Valor: ");
        scanf("%d", &itens[i].valor);
    }

    buscaVizinhaMochila(itens, n);

    printf("\nItens selecionados:\n");

    for (int i = 0; i < n; i++)
    {
        if (itens[i].peso <= CAPACIDADE_MOCHILA)
            printf("Item %d: Peso %d, Valor %d\n", i + 1, itens[i].peso, itens[i].valor);
    }

    int valorTotalMochila = valorTotal(itens, n);

    printf("\nValor total da mochila: %d\n", valorTotalMochila);

    free(itens);

    return 0;
}
