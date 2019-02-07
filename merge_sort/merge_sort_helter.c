#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

void funcao_merge (int *vetor, int inicio_vetor, int meio_vetor, int fim_vetor){
	
	//Declarando as variáveis que seram utilizadas	
	int *vetor_aux;
	int x1, x2;
	int tam;
	int i,j,k;
	int final1 = 0, final2 = 0;
	//---------------------------------------------
	
	tam = fim_vetor - inicio_vetor + 1; //identificando o tamanho do vetor
	x1 = inicio_vetor; //valor de inicio do vetor
	x2 = meio_vetor + 1; //valor do final do vetor
	
	vetor_aux = (int*) malloc (tam *sizeof(int));
	
	if(vetor_aux != NULL){
		for (i=0; i<tam; i++){ // neste FOR vamos percorrer o vetor auxiliar
			if(!final1 && !final2){
				
				 // vamos comparando e ordenando no nosso vetor auxiliar
				if (vetor[x1] < vetor[x2]){
					vetor_aux[i] = vetor[x1++];
				}
				else{
					vetor_aux[i] = vetor[x2++];
				}
				//-----------------------------------------------------
				
				// verificamos se o vetor que estamos comparando acabou ou não
				if(x1 > meio_vetor){ 
					final1 = 1;
				}
				if(x2 > fim_vetor){
					final2 = 1;
				}
				//-----------------------------------------------------------
			}
			
			else{
				//se o vetor tiver acabado nos copiamos o restante para o vetor auxiliar
				if(!final1){
					vetor_aux[i] = vetor[x1++];
				}
				else{
					vetor_aux[i] = vetor[x2++];
				}
				//---------------------------------------------------------------------
			}
		}
		
		for(j=0, k=inicio_vetor; j<tam; j++, k++){ //neste FOR vamos copiar de volta os valores ordenados para o vetor principal
			vetor[k] = vetor_aux[j];
		}
	}
	
	free(vetor_aux);
	
}

void mergesort (int *vetor, int inicio_vetor, int fim_vetor){
	
	int meio_vetor;
	
	if(inicio_vetor < fim_vetor){
		meio_vetor = floor((inicio_vetor + fim_vetor)/2); //calculando o meio do vetor e arrendondando para baixo
		mergesort (vetor, inicio_vetor, meio_vetor); //chamando a mesma função para esquerda (inicio ao meio)
		mergesort (vetor, (meio_vetor+1), fim_vetor); //chamando a mesma função para direita (meio +1 até o final)
		funcao_merge (vetor, inicio_vetor, meio_vetor, fim_vetor); //chamndo a função_merge que vai fazer  a ordenação
	}
}

int main () {
	
	int inicio_vetor;
	int fim_vetor;
	int tam_vetor;
	int i, buffer, j;
	
	printf("\nEscolha o tamanho do vetor: ");
	scanf("%d", &tam_vetor);
	
	int vetor[tam_vetor];//criando vetor de valor determinado
	
	printf("\nNosso vetor tem %d espacos.\n\n", tam_vetor);
	
	for (i = 0; i <= (tam_vetor-1); i++){ //inserindo valores espaço a espaço
		printf("Valor da posicao %d: ", i);
		scanf("%d", &vetor[i]); 
	}
	
	for (i = 0; i <= (tam_vetor-1); i++){//mostrando valores desordenados
		printf("%d - ", vetor[i]); 
	}
	
	//-------------------------------------------------------------
	// MERGESORT
	
	inicio_vetor = 0; //inicio do vetor é zro (0)
	fim_vetor = tam_vetor - 1; //final do vetor é o valor do seu tamanho menos 1 pois iniciamos da posição zero(0)
	
	mergesort (vetor, inicio_vetor, fim_vetor);
	
	//----------------------------------------------------------------
	
	printf ("\n\nO vetor ordenado fica:\n\n");//mostrando o vetor ordenado
	
	for (i = 0; i <= (tam_vetor-1); i++){
		printf("%d - ", vetor[i]); 
	}
	
}
