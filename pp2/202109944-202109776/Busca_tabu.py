class Item:
    
#Construtor
    def __init__(self, name, weight, value):
        self.name = name
        self.weight = weight
        self.value = value
        self.quantity = 1

#Calculo para peso e valor total
def calculate_fitness(selected_items):
    total_weight = 0
    for item, count in selected_items.items():
        total_weight += item.weight * count

    total_value = 0
    for item, count in selected_items.items():
        total_value += item.value * count

    return total_value, total_weight


def tabu_search(items, capacity, max_iterations=100):
    best_solution = {}
    tabu_list = {}
    
    #Verifica os vizinhos
    for _ in range(max_iterations):
        candidate_items = []
        for item in items:
            if item.quantity > 0:
                candidate_items.append(item)

        if not candidate_items:
            break
        
        candidate_items.sort(key=lambda item: item.value / item.weight, reverse=True)
        
        current_solution = {}
        current_weight = 0
        
        #Verifica se o item e valido para lista
        for item in candidate_items:
            #Calcula valor do item atual se ele cabe na mochila
            if current_weight + item.weight <= capacity and item.quantity > 0:
                count = min(item.quantity, (capacity - current_weight) // item.weight)
                #Retira os itens que estao na solucao
                if item in current_solution:
                    current_solution[item] += count
                else:
                    current_solution[item] = count
                current_weight += item.weight * count
                item.quantity -= count
                
        #Calculo dos itens selecionados
        current_fitness = calculate_fitness(current_solution)
        
        #Compara solucoes encontradaas
        if current_fitness > calculate_fitness(best_solution):
            best_solution = current_solution
        
        #Possivel melhor solucao e atribuida a uma lista e evita ser revisitada
        solution_key = str(current_solution)
        tabu_list[solution_key] = 1 #chave da solucao atual que nao deve ser revisitada
        
        
        neighbors = []
        #Cria uma lista dos vizinhos para comparacoes
        for item in items:
            if item.quantity > 0:
                neighbor_solution = dict(current_solution)
                neighbors.append(neighbor_solution)
        
        #Verifica o peso e o valor do vizinho para inserir na lista para atualizar 
        for neighbor in neighbors:
            if str(neighbor) not in tabu_list:
                neighbor_weight = 0
                for item, count in neighbor.items():
                    neighbor_weight += item.weight * count
                #Substitui item
                if neighbor_weight <= capacity:
                    if calculate_fitness(neighbor) > calculate_fitness(best_solution):
                        best_solution = neighbor
                        current_solution = neighbor
                        neighbor_key = str(neighbor)
                        tabu_list[neighbor_key] = 1
                        break
        
    return best_solution

def main():
    
    #Capacidade da mochila
    capacity = 4
    
    #Adicionar itens na lista: [NOME,PESO,VALOR]
    items = [
        Item("a",1,1),
        Item("b",2,2),
        Item("c",1,3),
        Item("d",4,4),
    ]
    
    solution = tabu_search(items, capacity)
    
    total_weight = 0
    for item, count in solution.items():
        total_weight += item.weight * count

    total_value = 0
    for item, count in solution.items():
        total_value += item.value * count
    
    print("\n======== Itens na mochila ========")
    for item, count in solution.items():
        print(f"Item: {item.name} | QTD: {count} | Kg Unidade {item.weight:.2f} | Preço Unidade R$: {item.value:.2f}")
    
    print(f"\nPeso total dos itens na mochila: {total_weight:.2f} Kg")
    print(f"Valor total dos itens na mochila: R$ {total_value:.2f}")

if __name__ == "__main__":
    main()
