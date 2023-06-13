#include "perguntas.h"

ELEMM* imprimirPerguntas(ELEMM* iniELEMM) {
    ELEMM* atual = iniELEMM;
    printf("Pergunta: %s\n", atual->PMULTIPLA.pergunta);
    printf("[A] - %s\n", atual->PMULTIPLA.respostaA);
    printf("[B] - %s\n", atual->PMULTIPLA.respostaB);
    printf("[C] - %s\n", atual->PMULTIPLA.respostaC);
    printf("[D] - %s\n", atual->PMULTIPLA.respostaD);
    atual = atual->seguinte;
    return atual;
}

void listarPerguntasMultipla(ELEMM *iniELEMM) {
    if (iniELEMM == NULL) {
        printf("A lista esta vazia. Nao ha perguntas para listar.\n");
        return;
    }

    ELEMM *atual = iniELEMM;
    while (atual != NULL) {
        printf("Pergunta: %s\n", atual->PMULTIPLA.pergunta);
        printf("Resposta A: %s\n", atual->PMULTIPLA.respostaA);
        printf("Resposta B: %s\n", atual->PMULTIPLA.respostaB);
        printf("Resposta C: %s\n", atual->PMULTIPLA.respostaC);
        printf("Resposta D: %s\n", atual->PMULTIPLA.respostaD);
        printf("Resposta Certa: %s\n", atual->PMULTIPLA.respostacerta);
        printf("\n");

        atual = atual->seguinte;
    }
}


int verificarRespostaCorreta(ELEMM *iniELEMM, char resposta[]) {
    ELEMM* atual = iniELEMM;
    while (atual != NULL) {
        if (strcmp(atual->PMULTIPLA.respostacerta, resposta) == 0) {
            return 1; // Resposta correta encontrada na lista
        }
        atual = atual->seguinte;
    }
    return 0; // Resposta incorreta (não encontrada na lista)
}



void criarPerguntaMultipla(ELEMM *iniELEMM, ELEMM *fimELEMM) {
    PMULTIPLA aux;
    printf("Introduza a pergunta: ");
    fflush(stdin);
    gets(aux.pergunta);

    printf("Introduza a resposta A: ");
    fflush(stdin);
    gets(aux.respostaA);

    printf("Introduza a resposta B: ");
    fflush(stdin);
    gets(aux.respostaB);

    printf("Introduza a resposta C: ");
    fflush(stdin);
    gets(aux.respostaC);

	printf("Introduza a resposta D: ");
    fflush(stdin);
    gets(aux.respostaD);

    printf("Introduza a resposta Certa: ");
    fflush(stdin);
    gets(aux.respostacerta);

    inserirPerguntaMultipla(&iniELEMM,&fimELEMM,aux);
    escreveBinMultipla(iniELEMM);
}

int inserirPerguntaMultipla(ELEMM **iniELEMM, ELEMM **fimELEMM, PMULTIPLA aux) {
    ELEMM *novo = NULL;

    novo = (ELEMM*)calloc(1, sizeof(ELEMM));
    if (novo == NULL) {
        printf("Out of memory!!!\n");
        return -1;
    }

    novo->PMULTIPLA = aux;
    novo->anterior = NULL;
    novo->seguinte = NULL;

    if (*iniELEMM == NULL) {
        *iniELEMM = novo;
        *fimELEMM = novo;
    } else {
        (*iniELEMM)->anterior = novo;
        novo->seguinte = *iniELEMM;
        *iniELEMM = novo;
    }

    return 0;
}

int removerPerguntaMultipla(ELEMM **iniELEMM, ELEMM **fimELEMM) {
    char pergunta[100];
    printf("Introduza a pergunta a remover: ");
    fflush(stdin);
    gets(pergunta);

    ELEMM* atual = *iniELEMM;
    while (atual != NULL) {
        if (strcmp(atual->PMULTIPLA.pergunta, pergunta) == 0) {
            if (atual->anterior != NULL) {
                atual->anterior->seguinte = atual->seguinte;
            } else {
                // Se o nó a ser removido é o primeiro da lista
                *iniELEMM = atual->seguinte;
            }
            if (atual->seguinte != NULL) {
                atual->seguinte->anterior = atual->anterior;
            } else {
                // Se o nó a ser removido é o último da lista
                *fimELEMM = atual->anterior;
            }
            escreveBinMultipla(*iniELEMM);
			return 1;
        }
        atual = atual->seguinte;
    }
    printf("Pergunta nao encontrada.\n");
    return 0; // Indica que a pergunta não foi encontrada
}




int escreveBinMultipla(ELEMM *iniELEMM) {
    if (iniELEMM == NULL) {
        printf("Não existem Respostas Multiplas para guardar!\n");
        return -1;
    }

    FILE *fp = fopen("PerguntasMultiplas.dat", "wb");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return -1;
    }

    ELEMM *aux = iniELEMM;
    while (aux != NULL) {
        fwrite(aux, sizeof(ELEMM), 1, fp);
        aux = aux->seguinte;
    }
    fclose(fp);

    return 0;
}

void lerPerguntasBinario(ELEMM **iniELEMM, ELEMM **fimELEMM) {
    FILE *fp = fopen("PerguntasMultiplas.dat", "rb");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return;
    }

    ELEMM pergunta;
    while (fread(&pergunta, sizeof(ELEMM), 1, fp) == 1) {
        inserirPerguntaMultipla(iniELEMM, fimELEMM, pergunta.PMULTIPLA);
    }
    fclose(fp);
}

