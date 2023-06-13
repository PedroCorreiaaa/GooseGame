#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_SIZE 30

typedef struct jogo{
	char data[100];
	char vencedor[100];
	int tipotabuleiro;
	int n_jogadores;

}JOGO;

JOGO jogos[MAX_SIZE];

int lerficheirojogos(JOGO jogos[]);
void ordenarjogos(int total_jogos, JOGO jogos[], JOGO novo_jogo) ;
void escreverficheirojogos(int total_jogos, JOGO jogos[]);








