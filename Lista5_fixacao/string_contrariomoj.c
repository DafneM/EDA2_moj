#include <stdio.h>

void imprime_string(char *s){
	if(*s == '\0') {
		return;
	}
	else{ 
		imprime_string(s+1);
		printf("%c", *s);
	}
}

int main(){
	
	char s[1001];
	
	scanf("%s", s);

	imprime_string(s);
	printf("\n");

	return 0;
}


