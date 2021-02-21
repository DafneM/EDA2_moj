#include <stdio.h>
#include <string.h>

typedef struct Turma{
    int n;
    char string[21];
} Turma;

Turma aluno[100];


void insertionnumero(Turma *v, int l, int r){
    Turma aux;
    int i, j;

    for(i=l+1; i<=r; i++){
        for(j=i; j>l; j--){
              if(v[j-1].n>v[j].n){
                aux = v[j-1];
                v[j-1] = v[j];
                v[j] = aux;
            }
        }
    }
}


void insertionnome(Turma *v, int l, int r){
    Turma aux;
    int j = 0;
    int n = (r-l)+1;
    for (int i = 1; i < n; i++){
        aux=v[i];
        for( j = i; j>0 && strcmp(aux.string, v[j-1].string) < 0; j--){
            v[j] = v[j-1];
        }
        v[j] = aux;
    }
}

int main(){

    int maior = -1;
    int num;
    char string1[21], string2[21];
    int l = 1;
    int cont = 1;
    int i = 0;

    while(scanf("%d", &num) != EOF){
        for(i = 0; i < num; i++){
            scanf(" %s %d", aluno[i].string, &aluno[i].n);
    
            if(aluno[i].n > maior)
               maior = aluno[i].n;
        }

        insertionnumero(aluno, 0, num-1);
        
        for(int k = 1; k < i; k++){
            if(aluno[k].n == aluno[0].n)
                cont++;
        }

        insertionnome(aluno, 0, num-1);

        printf("Instancia %d\n", l);
        l++;
        printf("%s\n", aluno[cont-1].string);
        printf("\n");

        i=0;
    
    }

    return 0;

}