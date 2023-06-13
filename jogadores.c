#include "jogadores.h"



int lerficheiroJogadores(JOGADOR jogadores[]) {
    FILE *fp = NULL;
    fp = fopen("jogadores.txt", "r");
    if (fp == NULL) {
        printf("Erro ao abrir o ficheiro de registo de jogadores");
        return 0;
    }
    int i = 0;
    while (i < MAX_JOGADORES && fscanf(fp, " %[^;];%[^;];%[^;];%i;%i;%[^;];\n", jogadores[i].user, jogadores[i].passwd, jogadores[i].nacionalidade, &jogadores[i].perguntas_respondidas, &jogadores[i].idade, jogadores[i].data_ultimo_jogo) != EOF) {
        i++;
    }
    fclose(fp);
    return i;
}



void escreverficheiro(int total_jogadores, JOGADOR jogadores[], int qtd, JOGADOR players[]) {
	FILE *fp = NULL;
	fp = fopen("jogadores.txt", "w");
	if (fp == NULL) {
		printf("Erro ao abrir o ficheiro de registo de jogadores");
		return;
	}
	int i = 0, j = 0;
	for (i = 0; i < qtd; i++) {
		for (j = 0; j < total_jogadores; j++) {
			if (strcmp(players[i].user, jogadores[j].user) == 0 && strcmp(players[i].passwd, jogadores[j].passwd) == 0) {
				jogadores[j] = players[i];	
			}
			fprintf(fp, "%s;", jogadores[j].user);
			fprintf(fp, "%s;", jogadores[j].passwd);
			fprintf(fp, "%s;", jogadores[j].nacionalidade);
			fprintf(fp, "%i;", jogadores[j].perguntas_respondidas);
			fprintf(fp, "%i;", jogadores[j].idade);
			fprintf(fp, "%s;\n", jogadores[j].data_ultimo_jogo);
		}
	}
	fclose(fp);
}

JOGADOR inserir_novo_jogador(int total_jogadores, JOGADOR jogadores[]){
    printf("\tIntroduza o username do jogador: ");
    fflush(stdin);
    gets(jogadores[total_jogadores].user);
    printf("\tIntroduza a password: ");
    gets(jogadores[total_jogadores].passwd);
    printf("\tIntroduza a nacionalidade: ");
    gets(jogadores[total_jogadores].nacionalidade);
    printf("\tIntroduza a idade do jogador: ");
    scanf("%i", &jogadores[total_jogadores].idade);
    return jogadores[total_jogadores];
}

void login_jogadores(int total_jogadores, JOGADOR jogadores[]){
	int qtd = 0;
	int i , j = 0;
	printf("Deseja jogar com quantos jogadores [1-4]: ");
	scanf("%i", &qtd);	
	int found;
	JOGADOR *players = NULL;
	players = (JOGADOR*)calloc(qtd,sizeof(JOGADOR)); 
	for(i=0;i<qtd;i++){
		printf("Introduza o username: ");
		fflush(stdin);
		gets(players[i].user);
		printf("Introduza a password: ");
		gets(players[i].passwd);
		for(j = 0; j < total_jogadores;j++){
			if(strcmp(players[i].user, jogadores[j].user) == 0 && strcmp(players[i].passwd, jogadores[j].passwd) == 0){
				found = 1;
				players[i] = jogadores[j];
				players[i].num = i + 1;
				printf("Login com sucesso\n");
				char *data = obterDataAtual();
				strcpy(players[i].data_ultimo_jogo, data);
				printf("[Jogador %i] - %s\n ", players[i].num, players[i].user);
			}

		}
		if(found != 1){
			printf("Nao existe um jogador com o seguinte username: %s\nE necessario registar o mesmo\n", players[i].user);
			players[i] = inserir_novo_jogador(total_jogadores,jogadores);
			total_jogadores++;
			players[i].num = i + 1;
			printf("O jogador com o username %s foi registado com sucesso\n", players[i].user);
			char *data = obterDataAtual();
			strcpy(players[i].data_ultimo_jogo, data);
			printf("[Jogador %i] - %s\n", players[i].num, players[i].user);
			
		}
		found = 0;
	}
	escolher_tabuleiro(players,qtd,total_jogadores);
	escreverficheiro(total_jogadores,jogadores,qtd,players);
	free(players);
}


