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
    int tam = 0, resultado;

    scanf(" %s", string);
    resultado = tamstring(string, tam);
    printf("%d\n", resultado);
    return 0;
}