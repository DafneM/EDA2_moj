#include <stdio.h>

int main(){
    int qtdnum, num, soma=0;

    scanf("%d", &qtdnum);

    while(qtdnum>0){
        scanf("%d", &num);
        soma += num;
        qtdnum--;
    }

    printf("%d\n", soma);
    return 0;
}