void listar_nome(int total_jogadores, JOGADOR jogadores[]){
	JOGADOR aux;
	int i = 0;
	int j = 0;
	for(i = 0; i<total_jogadores;i++){
		for(j = 0; j<total_jogadores-1;j++){
			if(strcmp(jogadores[j].user,jogadores[j+1].user)>0){
				aux =  jogadores[j];
				jogadores[j] = jogadores[j+1];
				jogadores[j+1]= aux;
			}
		}
	}
	for(i = 0; i<total_jogadores;i++){
		printf("Username: %s\n", jogadores[i].user);
		printf("Idade: %i\n", jogadores[i].idade);
		printf("Nacionalidade: %s\n", jogadores[i].nacionalidade);
		printf("Numero de perguntas respondidas: %i\n", jogadores[i].perguntas_respondidas);
		printf("Data do ultimo jogo: %s", jogadores[i].data_ultimo_jogo);
	}
}

void listar_idade(int total_jogadores, JOGADOR jogadores[]){
	JOGADOR aux;
	int i = 0;
	int j = 0;
	for(i = 0; i<total_jogadores;i++){
		for(j = 0; j<total_jogadores-1;j++){
			if(jogadores[j].idade > jogadores[j+1].idade){
				aux =  jogadores[j];
				jogadores[j] = jogadores[j+1];
				jogadores[j+1]= aux;
			}
		}
	}
	for(i = 0; i<total_jogadores;i++){
		printf("Username: %s\n", jogadores[i].user);
		printf("Idade: %i\n", jogadores[i].idade);
		printf("Nacionalidade: %s\n", jogadores[i].nacionalidade);
		printf("Numero de perguntas respondidas: %i\n", jogadores[i].perguntas_respondidas);
		printf("Data do ultimo jogo: %s\n", jogadores[i].data_ultimo_jogo);
	}
}


void listar_data(int total_jogadores, JOGADOR jogadores[]) {
	
    int dia, mes, ano, dia2, mes2, ano2;
    
    JOGADOR aux;
    int i, j;
    for (i = 0; i < total_jogadores; i++) {
        for (j = 0; j < total_jogadores - 1; j++) {
            struct tm data1, data2;
            sscanf(jogadores[j].data_ultimo_jogo, "%d/%d/%d", &dia, &mes, &ano);
    		data1.tm_mday = dia;
   			data1.tm_mon = mes - 1;  // Os meses em struct tm são representados de 0 a 11
    		data1.tm_year = ano - 1900;
    		sscanf(jogadores[j + 1].data_ultimo_jogo, "%d/%d/%d", &dia2, &mes2, &ano2);
    		data2.tm_mday = dia2;
   			data2.tm_mon = mes2 - 1;  // Os meses em struct tm são representados de 0 a 11
    		data2.tm_year = ano2 - 1900;
            // Comparação das datas do último jogo
            if (mktime(&data1) < mktime(&data2)) {
                aux = jogadores[j];
                jogadores[j] = jogadores[j + 1];
                jogadores[j + 1] = aux;
            }
        }
    }
    for (i = 0; i < total_jogadores; i++) {
        printf("Username: %s\n", jogadores[i].user);
        printf("Idade: %i\n", jogadores[i].idade);
        printf("Nacionalidade: %s\n", jogadores[i].nacionalidade);
        printf("Numero de perguntas respondidas: %i\n", jogadores[i].perguntas_respondidas);
        printf("Data do ultimo jogo: %s\n", jogadores[i].data_ultimo_jogo);
    }
}



char* obterDataAtual() {
    time_t t = time(NULL);
    struct tm *data = localtime(&t);
    static char dataStr[11]; // String para armazenar a data formatada (dia/mês/ano)

    strftime(dataStr, sizeof(dataStr), "%d/%m/%Y", data);

    return dataStr;
}











