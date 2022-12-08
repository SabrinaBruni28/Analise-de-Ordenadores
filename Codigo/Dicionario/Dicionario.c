#include "Dicionario.h"

void Cria_Dicionario(Dicionario* dic){
    dic->tam = 0;
}
void Constroi_Dicionario(Dicionario* dic, FILE* text){
    char string[50], c;
    int num_linha = 1;
    int i;
    fflush(text);
   do{
        fscanf(text, "%s", string);
        c=fgetc(text);

        i = Verifica_Dicionario(dic, string[0]);
        if(i == -1){
            Lista_Palavra nova;
            Cria_Lista_Palavra(&nova);
            Insere_Palavra(&nova, string, num_linha);
            Insere_Lista(dic, &nova);
        }
        else{
            Insere_Palavra(&(dic->dicionario[i]), string, num_linha);
        }
        if(c == '\n') 
            num_linha++;
        if(c==EOF) 
            break;
    } while(!feof(text));
    Ordena_Dicionario(dic);
}
void Imprime_Lista(Dicionario* dic, char letra, int n){
    int i = Verifica_Dicionario(dic, letra);
    if(i == -1) printf("@@@@ Nao existe palavra com essa letra no Dicionario @@@@\n");
    else{
        Ordenacao(&(dic->dicionario[i]), n);
    }
}
void Imprime_Dicionario(Dicionario* dic, int c, int n){
    if(dic->tam == 0) printf("@@@@ Dicionario Vazio @@@@\n");
    int i;
    for(i = 0; i < dic->tam; i++){
        switch (c){
        case 1:
            Print_Lista(&(dic->dicionario[i]), n, 0);
            break;
        case 2:
            Bolha(dic->dicionario[i], n);
            break;
        case 3:
            BolhaMelhorado(dic->dicionario[i], n);
            break;
        case 4:
            Selecao(dic->dicionario[i], n);
            break;
        case 5:
            Insercao(dic->dicionario[i], n);
            break;
        case 6:
            Shellsort(dic->dicionario[i], n);
            break;
        case 7:
            QuickSort(dic->dicionario[i], n);
            break;
        case 8:
            Heapsort(&(dic->dicionario[i]), n);
            break;
        }
    }
}

int Verifica_Dicionario(Dicionario* dic, char letra){
    int i;
    for(i = 0; i < dic->tam; i++)
        if((dic->dicionario[i].lista[0].palavra[0]) == letra)
            return i;
    return -1;
}
int Insere_Lista(Dicionario* dic, Lista_Palavra* listpalav){
    dic->dicionario[dic->tam] = *listpalav;
    dic->tam++;
    return 0;
}
void Imprime_Linhas(Dicionario* dic, char* word){
    int i = Verifica_Dicionario(dic,word[0]);
    int j = Verifica_Palavra(&(dic->dicionario[i]), word);
    if(i == -1 || j ==-1) printf("@@@@ Palavra nao encontrada no dicionario @@@@\n");
    else{
        Palavra aux = dic->dicionario[i].lista[j];
        Print_Linhas(&(aux.linhas));
    }
}
int Tamanho_Dicionario(Dicionario* dic){
    int i, cont = 0;
    for(i = 0; i < dic->tam; i++)
        cont += Tamanho_Lista(&(dic->dicionario[i]));
    return cont;
}
void Ordena_Dicionario(Dicionario* dic){
    int n = dic->tam;
    int i,j;
    Lista_Palavra aux;
    for (i = 1; i < n; i++){
        aux = dic->dicionario[i];
        j = i - 1;
        while ( ( j >= 0 ) && ( strcmp(aux.lista[0].palavra, dic->dicionario[j].lista[0].palavra) < 0) ){
            dic->dicionario[j + 1] = dic->dicionario[j];
            j--;
        }
        dic->dicionario[j + 1] = aux;
    }
}
void Ordenacao_Dicionario(Dicionario* dic, int n){
    int i, c;
    printf("\n[1]-Nao Ordenado\n[2]-Ordenacao Bolha\n[3]-Ordenacao Bolha Melhorado\n[4]-Ordenacao Selecao\n[5]-Ordenacao Insercao\n[6]-Ordenacao Shell\n[7]-Ordenacao Quick\n[8]-Ordenacao Heap\n");
    scanf("%d", &c);
    Imprime_Dicionario(dic, c, n);
}