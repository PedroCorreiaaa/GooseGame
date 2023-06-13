#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ADMINS 5
#include "perguntas.h"


typedef struct admin{
	char user[100];
	char passwd[100];
}ADMIN;

ADMIN admins[MAX_ADMINS];

int lerficheiroAdmins(ADMIN admins[]);
void inserir_novo_admin(int total_admins,ADMIN admin[]);
void login_admin(int total_admins,ADMIN admins[]);
void funcao_admins(char username[]);
