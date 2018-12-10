#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

int main () {
	
	int tam_vetor;
	int i, buffer, j;
	
	printf("\nEscolha o tamanho do vetor: ");
	scanf("%d", &tam_vetor);
	
	int vetor[tam_vetor];
	
	printf("\nNosso vetor tem %d espacos.\n\n", tam_vetor);
	
	for (i = 0; i <= (tam_vetor-1); i++){
		printf("Valor da posicao %d: ", i);
		scanf("%d", &vetor[i]); 
	}
	
	//("inserir valor na posição 5 de um vetor de 4 posicoes: ");
	//scanf("%d", &vetor[5]);
	
	for (i = 0; i <= (tam_vetor-1); i++){
		printf("%d - ", vetor[i]); 
	}
	
	//-------------------------------------------------------------
	// INSERTION SORT
	
	for (i = 1; i <= (tam_vetor-1); i++){
		
		buffer = vetor[i];
		j = i -1;
		
		while( (j>=0) && (vetor[j] > buffer) ){
			vetor[j+1] = vetor[j];
			j--;
		}
		
		vetor[j+1] = buffer;
	}
	
	//----------------------------------------------------------------
	
	printf ("\n\nO vetor ordenado fica:\n\n");
	
	for (i = 0; i <= (tam_vetor-1); i++){
		printf("%d - ", vetor[i]); 
	}
	
}
