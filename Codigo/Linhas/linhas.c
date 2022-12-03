#include "linhas.h"

void Cria_Linhas(Linhas * lin){
    lin->tam = 0;
}
int Insere_linha(Linhas* lin, int n){
    if(lin->tam > TAMLIST) return 1;
    lin->linha[lin->tam] = n;
    lin->tam++;
    return 0;
}
void Print_Linhas(Linhas* lin){
    int i;
    printf("Linhas: ");
    for(i = 0; i <(lin->tam); i++){
        printf("|%d", lin->linha[i]);
    }
    printf("|\n");
}
int Verifica_linha(Linhas* lin, int n){
    int i;
    for(i = 0; i<(lin->tam); i++){
        if(lin->linha[i] == n){
            return 1;
        }
    }
    return 0;
}
