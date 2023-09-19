# Avaliação Projeto Prático 2 - IA
Alunos: **202001732** e **201806158**.

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
2. 0.45 pontos
3. 0.5 pontos
4. 0.45 pontos
5. 0.15 pontos

**Total:** 2.15 pontos.

## Comentários

Nesta seção, seguem comentários pertinentes sobre o trabalho.

### Pontos Neutros
- Solução inicial pegando os primeiros itens;
- Condição de parada baseada se houve melhoria na solução atual;

### Pontos Negativos
- Identificadores em português;
- Condicional da linha 40 faz com que o método só tente realizar movimentos caso o item atual já esteja na mochila, quer dizer, o movimento fica limitado a obrigatoriamente ter que tirar um item da mochila para então tentar colocar outro. Isso faz sentido na primeira iteração `i=0`, depois disso, não necessariamente;
- Necessidade de aprofundar o conhecimento sobre movimentos e vizinhança;
- Vários comentários pertinentes no código periférico mas falta comentário no cerne do algoritmo (foram vocês que fizeram? Por que não comentaram então?);

### Pontos Positivos
- Identificadores suficientemente semânticos, com algumas ressalvas;
- Função `main` muito bonita e bem feita;
- No geral, boa divisão do código em `procedimentos` e `funções`;
- Apesar de alguns pequenos erros na modelagem do algoritmo, foi entregue uma `busca local`.