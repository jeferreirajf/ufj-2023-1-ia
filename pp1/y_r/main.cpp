/*
NOME DA DUPLA:
202001754 e 202001750

TEMA:
Diagnóstico sobre a temperatura do computador.
*/

#include <iostream>
#include <string>
using namespace std;

struct {
  int min = 65;
  int max = 110;
} temp_Processador;

struct {
  int min = 5;
  int max = 50;
} temp_PlacaDeVideo;

struct {
  int min = 65;
  int max = 110;
} temp_MemRAM;

int entrada[3], quente, frio;

// FUNÇÃO DE PERTINÊNCIA
void temp() {
  if (entrada[0] >= temp_Processador.max)
    quente++;

  else
    frio++;

  if (entrada[1] >= temp_PlacaDeVideo.max)
    quente++;

  else
    frio++;

  if (entrada[2] >= temp_MemRAM.max)
    quente++;

  else
    frio++;
}

// FUNÇÃO DE INFERÊNCIA
void mediaTemp() {
  int mediaTemp = quente + frio / 2;
  if (mediaTemp > 2) {
    printf("A pontuação de tempetura do seu computador é: %d\n", mediaTemp);
    printf("\033[31mCrítico!\033[0;0m O seu computador pode sofrer danos caso "
           "você continue "
           "utilizando.\n");
  } else if (mediaTemp == 2) {
    printf("A pontuação de tempetura do seu computador é: %d\n", mediaTemp);
    printf("\033[31mRuim!\033[0;0m O seu computador está quente, mas você pode continuar utilizando para propósitos mais simples.\n");
  } else {
    printf("A pontuação de tempetura do seu computador é: %d\n", mediaTemp);
    printf("\033[32mBom!\033[0;0m Continue utilizando seu computador "
           "normalmente.\n");
  }
}

int main() {
  string peca[3] = {"Processador", "Placa de Vídeo", "Memória RAM"};

  cout << "[!] Diagnóstico de temperatura em computadores [!]" << endl;
  cout
      << "\nVamos verificar a temperatura dos seus componentes para determinar "
         "a necessidade de atenção aos dispositivos.\n"
      << endl;

  for (int i = 0; i < 3; i++) {
    cout << "Informe a temperatura atual do(a) " << peca[i] << ": ";
    cin >> entrada[i];
  }

  temp(); // FUNÇÃO DE PERTINÊNCIA
  mediaTemp(); // FUNÇÃO DE INFERÊNCIA

  return 0;
}
