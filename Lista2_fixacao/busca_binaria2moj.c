#include <stdio.h>
#include <stdlib.h>

int busca_binaria(int v2[], int v[], int qtdelem1, int valor)
{

    int esq = -1;
    int dir = qtdelem1;

    while (esq < dir - 1)
    {
        int meio = (dir + esq) / 2;
        if(v[meio] < valor)
            esq = meio;
        else
            dir = meio;
    }
    if (valor == v[dir])
    {
        return v2[dir];
    }
    else if(valor != v[dir]){
        return -1;
    }
}

void quicksort(int v2[], int v[], int esq, int dir)
{
    int i = esq;
    int j = dir;
    int elem = v[(esq + dir) / 2];
    int aux, aux1;

    while (i <= j)
    {
        while (v[i] < elem && i < dir)
        {
            i++;
        }
        while (v[j] > elem && j > esq)
        {
            j--;
        }
        if (i <= j)
        {
            aux = v[i];
            aux1 = v2[i];
            v[i] = v[j];
            v2[i] = v2[j];
            v[j] = aux;
            v2[j] = aux1;
            i++;
            j--;
        }
    }

    if (j > esq)
        quicksort(v2, v, esq, j);
    if (i < dir)
        quicksort(v2, v, i, dir);
}

int main()
{
    int N, M;
    int i = 0, j = 0;
    int numvetor, numencontrar;
    int retornofun;
    int qtdelem1 = 0;
    int posicao;

    scanf("%d %d", &N, &M);

    int *v2 = malloc(N * sizeof(int));
    int *v1 = malloc(N * sizeof(int));
    int *guarda = malloc(M * sizeof(int));
    while (i < N)
    {
        scanf("%d", &numvetor);
        v1[i] = numvetor;
        v2[i] = i;
        i++;
    }
    quicksort(v2, v1, 0, N - 1);
    while (j < M)
    {
        scanf("%d", &numencontrar);
        guarda[j] = numencontrar;
        j++;
    }
         
    for(i=0; i<M; i++){
        printf("%d\n", busca_binaria(v2, v1, N, guarda[i]));
    }

    return 0;
}