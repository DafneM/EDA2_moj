#include <stdio.h>
#include <string.h>

typedef struct{
    int n;
    char string[21];
} Turma;

Turma aluno[100];

int main(){

    int menor = 11;
    int num, qtdproblemas;
    char string1[21], string2[21];
    int l = 1;

    while(scanf("%d", &num) != EOF){
        for(int i = 0; i < num; i++){
                scanf(" %s %d", aluno[i].string, &aluno[i].n);
               
                  
            if(aluno[i].n < menor){
              menor = aluno[i].n;
              strcpy(string2, aluno[i].string);
            }
            else if((aluno[i].n == menor && strcmp(aluno[i].string, string2) > 0)){
              strcpy(string2, aluno[i].string);
              }
        }
       printf("Instancia %d\n", l);
       l++;
       printf("%s\n", string2);
       printf("\n");
    }

    return 0;

}