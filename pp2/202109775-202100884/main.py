def imprimir_tabuleiro(tabuleiro):
    # Função para imprimir o tabuleiro de forma visual
    for linha in tabuleiro:
        for posicao, peca in enumerate(linha):
            # Imprime cada peça do tabuleiro, substituindo 'None' por espaço vazio
            print(f" {peca if peca is not None else ' '}", end="")
            if posicao < 2:
                print(" |", end="")  
        print("\n------------")  
def eh_estado_final(tabuleiro, objetivo):
    # Função para verificar se o tabuleiro é igual ao estado objetivo
    return tabuleiro == objetivo

def obter_vizinhos(tabuleiro):
    # Função para obter os tabuleiros vizinhos válidos
    vizinhos = []
    for i in range(3):
        for j in range(3):
            if tabuleiro[i][j] is None:
                for di, dj in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
                    ni, nj = i + di, j + dj
                    if 0 <= ni < 3 and 0 <= nj < 3:
                        novo_tabuleiro = [linha[:] for linha in tabuleiro]
                        novo_tabuleiro[i][j], novo_tabuleiro[ni][nj] = novo_tabuleiro[ni][nj], novo_tabuleiro[i][j]
                        vizinhos.append(novo_tabuleiro)
    return vizinhos

def dfs_limite(tabuleiro, objetivo, limite, caminho=[]):
    # Busca em profundidade com limite
    if eh_estado_final(tabuleiro, objetivo):
        return caminho + [tabuleiro]

    if limite == 0:
        return None

    for vizinho in obter_vizinhos(tabuleiro):
        if vizinho not in caminho:
            resultado = dfs_limite(vizinho, objetivo, limite - 1, caminho + [tabuleiro])
            if resultado is not None:
                return resultado

    return None

# Tabuleiro inicial e objetivo
tabuleiro_inicial = [
    [1, 2, 3],
    [4, 5, 6],
    [7, None, 8]
]

tabuleiro_objetivo = [
    [1, 2, 3],
    [4, 5, 6],
    [None, 7, 8]
]

profundidade_maxima = 30  # Define a profundidade máxima para a busca

# Execução da busca com limite de profundidade
solucao = dfs_limite(tabuleiro_inicial, tabuleiro_objetivo, profundidade_maxima)

# Impressão da solução
if solucao:
    for passo, tabuleiro in enumerate(solucao):
        print(f"Passo {passo + 1}:")
        imprimir_tabuleiro(tabuleiro)
        print()
else:
    print("Nenhuma solução encontrada dentro do limite de profundidade.")