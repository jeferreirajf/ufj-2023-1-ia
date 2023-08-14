#Authors 
# 202001715
# 202001728

import requests
import json


def inferencia(nota):
    retorno=''
    #categoriza a classe de personagem pela nota
    if nota <= 0.14:
        print("Você se daria bem com Tank")
        retorno='Tank'
    elif nota <= 0.28:
        print("Você se daria bem com assassino")
        retorno='Assassin'
    elif nota <= 0.42:
        print("Você se daria bem com Suport")
        retorno='Suport'
    elif nota <= .56:
        print("Você se daria bem com Controller")
        retorno='Controller'
    elif nota <= .70:
        print("Você se daria bem com Damage Dealer")
        retorno='Damage Dealer'
    elif nota <= .84:
        print("Você se daria bem com Marksman")
        retorno='Marksman'
    else:
        print("Você se daria bem com mago")
        retorno='Artillery'

    return retorno
        
        
def pertinencia(notas,pesos=None):
    if pesos == None:
        pesos=[1 for i in notas]
    nota=0
    q=0
    
    #laco que soma o produto de todas as notas pelo peso
    for i,valor in enumerate(notas):
        nota+=valor*pesos[i]
        q+=1
        
    return nota/q
    

def buscar_dados(tipo):
    request = requests.get("https://api.brawlapi.com/v1/brawlers")
    todo = json.loads(request.content)
    brawlers=todo['list']
    personagens=[]
    urls=[]
    for i in brawlers:
        if i['class']['name'] == tipo:
            personagens.append(i['name'])
            urls.append(i['imageUrl'])
    print(f'Personagens da classe {tipo}: {personagens}')
    return urls






dados={  
    'Prefere brawler com quanto de vida?':['Muita','Média','Pouca'],
    'Prefere brawler com quanto de dano?':['Muito','Médio','Pouco'],
    'Prefere brawler com qual velocidade?':['Lento','Normal','Rápido'],
    'Prefere dar quanto apoio para seus aliados?':['Pouco','Médio','Muito'],
    'Prefere brawler com quanto de alcance?':['Pouco','Médio','Muito'],
    'Prefere brawler com quanto de recarga?':['Lento','Médio','Rápido'],
}

pesos=[1,1,1,1,1,1]
notas=[]


for mensagem,opcoes in dados.items():
    valor=None
    while valor not in opcoes:
        valor=input(f'{mensagem}{opcoes}:').title()
    nota=opcoes.index(valor)*0.5
    notas.append(nota)
    
  
tipo="Assassin"
    
tipo=inferencia(pertinencia(notas,pesos))   
buscar_dados(tipo)

