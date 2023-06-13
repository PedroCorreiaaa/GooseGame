/*==========================================|
|===========================================|
|				Trabalho Prog				|
|Tema: The Goose Game						|
|Realizador: Pedro Martins Correia (Nª29241)|								
|===========================================|		
|==========================================*/


#include "jogadores.h"
#include "admin.h"
#include "jogos.h"


int menu(){
	int opcao = 0;
	printf("\t\t\t\t\t\tBem-vindo ao Jogo do Ganso\n\n\n");
	printf("\t[1] - Administrar\n");
	printf("\t[2] - Jogar\n");
	printf("\t[3] - Listar jogadores por ordem alfabetica do nome\n");
	printf("\t[4] - Listar jogadores por ordem decrescente de idade\n");
	printf("\t[5] - Listar jogadores por ordem decescente da data do jogo\n");
	printf("\t[0] - Sair\n");
	scanf("%i", &opcao);
	return opcao;
}

int main(){
	int total_admins = 0;
	int total_jogadores = 0;
	total_jogadores = lerficheiroJogadores(jogadores);
	total_admins= lerficheiroAdmins(admins);
	int i = 0;
	int opcao = -1;
	while(opcao != 0){
		opcao = menu();
		switch(opcao){
			case 1:{
				login_admin(total_admins,admins);
				break;
			}
			case 2:{
				login_jogadores(total_jogadores,jogadores);
				break;
			}
			case 3:{
				listar_nome(total_jogadores,jogadores);				
				break;
			}
			case 4:{
				listar_idade(total_jogadores,jogadores);
				break;
			}
			case 5:{
				listar_data(total_jogadores, jogadores);
				break;
			}
		}
	}	
	return 0;
}
