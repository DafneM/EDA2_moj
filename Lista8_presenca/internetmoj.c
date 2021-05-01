#include <stdio.h>
#include <stdlib.h>

struct velocidade{
    int veldown;
    int velup;
};

typedef struct velocidade item;
#define Key(A) (A.veldown)
#define exch(a, b) {item t; t=a;a=b;b=t;}
#define less(a, b) (a.veldown < b.veldown)
#define cmpexch(a,b) {if(min(b,a)) exch(a,b);}

int lesseq(item A, item B){
  if(A.veldown == B.veldown)
    return A.velup < B.velup;
  else
    return A.veldown < B.veldown;
}

void merge(item *v1, int left, int middle, int right){

    item *v2 = malloc((right-left+1)*sizeof(item));
    int i = left;
    int j = middle + 1;
    int k = 0;

    while(i<=middle && j<=right){

      if(lesseq(v1[i],v1[j])){
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

void mergesort(item *v, int left, int right){

    if(left>=right)
      return;

    int middle = (left+right)/2;

    mergesort(v, left, middle);
    mergesort(v, middle+1, right);
    merge(v, left, middle, right);
}


int main(){
    struct velocidade velocidade[100005];
    int D, U, T;
    double L;
    int velocidadedown, velocidadeup;
    int cont = 0;
    scanf("%d %d %lf %d", &D, &U, &L, &T);
    double porcentagem = (L/100);
    double Dporcentagem = D*porcentagem;
    double Uporcentagem = U*porcentagem;
    int finalD = (D-Dporcentagem);
    int finalU = (U-Uporcentagem);
    for(int i = 0; i<T; i++){
        scanf("%d/%d", &velocidadedown, &velocidadeup);
        if((velocidadedown < finalD) || (velocidadeup < finalU)){
            velocidade[cont].veldown = velocidadedown;
            velocidade[cont].velup = velocidadeup; 
            cont++;
        }
    }
    mergesort(velocidade, 0, cont-1);
    for(int i = 0; i<cont; i++){
        printf("%d/%d\n", velocidade[i].veldown, velocidade[i].velup);
    }
    return 0;
}