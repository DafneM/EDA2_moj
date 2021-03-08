#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int qtdpatos, codcor;
    int qtdocorrenciasmaior = 0, maiorcor = 0;
    int *v = malloc(1000001*sizeof(int));
    int cont = 0;

    int *tabelahash = malloc(1000001*sizeof(int));

    memset(tabelahash, 0, 1000001*sizeof(int));

    while(scanf("%d", &qtdpatos)){
      if(qtdpatos == 0)
        break;

      for(int i = 0; i < qtdpatos; i++){
          scanf("%d", &codcor);
          tabelahash[codcor]++;
          if(tabelahash[codcor] > qtdocorrenciasmaior){
            qtdocorrenciasmaior = tabelahash[codcor];
            maiorcor = codcor;
          }
      }
      v[cont] = maiorcor;
      //printf("%d\n", maiorcor);
      cont++;
      qtdocorrenciasmaior = 0;
      maiorcor = 0;
      memset(tabelahash, 0, 1000001*sizeof(int));
    }

    for(int i = 0; i<cont; i++){
        printf("%d\n", v[i]);
    }

    return 0;
}