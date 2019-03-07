#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

void counting_sort (int *vetor, int n){
	
	//DECLARANDO AS VARIAVEIS
	int i;
	int j;
	int k = 0;
	//----------------------
	
	//VERIFICANDO O MAIOR ELEMENTO DO VETOR
	for(i=0; i<n; i++){
		if(vetor[i] > k){ 
			k = vetor[i];
		}
	}
	printf("\nk = %d\n", k);
	system("pause");
	//------------------------------------
	
	//CRIANDO OS VETORES QUE NOS AUXILIARAM------------------------------------------
	int vetor_B[n];//criando vetor que será preenchido com valores ordenados
	int vetor_aux[k]; //vator de contagem com k elementos
	//--------------------------------------------------------------------------------
	
	//COLOCANDO TODAS AS CASAS DO VETOR AUXILIAR DE CONTAGEM PARA ZERO E PRINTANDO PARA CONFERIR
	for(i=0; i<=k; i++){ //colocando 0 em todas as casas do vetor auxiliar
		vetor_aux[i] = 0;
	}
	
	printf("\nVetor AUX - com zeros\n");
	for (i = 0; i <= k; i++){ // printando vetor auxiliar de contagem com todas as casas com 0
			printf("vetor_aux[%d]- %d\n", i, vetor_aux[i]); 
	}
	//------------------------------------------------------------------------------------------
	
	//PERCORREMOS O VETOR PRINCIPAL E VAMOS INCREMENTANDO 1 EM CASA CASINHA DO VETOR AUXILIAR CORRESPONDENTE AO VALOR DO VETOR PRINCIPAL
	for(i=0; i < n; i++){
		vetor_aux[vetor[i]] += 1;
	}
	printf("\nVetor AUX - depois de contar os elementos\n");
	for (i = 0; i <= k; i++){ // printando vetor auxiliar de contagem
			printf("vetor_aux[%d]- %d\n", i, vetor_aux[i]); 
	}
	//----------------------------------------------------------------------------------------------------------------------------------
	
	//NESTE FOR SOMAMOS O VALOR DO INDICE COM SEU ANTERIOR ATÉ O FINAL DO VETOR AUXILIAR
	for(i=0; i <= k; i++){
		vetor_aux[i] = vetor_aux[i-1] + vetor_aux[i];
	}
	printf("\nVetor AUX - depois de somar com o valor do indice anterior\n");
	for (i=0; i <= k; i++){ 
			printf("vetor_aux[%d]- %d\n", i, vetor_aux[i]); 
	}
	//----------------------------------------------------------------------------------

	//NESTE FOR PEGAMOS O VALOR DO VETOR AUXILIAR ADQUIRIDO E SUBTRAIMOS 1 PARA USAR COMO INDICE DE INSERÇÃO DO VETOR ORGANIZADO
	for(i=0; i < n; i++){
		vetor_B[vetor_aux[vetor[i]] -1] = vetor[i];
		vetor_aux[vetor[i]]--;
	}
	//-------------------------------------------------------------------------------------------------------------------------	
	
	
	//COPIANDO VETOR B PARA O VETOR PRINCIPAL
	for(i=0; i<n; i++){ 
		vetor[i] = vetor_B[i];
	}
	//--------------------------------------
	
	
}

int main () {
	
	int tam_vetor;
	int i, buffer, j;
	
	
	printf("\nEscolha o tamanho do vetor: ");
	scanf("%d", &tam_vetor);
	
	int vetor[tam_vetor];//criando vetor principal
	
	printf("\nNosso vetor tem %d espacos.\n\n", tam_vetor);
	
	for (i = 0; i <= (tam_vetor-1); i++){ //inserindo valores espaço a espaço
		printf("Valor da posicao %d: ", i);
		scanf("%d", &vetor[i]);		 
	}
	
	for (i = 0; i <= (tam_vetor-1); i++){//mostrando valores desordenados
		printf("%d - ", vetor[i]); 
	}
		
	//-------------------------------------------------------------
	// COUNTNIGSORT
	
	// n = tam_vetor
	// k = valor do maior indice que corresponde ao meior vetor do array
	
	counting_sort(vetor, tam_vetor);
	
	//----------------------------------------------------------------
	
	printf ("\n\nO vetor ordenado fica:\n\n");//mostrando o vetor ordenado
	
	for (i = 0; i <= (tam_vetor-1); i++){
		printf("%d - ", vetor[i]); 
	}
	
}
