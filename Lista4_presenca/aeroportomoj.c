
#include <stdio.h>

int main()
{
	int numaero, numvoos;
	int n=1;
	int i;
	int vetor[1000] = {};
	int a;
	//int aux = 1;
	//int k, j, l=0
	int j;
	int x;
	int maior = 0;
	int k;
	
	
	scanf("%d %d", &numaero, &numvoos);
	
	while(numaero != 0 && numvoos != 0){
		
		printf("Teste %d\n", n);

		
		//lendo vetor 
		for(i=0; i<(numvoos*2); i++){
			
				scanf("%d", &a);
				vetor[a-1]++;
			}
		
		
		for(j=0; j<numaero; j++){
			x=vetor[j];
			if(x > maior){	maior=x; }
		}
		
		for(j=1; j<=numaero; j++){
			if(vetor[j-1] == maior){
			printf("%d ", j);
			}
		}
		printf("\n\n");
		
		scanf("%d %d", &numaero, &numvoos);
		
		for(k=0; k<=numaero; k++){ vetor[k-1] = 0; }
		
		maior = 0; 
		x=0;
		n++;
			
	}
	return 0;
}

