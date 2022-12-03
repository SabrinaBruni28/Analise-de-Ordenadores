
void Shellsort (Item* A, int n){
    int i, j;
    int h = 1;
    Item aux;
    do h = h * 3 + 1; while (h < n);
    do{
        h = h/3;
        for( i = h ; i < n ; i++ ){
            aux = A[i]; j = i;
            while (A[j - h].Chave > aux.Chave){
                A[j] = A[j - h]; j -= h;
                if (j < h) 
                    break;
            }
            A[j] = aux;
        }
    } while (h != 1);
}