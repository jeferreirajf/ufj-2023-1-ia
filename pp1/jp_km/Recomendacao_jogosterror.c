/*
    NOMES: 202109944 e 202109776
    SISTEMA DE RECOMENDA��ES DE JOGOS de TERROR
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float pertinence;
float gameplay;
float terror;
float duration;

//Dura��o do jogo
void setduration(char* typeduration){
    if (strcmp(typeduration,"long") == 0){
        duration = 1;
    }
    else if (strcmp(typeduration,"mediun") == 0){
        duration = 0.5;
    }
    else{  //short
        duration = 0.1;
    }
}


//DIFICULDADE DA GAMEPLAY
void setgameplay(char* typegameplay){
    if (strcmp(typegameplay,"frenetic") == 0){
        gameplay = 1;
    }
    else if (strcmp(typegameplay,"hard") == 0){
        gameplay = 0.5;
    }
    else{  //casual
        gameplay = 0.1;
    }
}


//N�VEL DE TERROR
void setterror(char* typeterror){
    if (strcmp(typeterror,"terrifiyng") == 0){
        terror = 1;
    }
    else if (strcmp(typeterror,"terror") == 0){
        terror = 0.5;
    }
    else{  //sustinhos
        terror = 0.1;
    }
}

//Separar os inputs
void setinputs(char* typegameplay,char* typeterror,char* typeduration){
    setgameplay(typegameplay);
    setterror(typeterror);
    setduration(typeduration);
}


//realizar a media para a pertinencia
float fuzzypertinenceinferec(float gameplay,float terror,float duration){
    return (gameplay+terror+duration)/3;
}


//definir a inferencia
char* gameinferec(float pertinence){

   if (pertinence < 0.4){
    return "listadejogos1";
   }
   if (pertinence < 0.7){
    return "listadejogos2";
   }
    return "listadejogos3";
}

int main(){

    setinputs("hard","terror" ,"short");
    pertinence = fuzzypertinenceinferec(gameplay,terror,duration);
    printf("Game : %s",gameinferec(pertinence));

    return 0;
}
