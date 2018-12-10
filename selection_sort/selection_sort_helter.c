#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

int main () {
	
	int tam_vetor;
	int i, buffer, j;
	int menor_valor = 0;
	
	
	printf("\nEscolha o tamanho do vetor: ");
	scanf("%d", &tam_vetor);
	
	int vetor[tam_vetor];
	
	printf("\nNosso vetor tem %d espacos.\n\n", tam_vetor);
	
	for (i = 0; i <= (tam_vetor-1); i++){
		printf("Valor da posicao %d: ", i);
		scanf("%d", &vetor[i]); 
	}
	
	for (i = 0; i <= (tam_vetor-1); i++){
		printf("%d - ", vetor[i]); 
	}
	
	//-------------------------------------------------------------
	// SELECTION SORT
	
	for (i = 0; i <= (tam_vetor-1); i++){
		
		 menor_valor = i;
		 j = i+1;
		 
	     while (j < tam_vetor) {
	       
		   if(vetor[j] < vetor[menor_valor]){ 
	         	menor_valor = j;
	     	}
	     	j++;
		}
	     	
	    	if(vetor[i] != vetor[menor_valor]) {
		       buffer = vetor[i];
		       vetor[i] = vetor[menor_valor];
		       vetor[menor_valor] = buffer;
		}
     }
	
	//----------------------------------------------------------------
	
	printf ("\n\nO vetor ordenado fica:\n\n");
	
	for (i = 0; i <= (tam_vetor-1); i++){
		printf("%d - ", vetor[i]); 
	}
	
}
