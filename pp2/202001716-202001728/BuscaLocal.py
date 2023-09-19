# Importa a biblioteca random para gerar números aleatórios
import random

# Lista de itens disponíveis para serem escolhidos
items = [
    {"weight": 8, "value": 6, 'name': "A", "amount": 1},
    {"weight": 5, "value": 3, 'name': "B", "amount": 1},
    {"weight": 2, "value": 1, 'name': "C", "amount": 1},
    {"weight": 6, "value": 7, 'name': "D", "amount": 1},
    {"weight": 9, "value": 10, 'name': "E", "amount": 1},
    {"weight": 4, "value": 4, 'name': "F", "amount": 1},
    {"weight": 5, "value": 3, 'name': "G", "amount": 1},
    {"weight": 8, "value": 8, 'name': "H", "amount": 1},
]

# Calcula o valor total dos itens selecionados
def total_value(items, taken_list):
    total = 0
    for i, _ in enumerate(taken_list):
        if taken_list[i] == 1:
            total += items[i]["value"]
    
    return total

# Calcula o peso total dos itens selecionados
def total_weight(items, taken_list):
    weight = 0
    
    for i, _ in enumerate(taken_list):
        if taken_list[i] == 1:
            weight += items[i]["weight"]
            
    return weight

# Gera a vizinhança de uma solução
def neighborhood(solution):
    neighborhood = []
    for i in range(len(solution)):
        neighbor = solution[:]
        neighbor[i] = 1 - neighbor[i]
        neighborhood.append(neighbor)
        
    return neighborhood

# Algoritmo de busca local para o problema da mochila
def knapsack(weight, iterations, items):
    items_taken = []
    
    # Inicializa a seleção de itens aleatoriamente
    while True:
        items_taken = [random.randint(0, 1) for i in items]
        if total_weight(items, items_taken) <= weight:
            break

        
    # Realiza iterações para melhorar a solução
    for i in range(iterations):
        neighbors = neighborhood(items_taken)
        
        for neighbor in neighbors:
            if total_weight(items, neighbor) <= weight:
                if total_value(items, neighbor) > total_value(items, items_taken):
                    items_taken = neighbor
               
    return items_taken

# Parâmetros do problema da mochila
capacity = 20
max_iterations = 1000

# Executa o algoritmo de busca local
items_taken = knapsack(capacity, max_iterations, items)

# Imprime os itens selecionados
print(items_taken)
for position,value in enumerate(items_taken):
    if value == 1:
        print(items[position]["name"],end=",")
