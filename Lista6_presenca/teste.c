#include <stdio.h>
#include <stdlib.h>

typedef struct no {
int dado;
struct no *esq, *dir;
} no;

no *criar_arvore (int x, no *esq, no *dir) {
  no *raiz = malloc (sizeof (no));
  raiz->dado = x;
  raiz->esq = esq;
  raiz->dir = dir;
  return raiz;
}

no *procurar (no *raiz, int x) {
  if (raiz == NULL || raiz->dado == x) return raiz;
  no *esq = procurar (raiz->esq, x);
  if (esq != NULL) return esq;
  return procurar (raiz->dir, x);
}

no *inserirR(no *raiz, int x) {
  no *procurado = procurar(raiz, x);
  if (raiz == NULL)
      return;
  else if(x < raiz->dado){
        no *novo = inserir(procurado->esq, x);
        procurado->esq = novo;
  }
  else{
    no *novo = inserir(procurado->dir, x);
    procurado->dir = novo;
  }
}

void inserir(no *raiz, int x){
    no *raiz = inserirR(raiz, x);
}

void em_ordem(no *raiz){
    if(raiz == NULL)
        return;
    else
    printf("%d", raiz->dado);
    em_ordem(raiz->esq);
    em_ordem(raiz->dir);
}

int main (){
  int elem, novo;
  char lado;
  // printf ("Digite a raiz: ");
  scanf ("%d", &novo);
  no *raiz = criar_arvore(novo, NULL, NULL);
  while (scanf ("%d", &elem) != EOF) {
   inserir(raiz, elem);
  }

  printf ("Em-ordem: ");
  em_ordem(raiz);

  return 0;
}