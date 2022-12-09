#include <time.h>
#include "lista_palavra.h"
int comp, mov;

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
void Print_Lista(Lista_Palavra* listpalav, int n, int j){
    int i;
    if(n==1){
        for(i = j; i < listpalav->tam; i++){
            Print_Palavra(&(listpalav->lista[i]));
        }
    }
    else{
        for(i = j; i < listpalav->tam; i++){
            Print_palavra(&(listpalav->lista[i]));
        }
    }
}
void Bolha (Lista_Palavra list, int n){
    comp = 0;
    mov = 0;
    clock_t init_t, final_t;

    init_t = clock();
    int i, j;
    Lista_Palavra lista;
    Palavra aux;
    lista = list;
    for( i = 0 ; i < lista.tam -1 ; i++ ){
        for( j = 1 ; j < lista.tam -i ; j++ )
        {
            comp++;
            if ( (strcmp(lista.lista[j].palavra, lista.lista[j-1].palavra)) < 0 ){
                mov++;
                strcpy(aux.palavra,lista.lista[j].palavra);
                strcpy(lista.lista[j].palavra, lista.lista[j-1].palavra);
                strcpy(lista.lista[j-1].palavra, aux.palavra);
            }
        }
    }
    final_t = clock();
    Print_Lista(&lista, n, 0);
    printf("\nNumero de comparacoes: %d\nNumero de movimentacoes: %d\nTempo: %lf\n",
            comp, mov, (double)(final_t - init_t)/CLOCKS_PER_SEC
            );
}
void BolhaMelhorado (Lista_Palavra list, int n){
    comp = 0;
    mov = 0;
    clock_t init_t, final_t;

    init_t = clock();
    int i, j,troca;
    Lista_Palavra lista;
    Palavra aux;
    lista = list;
    for( i = 0 ; i < lista.tam -1 ; i++ ){
        troca = 0;
        for( j = 1 ; j < lista.tam -i ; j++ )
        {
            comp++;
            if ( (strcmp(lista.lista[j].palavra, lista.lista[j-1].palavra)) < 0 ){
                mov++;
                strcpy(aux.palavra,lista.lista[j].palavra);
                strcpy(lista.lista[j].palavra, lista.lista[j-1].palavra);
                strcpy(lista.lista[j-1].palavra, aux.palavra);
                troca = 1;
            }
        }
        if (troca == 0)
            break;
    }
    final_t = clock();
    Print_Lista(&lista, n, 0);
    printf("\nNumero de comparacoes: %d\nNumero de movimentacoes: %d\nTempo: %lf\n",
            comp, mov, (double)(final_t - init_t)/CLOCKS_PER_SEC
            );
}

void Selecao (Lista_Palavra list, int n){
    comp = 0;
    mov = 0;
    clock_t init_t, final_t;

    init_t = clock();
    int i, j, Min;
    Lista_Palavra lista;
    Palavra aux;
    lista = list;
    for (i = 0; i < lista.tam - 1; i++){
        Min = i;
        for (j = i + 1 ; j < lista.tam; j++)
        {
            comp++;
            if ( strcmp(lista.lista[j].palavra, lista.lista[Min].palavra) < 0)
                Min = j;
        }
        strcpy(aux.palavra,lista.lista[Min].palavra);
        strcpy(lista.lista[Min].palavra, lista.lista[i].palavra);
        strcpy(lista.lista[i].palavra, aux.palavra);
        mov++;
    }
    final_t = clock();
    Print_Lista(&lista, n, 0);
    printf("\nNumero de comparacoes: %d\nNumero de movimentacoes: %d\nTempo: %lf\n",
            comp, mov, (double)(final_t - init_t)/CLOCKS_PER_SEC
            );
}

void Insercao (Lista_Palavra list, int n ){
    comp = 0; 
    mov = 0;
    clock_t init_t, final_t;

    init_t = clock();
    int i,j;
    Lista_Palavra lista;
    Palavra aux;
    lista = list;
    for (i = 1; i < lista.tam; i++){
        strcpy(aux.palavra, lista.lista[i].palavra);
        j = i - 1;
        while ( ( j >= 0 ) && ( strcmp(aux.palavra, lista.lista[j].palavra) < 0 ) ){
            strcpy(lista.lista[j + 1].palavra, lista.lista[j].palavra);
            j--;
            comp++;
        }
        if( j >= 0 ) comp++;
        strcpy(lista.lista[j + 1].palavra, aux.palavra);
        mov++;
    }
    final_t = clock();
    Print_Lista(&lista, n, 0);
    printf("\nNumero de comparacoes: %d\nNumero de movimentacoes: %d\nTempo: %lf\n",
            comp, mov, (double)(final_t - init_t)/CLOCKS_PER_SEC
            );
}
void Shellsort (Lista_Palavra list, int n){
    comp = 0;
    mov = 0;
    clock_t init_t, final_t;

    init_t = clock();
    int i, j;
    int h = 1;
    Lista_Palavra lista;
    Palavra aux;
    lista = list;
    do h = h * 3 + 1; while (h < lista.tam);
    do{
        h = h/3;
        for( i = h ; i < lista.tam ; i++ ){
            strcpy(aux.palavra, lista.lista[i].palavra);
            j = i;
            while (strcmp(lista.lista[j - h].palavra, aux.palavra) > 0){
                comp++;
                strcpy(lista.lista[j].palavra, lista.lista[j - h].palavra); 
                j -= h;
                if (j < h) 
                    break;
            }
            comp++;
            strcpy(lista.lista[j].palavra, aux.palavra);
            mov++;
        }
    } while (h != 1);
    final_t = clock();
    Print_Lista(&lista, n, 0);
    printf("\nNumero de comparacoes: %d\nNumero de movimentacoes: %d\nTempo: %lf\n",
            comp, mov, (double)(final_t - init_t)/CLOCKS_PER_SEC
            );
}
void Particao(int Esq, int Dir, int *i, int *j, Lista_Palavra *lista){
    Palavra pivo, aux;
    *i = Esq; *j = Dir;
    strcpy(pivo.palavra, lista->lista[(*i + *j)/2].palavra); /* obtem o pivo x */
    do{
        while (strcmp(pivo.palavra, lista->lista[*i].palavra) > 0){
            (*i)++;
            comp++;
        }
        comp++;
        while (strcmp(pivo.palavra, lista->lista[*j].palavra) < 0){
            (*j)--;
            comp++;
        }
        comp++;
        if (*i <= *j){
            strcpy(aux.palavra, lista->lista[*i].palavra);
            strcpy(lista->lista[*i].palavra, lista->lista[*j].palavra);
            strcpy(lista->lista[*j].palavra, aux.palavra);
            mov++;
            (*i)++; 
            (*j)--;
        }
    } while (*i <= *j);
}
void Ordena(int Esq, int Dir, Lista_Palavra *lista){
    int i,j;
    Particao(Esq, Dir, &i, &j, lista);
    if (Esq < j) 
        Ordena(Esq, j, lista);
    if (i < Dir) 
        Ordena(i, Dir, lista);
}

