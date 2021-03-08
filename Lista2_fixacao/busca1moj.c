#include <stdio.h>
#include <stdlib.h>

int busca_binaria(int *v1, int qtdelem1, int numencontrar){

    int esq = -1;
    int dir = qtdelem1;

    while(esq < dir - 1){
        int meio = (dir+esq)/2;
        if(v1[meio] < numencontrar)
            esq = meio;
        else 
            dir = meio;
    }
    return dir;
}


int main(){
    int N, M;
    int i = 0, j = 0;
    int numpresente, numencontrar;
    int qtdelem1 = 0, qtdelem2 = 0;
    int retornofun;
    

    scanf("%d %d", &N, &M);

    int *v1 = malloc(N*sizeof(int));
    int *v2 = malloc(M*sizeof(int));

        while(i < N){ 
            scanf("%d", &numpresente);
            v1[i] = numpresente;
            qtdelem1++;
            i++;
        }

        while(j < M){ 
            scanf("%d", &numencontrar);
            retornofun = busca_binaria(v1, qtdelem1, numencontrar);
            v2[j] = retornofun;
            qtdelem2++;
            j++;
        }

        for(int k = 0; k < qtdelem2; k++){
            printf("%d\n", v2[k]);
        }

    return 0;
}