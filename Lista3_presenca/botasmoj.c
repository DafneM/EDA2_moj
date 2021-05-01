#include <stdio.h>
#include <stdlib.h>

//struct pilha
typedef struct celula {
char dado;
struct celula *prox;
} celula;

//criar pilha
celula *cria_pilha(){
    celula *p = malloc(sizeof(celula));
    if(p == NULL){exit(1);}
    p -> prox = NULL;
    return p;
}

//empilhar
void empilha(celula *p, char x){
	celula *novo = malloc(sizeof(celula));
	novo -> dado = x;
	novo -> prox = p -> prox;
	p->prox = novo;
}

//desempilhar
int desempilha(celula *p, char *y){

	celula *lixo = p -> prox;
	if(lixo == NULL){
		return 0; }
	*y = lixo -> dado;
	p -> prox = lixo -> prox;
	//apagando a celula lixo
	free(lixo);
	return 1;
}

int main(){
    int num;
    char letra;
    int i, qtdpares=0;
    celula *p[31]; 
    char *y = malloc(sizeof(int));

    for(i=0; i<31; i++){
        p[i] = cria_pilha();
    }

    while( scanf("%d %c", &num, &letra)!=EOF){
        //se a pilha estiver vazia
            if(p[num-30] -> prox == NULL){
              empilha(p[num-30], letra);
            }
            else{
                //se nao formar par
                if(p[num-30]->prox->dado == 'D' && letra == 'D' ||
                   p[num-30]->prox->dado == 'E' && letra == 'E'){
                  empilha(p[num-30], letra);
                }
                //se formar par
                else if(p[num-30]->prox->dado == 'D' && letra == 'E' ||
                        p[num-30]->prox->dado == 'E' && letra == 'D'){
                  desempilha(p[num-30], y);
                  qtdpares++;
                }
        }
    }
    printf("%d\n", qtdpares);

    return 0;
}