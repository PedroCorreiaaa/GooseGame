#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_JOGADORES 100


typedef struct jogador{
	int num;
	int dados;
	char user[100];
	char passwd[100];
	char nacionalidade[100];
	int posicao;
	int perguntas_respondidas;
	int idade;
	char data_ultimo_jogo[100];
	int resposta_errada;
}JOGADOR;

JOGADOR jogadores[MAX_JOGADORES];


int lerficheiroJogadores(JOGADOR jogadores[]);

void escreverficheiro(int total_jogadores, JOGADOR jogadores[], int qtd, JOGADOR players[]);

int escolher_tabuleiro(JOGADOR players[], int qtd, int total_jogadores);

int tabuleiro(JOGADOR players[], int qtd, int casa[],int , int total_jogadores);

JOGADOR inserir_novo_jogador(int total_jogadores, JOGADOR jogadores[]);

void listar_nome(int total_jogadores, JOGADOR jogadores[]);

void listar_idade(int total_jogadores, JOGADOR jogadores[]);

void listar_data(int total_jogadores, JOGADOR jogadores[]);

void login_jogadores(int total_jogadores, JOGADOR jogadores[]);

char* obterDataAtual();

