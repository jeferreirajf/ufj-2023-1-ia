# Avaliação Projeto Prático 2 - IA
Alunos: **201902003** e **202001751**.

## Roteiro de avaliação

Abaixo seguem os principais critérios e as respectivas pontuações utilizados como avaliação do trabalho.

1. Geração de solução inicial: **0.6 pontos**
2. Geração de vizinhança: **0.6 pontos**
3. Entendimento do problema: **0.5 pontos**
4. Entendimento geral da busca local: **0.6 pontos**
5. Boas práticas de programação: **0.2 pontos**

## Notas

A seguir, seguem as pontuações atingidas pelo trabalho (Total máximo 2.5 pontos): 

1. 0.1 pontos
2. 0.2 pontos
3. 0.5 pontos
4. 0.1 pontos
5. 0.1 pontos

**Total:** 1.0 pontos.

## Comentários

Nesta seção, seguem comentários pertinentes sobre o trabalho.

### Pontos Neutros
- Semente do `srand` foi definida no início mas a função `rand` nunca foi utilizada;

### Pontos Negativos
- Identificadores em português;
- A solução inicial considera todos os itens pegos;
- O cálculo da função objetivo soma o valor de todos os itens, independente se a capacidade da mochila é ultrapassada;
- A condição de parada não está definida, acabou ficando `n*n` iterações por acaso;
- Confusão nos conceitos de `busca local` e `busca`;

### Pontos Positivos
- Boa divisão do código em funções/procedimentos;
- No geral, nomes semânticos;
- Boa modelagem do problema.