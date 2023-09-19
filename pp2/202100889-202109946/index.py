import random

def total_vi(itens, selection):
    return sum(itens[i][1] for i in range(len(itens)) if selection[i] == 1)

def total_pi(itens, selection):
    return sum(itens[i][0] for i in range(len(itens)) if selection[i] == 1)

def bag_search(itens, C, max_iter):
    n = len(itens)
    current_solution = [random.choice([0, 1]) for _ in range(n)]
    current_vi = total_vi(itens, current_solution)
    current_pi = total_pi(itens, current_solution)

    for _ in range(max_iter):
        neighbor = current_solution.copy()
        i = random.randint(0, n - 1)
        neighbor[i] = 1 - neighbor[i]
        
        weight_neighbor = total_pi(itens, neighbor)
        if weight_neighbor <= C:
            value_neighbor = total_vi(itens, neighbor)
            if value_neighbor > current_vi:
                current_solution = neighbor
                current_vi = value_neighbor
                current_pi = weight_neighbor

    return current_solution, current_vi, current_pi

# Definições de valores
C = 15 # peso limite da mochila
itens = [(1, 10), (3, 12), (5, 14), (7, 16), (9, 18)]  # (Pi, Vi)
max_iter = 1000 # número de iterações
solution, value, weight = bag_search(itens, C, max_iter)

print("bag:", solution) # 1 - dentro da mochila / 0 - fora da mochila
print("value:", value)
print("weight:", weight)
if weight > C:
    print("o peso execedeu o limite da mochila")
else:
    print("o peso esta dentro do limite da mochila")
