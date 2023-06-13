#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jogadores.h"
#include "jogos.h"
#include "perguntas.h"


#define casas_tabuleiro1 20
#define casas_tabuleiro2 30
#define casas_tabuleiro3 50

#define casas_tabuleiro1 20
#define casas_tabuleiro2 30
#define casas_tabuleiro3 50



int casas3[casas_tabuleiro3] = {3,1,2,5,2,2,7,3,2,3,5,8,1,1,3,2,2,2,1,6,5,1,3,5,3,1,3,2,1,5,3,1,2,5,2,2,7,3,2,3,5,8,1,1,3,2,2,2,1,0};
int casas2[casas_tabuleiro2] = {3,1,2,5,2,2,7,3,2,3,5,8,1,1,3,2,2,2,1,6,5,1,3,5,3,1,3,2,1,5};
int casas1[casas_tabuleiro1] = {3,1,2,5,2,2,7,3,2,3,5,8,1,1,3,2,2,2,1,6};

int escolher_tabuleiro(JOGADOR players[], int qtd, int total_jogadores);
int tabuleiro(JOGADOR players[], int qtd, int casa[], int n_casas, int total_jogadores);
int gerirtabuleiro();
char* dataAtual();
