#include <stdio.h>
#include <string.h>

int main(){
    int contsim = 0, contnao = 0, conttotal = 0, n = 0;
    char string[4];
    char stringsim[4] = "sim";

    while(scanf(" %s", string) != EOF){
        if(n == 9){
            if(strcmp(string, stringsim) == 0){
             contsim++;
            }
            if(contsim >= 2)
                conttotal++;
            n = 0;
            contsim = 0;
            contnao = 0;
        }
        else{
            if(strcmp(string, stringsim) == 0){
             contsim++;
            }
            else {
            contnao++;
            }
        n++;
        }
    }
    printf("%d\n", conttotal);
    return 0;
}