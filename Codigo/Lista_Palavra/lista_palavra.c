#include "lista_palavra.h"

void Cria_Lista_Palavra(Lista_Palavra* listpalav){
    listpalav->tam = 0;
}
int Insere_Palavra(Lista_Palavra* listpalav, char* word, int linha){
   int i = Verifica_Palavra(listpalav,word);
   if( i != -1){
       if(Verifica_linha(&(listpalav->lista[i].linhas),linha))
          return 1;
        else 
            Insere_linha(&(listpalav->lista[i].linhas),linha);
   }
    else{
        Palavra nova;
        Cria_Palavra(&nova);
        Set_palavra(&nova, word);
        Insere_linha(&(nova.linhas),linha);
        listpalav->lista[listpalav->tam] = nova;
        listpalav->tam++;
        return 0;
    }
}
int Remove_Palavra(Lista_Palavra* listpalav, char* word){
    int i = Verifica_Palavra(listpalav,word);
    if(i == -1){
        printf("@@@@ Palavra nao encontrada @@@@\n");
        return 1;
    }
    for(i; i < listpalav->tam; i++){
        listpalav->lista[i] = listpalav->lista[i+1];
    }
    listpalav->tam--;
    printf("**** Palavra removida ****\n");
    return 0;
}
int Remove_Palavra_Final(Lista_Palavra* listpalav){
    if(listpalav->tam == 0) return 1;
    listpalav->tam--;
    printf("**** Palavra removida ****\n");
    return 0;
}
int Verifica_Palavra(Lista_Palavra* listpalav, char* word){
    int i;
    for(i = 0; i<(listpalav->tam); i++)
        if(!(strcmp(listpalav->lista[i].palavra,word)))
            return i;
    return -1;
}
int Tamanho_Lista(Lista_Palavra* listpalav){
    return listpalav->tam;
}
void Print_Lista(Lista_Palavra* listpalav, int n){
    int i;
    if(n==1){
        for(i = 0; i < listpalav->tam; i++){
            Print_Palavra(&(listpalav->lista[i]));
        }
    }
    else{
        for(i = 0; i < listpalav->tam; i++){
            Print_palavra(&(listpalav->lista[i]));
        }
    }
}