#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

/*
Discentes: 202001751, 201902003
Tema: Recomenda��o de g�neros mais adequados de filmes
*/

//fun��o infer�ncia
float comparation(float pontuacaoAcao,float pontuacaoComedia,float pontuacaoTerror, float pontuacaoRomance)
{
	if(pontuacaoAcao > pontuacaoComedia && pontuacaoAcao > pontuacaoTerror && pontuacaoAcao > pontuacaoRomance)
	{
		return printf("\nO g�nero mais adequado para voc� �: A��o ");
	}
	else if(pontuacaoComedia > pontuacaoAcao && pontuacaoComedia > pontuacaoTerror && pontuacaoComedia > pontuacaoRomance)
	{
		return printf("\nO g�nero mais adequado para voc� �: Com�dia ");
	}
	else if(pontuacaoTerror > pontuacaoComedia && pontuacaoTerror > pontuacaoAcao && pontuacaoTerror > pontuacaoRomance)
	{
		return printf("\nO g�nero mais adequado para voc� �: Terror ");
	}
	else
	{
		return printf("\nO g�nero mais adequado para voc� �: Romance ");
	}
	
}
int main() 
{
	int opcao;
	float pontuacaoAcao = 0,pontuacaoComedia = 0, pontuacaoTerror = 0, pontuacaoRomance = 0;
	float alto = 1,medio = 0.5,baixo = 0.2;
	
	setlocale(LC_ALL, "Portuguese");
	
	printf("\n---------------Bem Vindo a recomendacao de filmes---------------\n");		
	printf("Voc� prefere filmes que oferecem emo��es intensas e cenas de luta emocionantes, ou prefere hist�rias leves com muita com�dia e momentos engra�ados? \n");
	printf("Informe 1 para primeira opcao, e 0 para segunda\n");
	fflush(stdin);
	scanf("%d",&opcao);
	
	
	//fun��o pertin�ncia
	if(opcao == 1)
	{
		pontuacaoAcao += alto;
		pontuacaoComedia += baixo;
		pontuacaoTerror += baixo;
		pontuacaoRomance +=baixo;
	}
	else
	{
		pontuacaoComedia += alto;
		pontuacaoTerror += baixo;
		pontuacaoRomance +=baixo;
		pontuacaoAcao += baixo;
	}
	
	printf("Voc� prefere aqueles filmes com finais felizes e cenas rom�nticas, ou hist�rias mais complexas e dram�ticas? \n");
	printf("Informe 1 para primeira opcao, e 0 para segunda\n");
	
	fflush(stdin);
	scanf("%d",&opcao);
	
	//fun��o pertin�ncia
	if(opcao == 1)
	{
		pontuacaoAcao += baixo;
		pontuacaoComedia += medio;
		pontuacaoTerror += baixo;
		pontuacaoRomance +=alto;
	}
	else
	{
		pontuacaoComedia += baixo;
		pontuacaoTerror += alto;
		pontuacaoRomance +=medio;
		pontuacaoAcao += baixo;
	}
	
	printf("Voc� gosta de filmes que provocam sustos e adrenalina, ou prefere tramas mais psicol�gicas e misteriosas?\n");
	printf("Informe 1 para primeira opcao, e 0 para segunda\n");
	
	fflush(stdin);
	scanf("%d",&opcao);
	
	//fun��o pertin�ncia
	if(opcao == 1)
	{
		pontuacaoAcao += medio;
		pontuacaoComedia += baixo;
		pontuacaoTerror += alto;
		pontuacaoRomance +=baixo;
	}
	else
	{
		pontuacaoComedia += baixo;
		pontuacaoTerror += alto;
		pontuacaoRomance +=medio;
		pontuacaoAcao += baixo;
	}
	
	printf("Voc� gosta de filmes com protagonistas carism�ticos e cheios de a��o, ou prefere um elenco engra�ado e situa��es c�micas?\n");
	printf("Informe 1 para primeira opcao, e 0 para segunda\n");
	
	fflush(stdin);
	scanf("%d",&opcao);
	
	if(opcao == 1)
	{
		pontuacaoAcao += alto;
		pontuacaoComedia += medio;
		pontuacaoTerror += baixo;
		pontuacaoRomance +=baixo;
	}
	else
	{
		pontuacaoComedia += alto;
		pontuacaoTerror += baixo;
		pontuacaoRomance += baixo;
		pontuacaoAcao += baixo;
	}
	
	printf("Voc� prefere filmes com enredos originais e surpreendentes, ou prefere aqueles que seguem uma f�rmula mais tradicional?\n");
	printf("Informe 1 para primeira opcao, e 0 para segunda\n");
	
	fflush(stdin);
	scanf("%d",&opcao);
	
	if(opcao == 1)
	{
		pontuacaoAcao += medio;
		pontuacaoComedia += baixo;
		pontuacaoTerror += medio;
		pontuacaoRomance +=baixo;
	}
	else
	{
		pontuacaoComedia += medio;
		pontuacaoTerror += medio;
		pontuacaoRomance += alto;
		pontuacaoAcao += baixo;
	}
		
	//Teste para verificar o valor de cada pontua��o
	//printf("%f, %f, %f,%f",pontuacaoAcao, pontuacaoComedia,pontuacaoTerror, pontuacaoRomance);
	
	comparation(pontuacaoAcao, pontuacaoComedia, pontuacaoTerror, pontuacaoRomance);
		
	
}

