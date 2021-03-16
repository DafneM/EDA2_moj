#include <stdio.h>
#include <stdlib.h>

typedef int KK;
#define less(A,B) ((A) < (B))
#define lesseq(A,B) ((A) <= (B))
#define exch(A,B) { int tmp; tmp=A;A=B;B=tmp; }
#define cmpexch(A,B) { if (less(B,A)) exch(A,B); }

void insertionSort(KK *v, int l, int r){
    KK aux;

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
}

int partition(KK *v,int l,int r){
    KK aux=v[r];
    int m=l;
    for(int k=l;k<r;k++){
        if(less(v[k],aux)){
        exch(v[k],v[m]);
        m++;
        }
    }
    exch(v[m],v[r]);
    return m;
}

void quickSortMediana3(KK *v,int l, int r){
    if (r-l<=32) {
        return;
    }
    exch(v[(l+r)/2],v[r-1]);
    cmpexch(v[l],v[r-1]);
    cmpexch(v[l],v[r]);
    cmpexch(v[r-1],v[r]);

    //chamando a funcao separa
    int m=partition(v,l+1,r-1);
    //chamada recursiva
    quickSortMediana3(v,l,m-1);
    quickSortMediana3(v,m+1,r);
    }

void quickSortMediana3Insertion(KK *v,int l,int r){
    quickSortMediana3(v,l,r);
    insertionSort(v,l,r);
}

//index é o indice que estamos buscando
int quickselect(KK *v, int l, int r, int index){
    int j = partition(v, l, r);
    //a condicao if garante que todos os elementos que estão a esquerda de j sao menores
    if (j>index)
     return quickselect(v, l, j-1, index);
    else if (j<index)
     return quickselect(v, j+1, r, index);
    return j;
}

int main(){
    int num;
    int iniciop, fimp;
    int total, pagina, qtdprodutospag;

    scanf("%d %d %d", &total, &pagina, &qtdprodutospag) == 1;

    int r = total-1;

    KK *v = malloc(total*sizeof(KK));

    for(int i = 0; i < total; i++){
        scanf("%d", &num);
        v[i] = num;
    }

    iniciop = qtdprodutospag*pagina;
    fimp = iniciop + qtdprodutospag;
    if(fimp > r){
      fimp = r;
    }
    

    quickselect(v, 0, r, iniciop);
    if(fimp == r){
      quickselect(v, 0, r, fimp);
    }
    else{
      quickselect(v, iniciop+1, r, fimp);
    }
    quickSortMediana3Insertion(v, iniciop, fimp);

      int i = iniciop;

      if(fimp == r){
        while(i <= fimp){
            printf("%d\n", v[i]);
            i++;
        }
      }
      else{
        while(i < fimp){
            printf("%d\n", v[i]);
            i++;
        }
      }

    return 0;
}