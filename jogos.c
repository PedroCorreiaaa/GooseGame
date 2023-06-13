#include "jogos.h"

int lerficheirojogos(JOGO jogos[]) {
    FILE *fp = fopen("jogos.txt", "r");
    if (fp == NULL) {
        printf("Erro ao abrir o ficheiro de registo de jogos\n");
        return 0;
    }
    int i = 0;
    while (i < MAX_SIZE && fscanf(fp, " %[^;];%[^;];%i;%i;\n", jogos[i].data, jogos[i].vencedor, &jogos[i].tipotabuleiro, &jogos[i].n_jogadores) == 4) {
        i++;
    }
    fclose(fp);
    return i;
}


void ordenarjogos(int total_jogos, JOGO jogos[], JOGO ultimo) {
    int i;

    if (total_jogos == MAX_SIZE) {
        for (i = 0; i < MAX_SIZE - 1; i++) {
            jogos[i] = jogos[i+1]; // Desloca todos os jogos para a esquerda
        }
        jogos[MAX_SIZE - 1] = ultimo; // Adiciona o novo jogo no último elemento
    } else {
        jogos[total_jogos] = ultimo; // Adiciona o novo jogo no próximo índice disponível
        total_jogos++; // Incrementa o total de jogos
    }

    escreverficheirojogos(total_jogos, jogos);
}



	
void escreverficheirojogos(int total_jogos, JOGO jogos[]) {
    FILE *fp = fopen("jogos.txt", "w");
    if (fp == NULL) {
        printf("Erro ao abrir o ficheiro de registo de jogos\n");
        return;
    }
    int i;
    for (i = 0; i < total_jogos; i++) {
        fprintf(fp, "%s;%s;%d;%d;\n", jogos[i].data, jogos[i].vencedor, jogos[i].tipotabuleiro, jogos[i].n_jogadores);
    }
    fclose(fp);
}