void QuickSort(Lista_Palavra list, int n){
    comp = 0; 
    mov = 0;
    clock_t init_t, final_t;

    init_t = clock();
    Lista_Palavra lista;
    lista = list;
    Ordena(0, lista.tam -1, &lista);
    final_t = clock();
    Print_Lista(&lista, n, 0);
    printf("\nNumero de comparacoes: %d\nNumero de movimentacoes: %d\nTempo: %lf\n", comp, mov, (double)(final_t - init_t)/CLOCKS_PER_SEC);
}

void Constroi(Lista_Palavra* lista, int *n){
    int Esq;
    Esq = *n / 2 + 1;
    while (Esq > 1){
        Esq--;
        Refaz(Esq, *n, lista);
    }
}

void Refaz(int Esq, int Dir, Lista_Palavra* lista){
    int j = Esq * 2;
    Palavra aux;
    strcpy(aux.palavra, lista->lista[Esq].palavra);
    while (j <= Dir){
        if ((j < Dir)&&(strcmp(lista->lista[j].palavra, lista->lista[j+1].palavra) < 0)) 
            j++;
        if(j < Dir) comp++;
        comp++;
        if (strcmp(aux.palavra, lista->lista[j].palavra) >= 0) 
            break;
        strcpy(lista->lista[Esq].palavra, lista->lista[j].palavra);
        Esq = j; 
        j = Esq * 2;
    }
    strcpy(lista->lista[Esq].palavra, aux.palavra);
    mov++;
}

void Heapsort(Lista_Palavra* list, int n){ 
    comp = 0; 
    mov = 0;
    clock_t init_t, final_t;

    init_t = clock();
    int Esq, Dir, N, i;
    Lista_Palavra lista;
    Palavra aux;
    Cria_Lista_Palavra(&lista);
    for(i=0;i<list->tam;i++){
        lista.tam++;
        lista.lista[lista.tam] = list->lista[i];
    }
    N = lista.tam;
    Constroi(&lista, &N); /* constroi o heap */
    Esq = 1; 
    Dir = N;
    while (Dir > 1){ /* ordena o vetor */
        mov++;
        strcpy(aux.palavra, lista.lista[1].palavra);
        strcpy(lista.lista[1].palavra, lista.lista[Dir].palavra);
        strcpy(lista.lista[Dir].palavra, aux.palavra);
        Dir--;
        Refaz(Esq, Dir, &lista);
    }
    lista.tam++;
    final_t = clock();
    Print_Lista(&lista, n, 1);
    printf("\nNumero de comparacoes: %d\nNumero de movimentacoes: %d\nTempo: %lf\n",
            comp, mov, (double)(final_t - init_t)/CLOCKS_PER_SEC
            );
}

void Ordenacao(Lista_Palavra* lista, int n){
    int c;
    printf("\n[1]-Nao Ordenado\n[2]-Ordenacao Bolha\n[3]-Ordenacao Bolha Melhorado\n[4]-Ordenacao Selecao\n[5]-Ordenacao Insercao\n[6]-Ordenacao Shell\n[7]-Ordenacao Quick\n[8]-Ordenacao Heap\n");
    scanf("%d", &c);
    printf("#Palavras com a letra %c:\n",lista->lista->palavra[0]);
    switch (c){
    case 1:
        Print_Lista(lista, n, 0);
        break;
    case 2:
        Bolha(*lista, n);
        break;
    case 3:
        BolhaMelhorado(*lista, n);
        break;
    case 4:
        Selecao(*lista, n);
        break;
    case 5:
        Insercao(*lista, n);
        break;
    case 6:
        Shellsort(*lista, n);
        break;
    case 7:
        QuickSort(*lista, n);
        break;
    case 8:
        Heapsort(lista, n);
        break;
    }
}