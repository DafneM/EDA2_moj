#include <stdio.h>

void bubblesort(int *v, int l, int r){
    int aux;
    for(int i=l; i<r; i++){
        for(int j=l+1; j<=r; j++){
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

    bubblesort(v, 0, i-1);

    return 0;
}