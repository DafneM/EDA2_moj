#include <stdio.h>

void recursiva(); 

int main(){
	int qtdlinhas, qtdchar;
	char stringpre_ordem[200], stringem_ordem[200];
	
	scanf("%d", &qtdlinhas);
	for(int i = 0; i<qtdlinhas; i++){
		scanf("%d %s %s", &qtdchar, stringpre_ordem, stringem_ordem);
		recursiva(stringem_ordem, stringpre_ordem);
		printf("\n");
	}
	return 0;
}

void recursiva(char stringem_ordem[], char stringpre_ordem[]){
	int k = 0;
    char raiz;
	if(stringem_ordem[0] == '\0') return;
	else{
		raiz = stringpre_ordem[0];
		while(stringem_ordem[k] != raiz){
			k++;
		}
		stringem_ordem[k] = '\0';
		recursiva(stringem_ordem, stringpre_ordem+1);
		recursiva(stringem_ordem+1+k, stringpre_ordem+1+k);
		printf("%c", raiz);	
	}
}
