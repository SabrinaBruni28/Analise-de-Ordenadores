
void Particao(int Esq, int Dir, int *i, int *j, Item *A){
    Item pivo, aux;
    *i = Esq; *j = Dir;
    pivo = A[(*i + *j)/2]; /* obtem o pivo x */
    do{
        while (pivo.Chave > A[*i].Chave) 
            (*i)++;
        while (pivo.Chave < A[*j].Chave) 
            (*j)--;
        if (*i <= *j){
            aux = A[*i]; 
            A[*i] = A[*j]; 
            A[*j] = aux;
            (*i)++; 
            (*j)--;
        }
    } while (*i <= *j);
}


void Ordena(int Esq, int Dir, Item *A){
    int i,j;
    Particao(Esq, Dir, &i, &j, A);
    if (Esq < j) 
        Ordena(Esq, j, A);
    if (i < Dir) 
        Ordena(i, Dir, A);
}


void QuickSort(Item *A, int n){
    Ordena(0, n-1, A);
}