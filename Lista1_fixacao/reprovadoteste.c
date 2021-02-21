#include <stdio.h>
#include <string.h>

int main(){

    int menor = 11;
    int num, qtdproblemas;
    char string1[21], string2[21];
    int n = 1;

    while(scanf("%d", &num) != EOF){
        for(int i = 0; i < num; i++){
                scanf(" %s %d", string1, &qtdproblemas);
                  
            if(qtdproblemas < menor){
              menor = qtdproblemas;
              strcpy(string2, string1);
            }
            else{
              if(qtdproblemas == menor && strcmp(string1, string2) > 0){
              strcpy(string2, string1);
              }
            }
        }
       printf("Instância %d\n%s\n\n", n, string2);
       n++;
    }


    return 0;
}