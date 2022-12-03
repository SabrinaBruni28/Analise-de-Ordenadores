#include "../Palavra/palavra.h"

typedef struct{
    Palavra lista[TAMLIST];
    int tam;
}Lista_Palavra;

void Cria_Lista_Palavra(Lista_Palavra* listpalav);
int Insere_Palavra(Lista_Palavra* listpalav, char* word, int linha);
int Remove_Palavra(Lista_Palavra* listpalav, char* word);
int Remove_Palavra_Final(Lista_Palavra* listpalav);
int Verifica_Palavra(Lista_Palavra* listpalav, char* word);
int Tamanho_Lista(Lista_Palavra* listpalav);
void Print_Lista(Lista_Palavra* listpalav, int n);