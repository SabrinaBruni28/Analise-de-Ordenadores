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
void Print_Lista(Lista_Palavra* listpalav, int n, int j);
void Bolha (Lista_Palavra lista, int n);
void BolhaMelhorado (Lista_Palavra lista, int n);
void Selecao (Lista_Palavra list, int n);
void Insercao (Lista_Palavra list, int n );
void Shellsort (Lista_Palavra list, int n);
void Particao(int Esq, int Dir, int *i, int *j, Lista_Palavra *lista);
void Ordena(int Esq, int Dir, Lista_Palavra *lista);
void QuickSort(Lista_Palavra list, int n);
void Constroi(Lista_Palavra* lista, int *n);
void Refaz(int Esq, int Dir, Lista_Palavra* lista);
void Heapsort(Lista_Palavra* list, int n);
void Ordenacao(Lista_Palavra* lista, int n);
