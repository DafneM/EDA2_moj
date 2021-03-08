#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge(int *v1, int left, int middle, int right){

    int *v2 = malloc((right-left+1)*sizeof(int));
    int i = left;
    int j = middle + 1;
    int k = 0;

    while(i<=middle && j<=right){

      if(v1[i] <= v1[j]){
        v2[k] = v1[i];
        k++, i++;
      }
      else{
          v2[k] = v1[j];
          k++, j++;
      }

    }

    while(i<=middle){
        v2[k] = v1[i];
        k++, i++;
    }
    while(j<=right){
        v2[k] = v1[j];
        k++, j++;
    }

    k = 0;
    for(i = left; i<=right; i++){
        v1[i] = v2[k];
        k++;
    }

    free(v2);
}

void mergesort(int *v, int left, int right){

    if(left>=right)
      return;

    int middle = (left+right)/2;

    mergesort(v, left, middle);
    mergesort(v, middle+1, right);
    merge(v, left, middle, right);
}

int main(){
    int qtdelem, num, i = 0;
    int numfind;
    int cont = 0;
    int tamv2 = 0;
    int j = 0;


    //runtime pode ser por conta do tamanho da string

    int *v2 = malloc(1*sizeof(int));

    while(scanf("%d", &num) != EOF){
        v2[tamv2] = num;
        tamv2++;
        v2 = (int*)realloc(v2, (tamv2+1)*sizeof(int));
    }

    mergesort(v2, 0, tamv2-1);

    for(int m=0; m<tamv2; m++){
        if(m == tamv2 - 1)
          printf("%d\n", v2[m]);
        else 
          printf("%d ", v2[m]);
    }

    return 0;
}