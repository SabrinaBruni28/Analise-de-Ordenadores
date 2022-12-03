#include "../Lista_Palavra/lista_palavra.h"

typedef struct{
    Lista_Palavra dicionario[26];
    int tam;
}Dicionario;

void Cria_Dicionario(Dicionario* dic);
void Constroi_Dicionario(Dicionario* dic, FILE* text);
void Imprime_Lista(Dicionario* dic, char letra, int n);
void Imprime_Dicionario(Dicionario* dic, int n);
int Verifica_Dicionario(Dicionario* dic, char letra);
int Insere_Lista(Dicionario* dic, Lista_Palavra* listpalav);
void Imprime_Linhas(Dicionario* dic, char* word);
int Tamanho_Dicionario(Dicionario* dic);
void Ordena_Dicionario(Dicionario* dic);