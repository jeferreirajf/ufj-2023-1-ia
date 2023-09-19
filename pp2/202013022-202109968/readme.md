# Avaliação Projeto Prático 2 - IA
Alunos: **202013022** e **202109968**.

## Roteiro de avaliação

Abaixo seguem os principais critérios e as respectivas pontuações utilizados como avaliação do trabalho.

1. Geração de solução inicial: **0.6 pontos**
2. Geração de vizinhança: **0.6 pontos**
3. Entendimento do problema: **0.5 pontos**
4. Entendimento geral da busca local: **0.6 pontos**
5. Boas práticas de programação: **0.2 pontos**

## Notas

A seguir, seguem as pontuações atingidas pelo trabalho (Total máximo 2.5 pontos): 

1. 0.4 pontos
2. 0.4 pontos
3. 0.5 pontos
4. 0.4 pontos
5. 0.15 pontos

**Total:** 1.85 pontos.

## Comentários

Nesta seção, seguem comentários pertinentes sobre o trabalho.

### Pontos Neutros
- Geração aleatória de solução inicial;
- Solução inicial pode estourar a restrição de capacidade;
- Atualização de solução atual só ocorre quando uma solução melhor é encontrada e a restrição de capacidade não é estourada;
- Condição de parada de máximo de iterações;

### Pontos Negativos
- Linha 48 evidentemente colocada no lugar errado comprometendo toda a geração de vizinhança;
- Método avalia `NUM_ITEMS` vezes o exato mesmo vizinho;
- Melhor vizinho nunca é atualizado caso a solução inicial estoure a restrição de capacidade por mais de um item, fazendo com que a solução atual se torne uma solução que não pega nenhum item;

### Pontos Positivos
- Identificadores em inglês;
- Uso consistente de `pascal case`;
- Boa escolha de movimento, apesar de erros na execução;
- Entendimento geral do método de `busca local` satisfatório, apesar dos vários erros que comprometem o desempenho do método.