#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int qtdelem; int num;
    int qtdocorrenciasmaior = 0, maior = 0;
    int cont = 0;
    int *v = malloc(1001*sizeof(int));

    int *tabelahash = malloc(1001*sizeof(int));
    memset(tabelahash, 0, 1001*sizeof(int));

    while(scanf("%d", &qtdelem) != EOF){
        if(qtdelem == 0)
          break;

      for(int i = 0; i<qtdelem; i++){
        scanf("%d", &num);
        tabelahash[num]++;
        if(tabelahash[num] > qtdocorrenciasmaior){
          qtdocorrenciasmaior = tabelahash[num];
          maior = num;
        }
        else if(tabelahash[num] == qtdocorrenciasmaior){
          if(num > maior)
            maior = num;
          qtdocorrenciasmaior = tabelahash[num];
        }
      }
    }

    printf("%d\n", maior);

    return 0;
}