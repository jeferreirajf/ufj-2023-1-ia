#include <stdio.h>
#include <stdlib.h>

// Alunos: 201806158 e 202001732

int resolve(int hora, int dia, int chega, int impar, int tempo){
    //função de pertinência
    float valorhora[7] = {0.5,1,0.75,0,1,1,0,0.25};
    float valordia[4] = {0.75,1,1,0.5,0.25};
    float valorchega[3] = {1,0.75,0.5,0};
    float valorimpar[1] = {1,0.5};
    float valortempo[2] = {1,0.75,0.25};
    
    float resolve = (valorhora[hora] + valordia[dia] + valorchega[chega] + valorimpar[impar] + valortempo[tempo])/5;
    
    //função de inferência
    if(resolve <= 0.25){
        printf("\nVoce provavelmente consiguira pegar o CAJ!");
    }else if(resolve <= 0.5 && resolve > 0.25){
        printf("\nVoce tem uma chance razoavel de pegar o CAJ!");
    }else if(resolve <= 0.75 && resolve > 0.5){
        printf("\nVoce tem uma baixa chance de pegar o CAJ, e provavelmente tera de ir em pe!");
    }else{
        printf("\nVoce provavelmente nao conseguira pegar o CAJ!");
    }
}

int main()
{
    int horario, diasemana, horachegada, periodoimpar, tempoperiodo;

    printf("\nBom dia!\n");
    printf("\nQual horário pretende pegar o caj?");
    printf("\nSelecione uma das opcoes abaixo:\n0- 06:25 \n1- 07:10 \n2- 09:00 \n3- 10:00 \n4- 13:00 \n5- 15:00 \n6- 16:00 \n7- 18:00\n");
    scanf("%i",&horario);
    printf("\nSelecione qual dia da semana: \nSelecione uma das opcoes abaixo: \n0- Segunda-Feira \n1- Terça-Feira \n2- Quarta-Feira \n3- Quinta-Feira \n4- Sexta-Feira\n");
    scanf("%i",&diasemana);
    printf("\nQual Horario ira chegar? \nSelecione uma das opcoes abaixo:\n0- No horario \n1- 10 Minutos antes \n2- Meia-Hora antes \n3- Uma Hora antes\n");
    scanf("%i",&horachegada);
    printf("\nVoce esta em periodo impar?  0- Sim  1-não\n");
    scanf("%i",&periodoimpar);
    printf("\nEm qual parte do periodo voce esta?\nSelecione uma das opcoes abaixo: \n0- No inicio do periodo?  \n1- No meio do periodo?  \n2- No final do periodo?\n");
    scanf("%i",&tempoperiodo);
    
    resolve(horario, diasemana, horachegada, periodoimpar, tempoperiodo);


    return 0;
}


