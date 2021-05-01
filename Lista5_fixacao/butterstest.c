#include <stdio.h>
#include <stdlib.h>

int testerand(int Mi, int Mf, int num){
    int i = Mi, j = 1, retorno;
    while(Mi < Mf){
      for (j = 1; j < 1000; j++){
        rand_r(&i);
      }
      if (rand_r(&i) % 256 == num)
        retorno = i;
        i++;
    }
    return retorno;
}

int main(){
    int Mi, Mf, num, retorno;
    scanf("%d %d", &Mi, &Mf);
    if(Mi == Mf){
        printf("%d", Mf);
    }
    else{
        while(scanf("%d", &num) != EOF){
        retorno = testerand(Mi, Mf, num);
        }
        printf("%d", retorno);
    }
}