import random

def valor_total(sol, valores):
  return sum(valores[i] for i, selected in enumerate(sol) if selected)


def peso_total(sol, pesos):
  return sum(pesos[i] for i, selected in enumerate(sol) if selected)
 

#se o peso total dos itens selecionados exceder o limite peso_max, a funcao retorna 0, que eh uma penalizacao por solucoes invalidas.
def funcao_objetivo(sol, valores, pesos, peso_max):
  total_valor = valor_total(sol, valores)
  total_peso = peso_total(sol, pesos)
  if total_peso > peso_max:
    return 0  #penalizacao de soluções inválidas
  return total_valor


def solucao_inicial(n):
  return [random.randint(0, 1) for _ in range(n)]


def vizinhos(sol):
  n = len(sol)
  viz = []
  for i in range(n):
    viz.append(sol[:])  #copia a solucao atual para a lista
    viz[i][i] = 1 - sol[i]  #troca o valor da posição i por seu complemento
  return viz


#a busca local utilizada gera uma solução inicial aleatoria e depois explora vizinhos dessa solução, se tiver uma solucao melhor atualiza a solucao, depois se repete ate nao tem o que melhorar
def busca_local(valores, pesos, peso_max):
  n = len(valores)  #itens
  s = solucao_inicial(n)  #cria uma solução inicial aleatoria
  fo = funcao_objetivo(s, valores, pesos,
                       peso_max)  #calcula a funcao objetivo da solução inicial
  melhoria = True
  while melhoria:
    melhoria = False
    v = vizinhos(s)  #gera uma lista de vizinhos da solucao atual
    for s_linha in v:
      fo_linha = funcao_objetivo(s_linha, valores, pesos, peso_max)
      if fo_linha > fo:
        s = s_linha
        fo = fo_linha
        melhoria = True
        break
  return s


#Item 1: 10 de valor, e 5 de peso
#Item 2: 15 de valor, e 10 de peso
#Item 3: 20 de valor, e 15 de peso
#Item 4: 25 de valor, e 20 de peso
#Item 5: 30 de valor, e 25 de peso
#peso_max corresponde ao peso que o ladrao suporta
valores = [10, 15, 20, 25, 30]
pesos = [5, 10, 15, 20, 25]
peso_max = 40

solucao = busca_local(valores, pesos, peso_max)

#a logica utilizada dentro do vetor eh uma logica booleana, ou seja "1" se coletei o item e "0" se nao coletei
print("Itens selecionados:", solucao)
print("\nLucro total:", valor_total(solucao, valores))
print(f"Peso utilizado da mochila: {peso_max} de {peso_total(solucao, pesos)}")
