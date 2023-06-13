#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "admin.h"

void inserir_novo_admin(int total_admins, ADMIN admins[]){
	FILE *fp = NULL;
	fp = fopen("admins.txt", "a");
	if(fp == NULL){
		printf("Erro ao abrir o ficheiro de registo de jogadores");
		return;
	}
	printf("\tIntroduza o username do admin: ");
	fflush(stdin);
	gets(admins[total_admins].user);
	printf("\tIntroduza a password: ");
	gets(admins[total_admins].passwd);
	fprintf(fp,"%s;",admins[total_admins].user);
	fprintf(fp,"%s;\n",admins[total_admins].passwd);
	fclose(fp);
	total_admins++;
	login_admin(total_admins, admins);
}

void funcao_admins(char username[]){
	int opcao = -1;
	while(opcao != 0){
		printf("\t\t Sessao iniciada como admin [user: %s]\n\n", username);
		printf("[1] - Gerir o tabuleiro\n");
		printf("[2] - Gerir as perguntas\n");
		printf("[0] - Logout\n");
		scanf("%i", &opcao);
		switch(opcao){
			case 1:{
				gerirtabuleiro();
				break;
			}
			case 2:{
				ELEMM *iniELEMM=NULL;
				ELEMM *fimELEMM=NULL;
				lerPerguntasBinario(&iniELEMM, &fimELEMM);
				printf("\t\t Sessao iniciada como admin [user: %s]\n\n", username);
				printf("[1] - Adicionar Pergunta\n");
				printf("[2] - Remover Pergunta\n");
				printf("[3] - Listar Perguntas\n");
				int opcao2 = 0;
				scanf("%i", &opcao2);
				switch(opcao2){
					case 1:{
						criarPerguntaMultipla(iniELEMM,fimELEMM);
						break;
					}
					case 2:{
						removerPerguntaMultipla(&iniELEMM,&fimELEMM);
						break;
					}
					case 3:{
						listarPerguntasMultipla(iniELEMM);
						break;
					}
				}
				break;
			}
			case 0:{
				return;
				break;
			}
		}
	}
}


int lerficheiroAdmins(ADMIN admins[]) {
    FILE *fp = NULL;
    fp = fopen("admins.txt", "r");
    if (fp == NULL) {
        printf("Erro ao abrir o ficheiro de registo de jogadores");
        return 0;
    }
    int i = 0;
    while (i < MAX_ADMINS && fscanf(fp, "%[^;];%[^;];\n", admins[i].user, admins[i].passwd) != EOF) {
        i++;
    }
    fclose(fp);
    return i;
}

void login_admin(int total_admins,ADMIN admins[]){
	char username[50], password[50];
    char user[50], passwd[50];
    int found = 0; // flag para indicar se o admin foi encontrado

    printf("Introduza o username do admin: ");
    fflush(stdin);
    gets(username);
    printf("Introduza a password do admin: ");
    gets(password);
	int i = 0;
	for(i = 0;i < total_admins; i++){
		if(strcmp(username , admins[i].user) == 0 && strcmp(password , admins[i].passwd) == 0){
			found = 1;
		}
	}

	if (found == 1) {
    	printf("O admin com username %s foi encontrado.\n", username);
    	funcao_admins(username);
	} 
	else {
    	printf("O admin com username %s nao foi encontrado, e necessario registar o mesmo\n", username);
    	inserir_novo_admin(total_admins,admins);	
	}
	return;
}
