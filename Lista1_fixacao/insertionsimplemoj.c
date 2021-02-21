#include <stdio.h>

void insertionsortsimple(int *v, int l, int r){
    int aux, i, j;

    for(i=l+1; i<=r; i++){
        for(j=i; j>l; j--){
              if(v[j-1]>v[j]){
                aux = v[j-1];
                v[j-1] = v[j];
                v[j] = aux;
            }
        }
    }

     for(int k=0; k<=r; k++){
        if(k == r)
            printf("%d\n", v[k]);
        else
            printf("%d ", v[k]);
    }
}

int main(){
    int v[1001];
    int num, i=0;

    while(scanf("%d", &num) != EOF){
        v[i] = num;
        i++;
    }

    insertionsortsimple(v, 0, i-1);

    return 0;
}