
void Constroi(Item *A, int *n){
    int Esq;
    Esq = *n / 2 + 1;
    while (Esq > 1){
        Esq--;
        Refaz(Esq, *n, A);
    }
}


void Refaz(int Esq, int Dir, Item *A){
    int j = Esq * 2;
    Item aux = A[Esq];
    while (j <= Dir){
        if ((j < Dir)&&(A[j].Chave < A[j+1].Chave)) 
            j++;
        if (aux.Chave >= A[j].Chave) 
            break;
        A[Esq] = A[j];
        Esq = j; j = Esq * 2;
    }
    A[Esq] = aux;
}


void Heapsort(Item *A, int *n){ 
    int Esq, Dir;
    Item aux;
    Constroi(A, n); /* constroi o heap */
    Esq = 1; 
    Dir = *n;
    while (Dir > 1){ /* ordena o vetor */
        aux = A[1]; 
        A[1] = A[Dir]; 
        A[Dir] = aux;
        Dir--;
        Refaz(Esq, Dir, A);
    }
}
