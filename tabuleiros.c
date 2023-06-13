#include "tabuleiros.h"


int gerirtabuleiro(){
	int opcao = 0;
	printf("Deseja mudar que tabuleiro: \n");
	printf("[1] - Tabuleiro S (Primeiras 20 casas)\n");
	printf("[2] - Tabuleiro M (Primeiras 30 casas)\n");
	printf("[3] - Tabuleiro L (Primeiras 50 casas)\n");
	fflush(stdin);
	scanf("%i", &opcao);
	int casa = 0;
	printf("No tabuleiro %c deseja alterar que casa: ");
	scanf("%i", &casa);
	switch (opcao){
		case 1:{
			printf("Numero de casas a avancar/recuar antigo: %i\n", casas1[casa - 1]);
			printf("Introduza o novo numero de casas a avancar/recuar: ");
			fflush(stdin);
			int num = 0;
			scanf("%i", &num);
			casas1[casa - 1] = num;
			break;
		}
		case 2:{
			printf("Numero de casas a avancar/recuar antigo: %i\n", casas2[casa - 1]);
			printf("Introduza o novo numero de casas a avancar/recuar: ");
			fflush(stdin);
			int num = 0;
			scanf("%i", &num);
			casas2[casa - 1] = num;			
			break;
		}
		case 3:{
			printf("Numero de casas a avancar/recuar antigo: %i\n", casas1[casa - 1]);
			printf("Introduza o novo numero de casas a avancar/recuar: ");
			fflush(stdin);
			int num = 0;
			scanf("%i", &num);
			casas3[casa - 1] = num;			
			break;
		}
	}
	return 1;
}
int escolher_tabuleiro(JOGADOR players[], int qtd, int total_jogadores){
	int opcao = 0;
	printf("\tEscolha de tabuleiro\n[1] - Tabuleiro com %i casas\n[2] - Tabuleiro com %i casas\n[3] - Tabuleiro com %i casas\n", casas_tabuleiro1, casas_tabuleiro2, casas_tabuleiro3);
	scanf("%i", &opcao);
	switch(opcao){
		case 1:{
			tabuleiro(players, qtd, casas1, casas_tabuleiro1, total_jogadores);
			break;
		}
		case 2:{
			tabuleiro(players, qtd, casas2, casas_tabuleiro2, total_jogadores);
			break;
		}
		case 3:{
			tabuleiro(players, qtd, casas3, casas_tabuleiro3, total_jogadores);
			break;
		}
	}
}

int tabuleiro(JOGADOR players[], int qtd, int casa[], int n_casas, int total_jogadores){
	ELEMM *iniELEMM=NULL;
	ELEMM *fimELEMM=NULL;
	lerPerguntasBinario(&iniELEMM, &fimELEMM);
	char resposta[100];
	int i = 0;
	int j= 0;
	players[0].posicao = 0;
	players[1].posicao = 0;
	players[2].posicao = 0;
	players[3].posicao = 0;
	while((players[0].posicao + 1) <= n_casas && (players[1].posicao + 1) <= n_casas && (players[2].posicao + 1) <= n_casas && (players[3].posicao + 1) <= n_casas){
		for(i = 0; i < qtd; i++){
			players[i].resposta_errada = 0;
			while(players[i].resposta_errada == 0 && players[i].posicao < n_casas){
				system("cls");
				printf("======================\n");
				for(j = 0;j<qtd;j++){
					printf("Username: %s\n", players[j].user);
					printf("Posicao atual [%i]\n", players[j].posicao + 1);
					printf("Perguntas respondidas: %i\n", players[j].perguntas_respondidas);
				}
				printf("======================\n\n");
				
				printf("Vez de: %s\n", players[i].user);
				printf("Informacao da casa %i:\n",players[i].posicao +1);
				printf("Casas a avancar/recuar: %i\n",casa[players[i].posicao]);
				iniELEMM = imprimirPerguntas(iniELEMM);
				fflush(stdin);
				printf("Resposta: ");
				gets(resposta);
				players[i].perguntas_respondidas++;
				if(verificarRespostaCorreta(iniELEMM,resposta) == 1){
					//verificar se a resposta tá correta
					players[i].posicao += casa[players[i].posicao];
				}
				else if(players[i].posicao > 0){
					players[i].posicao -= casa[players[i].posicao];
					players[i].resposta_errada = 1;
					if(players[i].posicao < 0){
						players[i].posicao = 0;
					}
				}
				if(players[i].posicao == n_casas - 1){
						printf("VENCEDOR - %s\n", players[i].user);
						escreverficheiro(total_jogadores,jogadores,qtd,players);
						JOGO jogo;
						char *data = dataAtual();
						strcpy(jogo.data,data);
						jogo.n_jogadores = qtd;
						switch(n_casas){
							case casas_tabuleiro3:{
								jogo.tipotabuleiro = 3;
								break;
							}
							case casas_tabuleiro2:{
								jogo.tipotabuleiro = 2;
								break;
							}
							case casas_tabuleiro1:{
								jogo.tipotabuleiro = 1;
								break;
							}
						}
						strcpy(jogo.vencedor, players[i].user);
	
						int total_jogos = lerficheirojogos(jogos);
						// Ordenar a lista de jogos
						ordenarjogos(total_jogos, jogos, jogo);
						return 1;
				}
			}
		}
	}
}

char* dataAtual() {
    time_t t = time(NULL);
    struct tm *data = localtime(&t);
    static char dataStr[11]; // String para armazenar a data formatada (dia/mês/ano)

    strftime(dataStr, sizeof(dataStr), "%d/%m/%Y", data);

    return dataStr;
}
