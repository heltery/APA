#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

void criar_heap (int *vetor, int i, int final_vetor){
	
	//Declarando as variáveis que seram utilizadas	
	int aux = vetor[i]; 							//pai
	int j = (i*2) + 1; 								//filho 1 - esquerda
	//---------------------------------------------
	
	while (j <= final_vetor){ //verificando se o filho 1 é menor que o final do vetor
		if(j < final_vetor){
			if(vetor[j] < vetor[j+1]){ 				//verificando qual dos dois filhos do pai é o maior ( j ou j+1 ) - filho 2 - direita
				j = j + 1;
			}
		}
		if(aux < vetor[j]){ //verificando se o pai é menor que o filho
			vetor[i] = vetor[j]; //caso filho seja maior que o pai, o filho vira pau
			i = j;
			j = (2*i) + 1;
		}
		else{
			j = final_vetor + 1;
		}
	}
	
	vetor[i] = aux; //pai vira filho se o filho tiver sido maior que pai e tivermos invertido as posições mais acima
	
}

void heapsort (int *vetor, int tam_vetor){
	
	//DECLARANDO AS VARIAVEIS QUE SERAM UTILIZADAS
	int i, aux;
	int meio_vetor = tam_vetor/2;
	//-------------------------------------------
	
	for(i=meio_vetor; i>=0; i--){ //aqui estamos chamando a função HEAP para organizar a arvore
		criar_heap(vetor, i, tam_vetor);
	}
	for(i=tam_vetor; i>=1; i--){ //pegamos sempre o elemento de maior valor e colocamos no final
		aux = vetor[0];
		vetor[0] = vetor[i];
		vetor[i] = aux;
		criar_heap(vetor, 0, i-1); //aqui estamos reestruturando a arvore depois de colocar o valor do topo da arvore, que é o maior elemento no momento, para o final
	}
	
}

int main () {
	
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
	// HEAPSORT
	
	heapsort(vetor, tam_vetor);
	
	//----------------------------------------------------------------
	
	printf ("\n\nO vetor ordenado fica:\n\n");//mostrando o vetor ordenado
	
	for (i = 0; i <= (tam_vetor-1); i++){
		printf("%d - ", vetor[i]); 
	}
	
}
