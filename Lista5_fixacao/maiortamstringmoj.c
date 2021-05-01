#include <stdio.h>

int tamstring(char *string, int tam){
    int i = 0;
    while(string[i] != '\0'){
        tam++;
        i++;
    }
    return tam;
}

int main(){
    char string[1001];
    int maiortam = 0, tam = 0, qtdstrings, tamres;

    scanf("%d", &qtdstrings);

    for(int i = 0; i<qtdstrings; i++){
      scanf(" %s", string);
      tamres = tamstring(string, tam);
      if(tamres > maiortam)
        maiortam = tamres;
    }
    printf("%d\n", maiortam);
    return 0;
}