#include <stdio.h>
#include <stdlib.h>

int *merge(int *a, int N, int *b, int M) 
{   
    int *c = malloc((N+M)*sizeof(int));
    int i = 0, j = 0, k;
    for (k = 0; k < N+M; k++) {
        if (i == N) {
           c[k] = b[j++];
           continue;
        }
        if (j == M) {
           c[k] = a[i++];
           continue;
        }
        if ((a[i] < b[j])) c[k] = a[i++];
        else c[k] = b[j++];
    }
    return c;
}

int main(){

    int n = 0;
    int vetor1[1000000], *vetor2;
    int numero, tamvetor2 = 0;

    while(n < 8){
        scanf("%d", &numero);
            for(int i = 0; i < numero; i++){
                scanf("%d", &vetor1[i]);
            }

        vetor2 = merge(vetor1, numero, vetor2, tamvetor2);
        tamvetor2 = tamvetor2 + numero;
        n++;
    }
            

    for(int l = 0; l < tamvetor2; l++){
        if( l == tamvetor2-1){
            printf("%d\n", vetor2[l]);
        }
        else{
            printf("%d ", vetor2[l]);
        }
    }

    return 0;
}