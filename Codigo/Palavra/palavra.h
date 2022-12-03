#include "../Linhas/linhas.h"
#define  TAMPALAV 50

typedef struct{
    char palavra[TAMPALAV];
    Linhas linhas;
}Palavra;

void Cria_Palavra(Palavra* palav);
int Set_palavra(Palavra* palav, char* word);
char* Get_palavra(Palavra* palav);
void Print_palavra(Palavra* palav);
void Print_Palavra(Palavra* palav);