#include <stdio.h>

void insertionsort(int *v, int l, int r){
    int aux;

    for(int i=r; i>l; i--){
        if(v[i-1]>v[i]){
            aux = v[i];
            v[i] = v[i-1];
            v[i-1] = aux;
        }
    }

    for(int i = l+2; i<=r; i++){

        int j = i; int elemento = v[j];

        while(elemento < v[j-1]){
             v[j]=v[j-1];
             j--;
        }
         v[j]=elemento;
    }


     for(int k=0; k<=r; k++){
        if(k == r)
            printf("%d\n", v[k]);
        else
            printf("%d ", v[k]);
    }
}

int main(){
    int num, i=0;
    int v[50001];

    while(scanf("%d", &num) != EOF){
        v[i] = num;
        i++;
    }

    

    insertionsort(v, 0, i-1);

    return 0;
}