import numpy as np

def total_valu_size(packing, values, sizes, max_size):
  # calculo valor total e tamanho total de uma mochila
  total_value = 0.0  # total value of packing
  total_size = 0.0  # total size of packing
  n = len(packing) #qtd de itens
  for i in range(n):
    if packing[i] == 1:
      total_value += values[i]
      total_size += sizes[i]
  if total_size > max_size:  # ultrapassa capacidade da mochila, zera o valor de ganho
    total_value = 0.0
  return (total_value, total_size)

def adjacent(packing, rnd):
  # gerar uma nova configuração (ou "vizinho") com base na configuração atual com um pouco de aleatoriedade
  n = len(packing)
  result = np.copy(packing)
  i = rnd.randint(n)
  if result[i] == 0:
    result[i] = 1
  elif result[i] == 1:
    result[i] = 0
  return result

def solve(n_items, rnd, values, sizes, max_size, max_iter, start_temperature, alpha):

  # Calculo usando Simulated Annealing
  curr_temperature = start_temperature
  curr_packing = np.ones(n_items, dtype=np.int64) # Transforma tudo em 1 para tentar colocar tudo na mochila

  print("Chute inicial: ")
  print(curr_packing)
  print("\n")

  (curr_valu, curr_size) = total_valu_size(curr_packing, values, sizes, max_size) # olha o valor de ganho
  iteration = 0
  interval = (int)(max_iter / 10)
  while iteration < max_iter:
    adj_packing = adjacent(curr_packing, rnd)
    (adj_v, _) = total_valu_size(adj_packing, values, sizes, max_size)

    if adj_v > curr_valu:  # se adjacente é melhor
      curr_packing = adj_packing; curr_valu = adj_v
    else:          # se adjacente é pior
      accept_p = np.exp( (adj_v - curr_valu ) / curr_temperature )
      p = rnd.random()
      if p < accept_p:  # aceitar pior solução mesmo assim (evitar melhor local + causar aleatorização)
        curr_packing = adj_packing; curr_valu = adj_v

    if iteration % interval == 0:
      print("| iter = %6d | curr value = %7.0f | curr temp = %10.2f |" % (iteration, curr_valu, curr_temperature))

    if curr_temperature < 0.00001:
      curr_temperature = 0.00001
    else:
      curr_temperature *= alpha

    iteration += 1

  return curr_packing

def main():
  print("Maximizar o ganho com base nos itens e valor e capacidade da mochila ")


  # INSERIR DADOS DO PROBLEMA
  values = np.array([8, 12, 5, 10, 7, 15, 3, 20, 18]) #valores dos itens inseridos (pontuação)
  sizes = np.array([3, 7, 2, 5, 4, 6, 1, 9, 8]) #tamanho dos itens especificos (peso)
  max_size = 20 #tamanho total da capacidade que aceita na mochila (peso que pode aceitar)
  n_value = len(values) #pega a quantidade de itens automaticamente com base na quantidade de valores no array value

  # AMOSTRAGEM DOS DADOS INSERIDOS
  print("\nItem values: ")
  print(values)
  print("\nItem sizes: ")
  print(sizes)
  print("\nMax total size = %d " % max_size)

  # CONFIGURAÇÕES DO SIMULATED ANNEALING
  rnd = np.random.RandomState(5)  # valor aleatorio para randomização
  max_iter = 100000 # quantidade maxima de iterações para achar melhor valor
  start_temperature = 10000.0 #temperatura inicial, usada para controlar a probabilidade de aceitar uma solução pior em relação à solução atual
  alpha = 0.98 # controla a taxa de resfriamento da temperatura, quanto mair proximo de 1 faz com que a temperatura diminua lentamente

  print("\nConfigurações Selecionadas: ")
  print("max_iter = %d " % max_iter)
  print("start_temperature = %0.1f " % start_temperature)
  print("alpha = %0.2f \n" % alpha)

  packing = solve(n_value, rnd, values, sizes, max_size, max_iter, start_temperature, alpha)

  print("\nMELHOR JUNÇÃO DE ITENS ENCONTRADA: ")
  print("-=-=-=-=-=-=-=-=-=-=-=-=-=-=- ")
  print(packing)
  print("-=-=-=-=-=-=-=-=-=-=-=-=-=-=- \n")
  print("1 = Itens que devem ser pegos | 0 = Itens que não devem ser pegos")
  (total_value, total_size) = total_valu_size(packing, values, sizes, max_size)
  print("\nValor máximo encontrado para valor = %0.1f " % total_value)
  print("Valor máximo encontrado para tamanho = %0.1f " % total_size)

if __name__ == "__main__":
  main()