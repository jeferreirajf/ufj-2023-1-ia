# Avaliação Projeto Prático 2 - IA
Alunos: **202001719** e **201902024**.

## Roteiro de avaliação

Abaixo seguem os principais critérios e as respectivas pontuações utilizados como avaliação do trabalho.

1. Geração de solução inicial: **0.6 pontos**
2. Geração de vizinhança: **0.6 pontos**
3. Entendimento do problema: **0.5 pontos**
4. Entendimento geral da busca local: **0.6 pontos**
5. Boas práticas de programação: **0.2 pontos**

## Notas

A seguir, seguem as pontuações atingidas pelo trabalho (Total máximo 2.5 pontos): 

1. 0.5 pontos
2. 0.35 pontos
3. 0.5 pontos
4. 0.35 pontos
5. 0.2 pontos

**Total:** 1.9 pontos.

## Comentários

Nesta seção, seguem comentários pertinentes sobre o trabalho.

### Pontos Neutros
- Solução inicial criada de forma totalmente aleatória e penalização na função objetivo quando a solução estoura a restrição de capacidade;
- A solução atual só é atualizada caso encontre uma melhor na vizinhança imediata, caso não seja encontrado um vizinho imediatamente melhor, o método para imediatamente;

### Pontos Negativos
- O método não leva em consideração o quanto da restrição de capacidade é estourado, quer dizer, uma solução que ultrapasse a restrição de capacidade em uma unidade é penalizada na mesma quantidade que uma solução que ultrapasse a capacidade em 1000 unidades;
- Todos os vizinhos possíveis são gerados, o que torna a busca em uma busca quase exaustiva;
- O método pode facilmente gerar uma solução inicial que estoura em muito a capacidade e já terminar a execução em uma única iteração pois não haveria atualização da solução atual;
- Senti falta do código estar dividido em mais arquivos;
- Alguns identificadores ficaram muito ruins (por ex, `v`, `sLine`, `ofLine`, etc);
- Apesar de utilizar typescript, nada estava devidamente tipado.

### Pontos Positivos
- Boa indentação;
- Indentificadores em inglês;
- Modelagem do problema de forma simples e bem funcional;
- Apesar dos pequenos erros, é uma busca local sendo entregue (com problemas).