#include "palavra.h"

void Cria_Palavra(Palavra* palav){
    palav->palavra[0] = '\0';
    Cria_Linhas(&(palav->linhas));
}
int Set_palavra(Palavra* palav, char* word){
    strcpy(palav->palavra, word);
    return 0;
}
char* Get_palavra(Palavra* palav){
    return palav->palavra;
}
void Print_palavra(Palavra* palav){
    printf("Palavra: %s\n",palav->palavra);
}
void Print_Palavra(Palavra* palav){
    printf("Palavra: %s \n", palav->palavra);
    Print_Linhas(&(palav->linhas));
}