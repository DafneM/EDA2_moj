#include <stdio.h>
#include <stdlib.h>

typedef int Item;

typedef struct no {
    Item dado;
    struct no *esq;
    struct no *dir;
} no;

no *inicializar(){
    return NULL;
}

no *inserir(no *raiz, Item x){
    if(raiz == NULL){
        no *novo = malloc(sizeof(no));
        novo->dado = x;
        novo->esq = NULL;
        novo->dir = NULL;
        return novo;
    }
    else{
        if(x > raiz->dado){
            raiz->dir = inserir(raiz->dir, x);
        }
        else if(x < raiz->dado){
            raiz->esq = inserir(raiz->esq, x);
        }
    }
    return raiz;
}

void pre_ordem(no *raiz){
    if(raiz == NULL)
        return;
    else
    printf("%d ", raiz->dado);
    pre_ordem(raiz->esq);
    pre_ordem(raiz->dir);
}


void em_ordem(no *raiz){
    if(raiz == NULL)
        return;
    else
    em_ordem(raiz->esq);
    printf ("%d ", raiz->dado);
    em_ordem(raiz->dir); 

}

void pos_ordem(no *raiz){
    if(raiz == NULL)
        return;
    else
    pos_ordem(raiz->esq);
    pos_ordem(raiz->dir);
    printf("%d ", raiz->dado);
}

int main(){
    int x;
    no *raiz = inicializar();
    while(scanf("%d", &x) != EOF){
        raiz = inserir(raiz, x);
    }
    pre_ordem(raiz);
    printf(".\n");
    em_ordem(raiz);
    printf(".\n");
    pos_ordem(raiz);
    printf(".\n");
    return 0;
}