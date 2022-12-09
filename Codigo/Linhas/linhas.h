#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAMLIST 200

typedef struct{
    int linha[TAMLIST];
    int tam;
}Linhas;

void Cria_Linhas(Linhas * lin);
int Insere_linha(Linhas* lin, int n);
void Print_Linhas(Linhas* lin);
int Verifica_linha(Linhas* lin, int n);