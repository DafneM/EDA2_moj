#include <stdio.h>
#include <stdlib.h>

int main(){
    int v[1001];
    int qtdelem, num;
    scanf("%d", &qtdelem);
    for(int i = 0; i<qtdelem; i++){
        scanf("%d", &num);
        if(num % 2 == 0){
            printf("Jedi\n");
        }
        else{
            printf("Sith\n");
        }
    }
    return 0;
}