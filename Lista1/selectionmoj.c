#include <stdio.h>

void selectionsort(int *v, int l, int r){
    int aux;

    for(int i=l; i<r; i++){
        int menor=i;
        for(int j=i+1; j<=r; j++){
            if(v[j]<v[menor]){
                menor=j;
            }
        }
        aux = v[i];
        v[i] = v[menor];
        v[menor] = aux;
    }

    for(int k=0; k<=r; k++){
        if(k == r)
            printf("%d\n", v[k]);
        else
            printf("%d ", v[k]);
    }
}


int main(){
    int num;
    int v[1001], i;

    while(scanf("%d", &num) != EOF){
        v[i] = num;
        i++;
    }

    selectionsort(v, 0, i-1);

    return 0;
}