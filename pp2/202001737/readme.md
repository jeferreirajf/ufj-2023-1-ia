# Avaliação Projeto Prático 2 - IA
Alunos: **202001737**.

## Roteiro de avaliação

Abaixo seguem os principais critérios e as respectivas pontuações utilizados como avaliação do trabalho.

1. Geração de solução inicial: **0.6 pontos**
2. Geração de vizinhança: **0.6 pontos**
3. Entendimento do problema: **0.5 pontos**
4. Entendimento geral da busca local: **0.6 pontos**
5. Boas práticas de programação: **0.2 pontos**

## Notas

A seguir, seguem as pontuações atingidas pelo trabalho (Total máximo 2.5 pontos): 

1. 0.6 pontos
2. 0.6 pontos
3. 0.5 pontos
4. 0.6 pontos
5. 0.1 pontos

**Total:** 2.4 pontos.

## Comentários

Nesta seção, seguem comentários pertinentes sobre o trabalho.

### Pontos Neutros
- Implementação de um *simulated annealing*;
- Solução inicial pode estourar a restrição de capacidade;
- Se uma solução estoura a restrição de capacidade em uma unidade ou em mil unidades, é penalizada na mesma proporção;
- Método limitado por número de iterações máximas;

### Pontos Negativos
- Identificadores em português;
- `malloc` da linha 130 alocando `sizeof(*atualSolução)` não faz sentido;
- Mistura de `camel case` com `snake case`;
- `solucao` foi um péssimo nome para o método principal;

### Pontos Positivos
- Bom uso de constantes;
- Boa geração de solução inicial;
- Boa escolha no movimento;
- Geração de vizinhança satisfatória;
- Correto resfriamento de temperatura;
- Correta análise de probabilidade de trabalhar com uma solução pior;
- No geral, *simulated annealing* muito bem implementado, só faltou um carinho na calibração do parâmetro `alpha`;
