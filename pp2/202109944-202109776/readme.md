# Avaliação Projeto Prático 2 - IA
Alunos: **202109944** e **202109776**.

## Roteiro de avaliação

Abaixo seguem os principais critérios e as respectivas pontuações utilizados como avaliação do trabalho.

1. Geração de solução inicial: **0.6 pontos**
2. Geração de vizinhança: **0.6 pontos**
3. Entendimento do problema: **0.5 pontos**
4. Entendimento geral da busca local: **0.6 pontos**
5. Boas práticas de programação: **0.2 pontos**

## Notas

A seguir, seguem as pontuações atingidas pelo trabalho (Total máximo 2.5 pontos): 

1. 0.2 pontos
2. 0.2 pontos
3. 0.5 pontos
4. 0.1 pontos
5. 0.1 pontos

**Total:** 1.1 pontos.

## Comentários

Nesta seção, seguem comentários pertinentes sobre o trabalho.

### Pontos Neutros
- Utiliza a solução construtiva ótima para construir a solução inicial
- Solução atual só é atualizada caso encontre uma solução que supere a melhor encontrada até então;

### Pontos Negativos
- Utiliza a solução construtiva ótima para construir a solução inicial;
- If da linha 59 não faz sentido;
- O if da linha 82 prioriza soluções com mais peso, quer dizer, se as soluções possuem valores totais iguais, a solução com maior peso prevalece;
- Existe uma evidente confusão nos conceitos de busca local;
- Os cálculos das linhas 106--112 poderiam ter sido feitos com a função calculate_fitness;
- Cada iteração do método resolve o problema, ou seja, o problema é resolvido `max_iterations` vezes.

### Pontos Positivos
- Modelagem do problema ok;
- Identificadores semânticos;
- Tentativa de implementar uma Busca Tabu (com erros).