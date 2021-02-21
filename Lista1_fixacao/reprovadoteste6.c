#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct  desempenho{
    char nome[21];
    int nProblemasResolvidos;
}desempenho;

void insertionSortQtdeProblemas(desempenho *v, int n){
    int i, j;
    desempenho aux;
    for (i=1;i<n;i++){
        aux=v[i];
        for (j = i;(j>0) && (aux.nProblemasResolvidos < v[j-1].nProblemasResolvidos); j--){
            v[j]=v[j-1];
        }
        v[j]=aux;
    }
}

void insertionSortNome(desempenho *v, int n){
    int i, j;
    desempenho aux;
    for (i = 1; i < n; i++){
        aux=v[i];
        for(j = i; j>0 && strcmp(aux.nome, v[j-1].nome) < 0; j--){
            v[j] = v[j-1];
        }
        v[j] = aux;
    }
}
int main(){
    int n, i = 0, pResolvidos, count = 1, q;
    desempenho *p = malloc(sizeof(desempenho));
    char nome[20];
    while (scanf("%d", &n)!=EOF){
        while (i < n){ 
            if(i!=0)
                p = realloc(p, (i+2)*sizeof(desempenho));
            scanf("%s", nome);
            scanf("%d", &pResolvidos);
            strcpy(p[i].nome,nome) ;
            p[i].nProblemasResolvidos = pResolvidos;
            i++;
            
        }
        printf("Instancia %d\n", count);
        count ++; 
        int maior = -1;
        int posicaoMaior;
        for (int j = 0; j < i; j++){
            if(p[j].nProblemasResolvidos > maior){
                maior = p[j].nProblemasResolvidos;
                posicaoMaior = j;
            }
        }
        insertionSortQtdeProblemas(p,n);
        int aux=1;
        for (int j = 1; j < i; j++){
            if(p[j].nProblemasResolvidos == p[0].nProblemasResolvidos)
                aux++;
        }
        insertionSortNome(p,aux);
            printf("%s\n", p[aux-1].nome);
        i = 0;
        
    }

    return 0;
}