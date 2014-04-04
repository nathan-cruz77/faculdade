void mergeSort_intercala(TItem *A, int p, int q, int r){
    int i, j, k;
    TItem *B;
    
    /* Aloca e popula o novo vetor */
    B = (TItem *) malloc(sizeof(TItem) * (r-p+1));
    for(i=p; i<=q; i++) B[i-p] = A[i];
    for(j=r; j>q; j--) B[j-p] = A[j];

    for(i=p, j=r, k=p; k<=r; k++){
        if(B[i-p].Chave <= B[j-p].Chave){
            A[k] = B[i-p];
            i++;
        }
        else{
            A[k] = B[j-p];
            j--;
        }
    }
    free(B);
}

void mergeSort_ordena(TItem *A, int p, int r){
    int q;

    if(p<r){
        q = (p+r)/2;
        mergeSort_ordena(A, p, q);
        mergeSort_ordena(A, q+1, r);
        mergeSort_intercala(A, p, q, r);
    }    
}

void mergeSort(TItem *A, int n){
    mergeSort_ordena(A, 0, n-1);
}
