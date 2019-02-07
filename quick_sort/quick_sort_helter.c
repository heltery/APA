#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

int funcao_pivo (int *vetor, int inicio_vetor, int fim_vetor){
	
	//Declarando as vari�veis que seram utilizadas	
	int E, D; // E = esquerda , D = direita
	int pivo;
	int aux;
	//---------------------------------------------
	
	E = inicio_vetor; //iniciando da esquerda a verifica��o
	D = fim_vetor; //iniciando da direita a verifica��o
	pivo = vetor[inicio_vetor]; //iniciando o pivo pela esquerda
	
	while(E < D){
		while(vetor[E] <= pivo){ //verificando e avan�ando partindo da esquerda
			E++;
		}
		while(vetor[D] > pivo){ //verificando e avan�ando partindo da direita
			D--;
		}
		if(E < D){ // apartir do momento que se cruzarem esquerda e direta e a esquerda for menor que a direita movemos os valores
			aux = vetor[E];
			vetor[E] = vetor[D];
			vetor[D] = aux;
		}
	}
	
	//depois que verificar e mover toda a sequencia trocamos os valores de inicio e o pivo para assim colocar o pivo no lugar
	vetor[inicio_vetor] = vetor[D];
	vetor[D] = pivo;
	return pivo;
	
}

void quicksort (int *vetor, int inicio_vetor, int fim_vetor){
	
	int pivo; //declarando vari�vel que vai receber o valor do pivo
	
	if(inicio_vetor < fim_vetor){
		pivo = funcao_pivo(vetor, inicio_vetor, fim_vetor); //chama a fun��o que vai calcular o pivo do nosso vetor
		quicksort (vetor, inicio_vetor, (pivo-1)); //chamando a mesma fun��o para esquerda (inicio ao pivo-1)
		quicksort (vetor, (pivo+1), fim_vetor); //chamando a mesma fun��o para direita (pivo+1 at� o final)
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
	
	for (i = 0; i <= (tam_vetor-1); i++){ //inserindo valores espa�o a espa�o
		printf("Valor da posicao %d: ", i);
		scanf("%d", &vetor[i]); 
	}
	
	for (i = 0; i <= (tam_vetor-1); i++){//mostrando valores desordenados
		printf("%d - ", vetor[i]); 
	}
	
	//-------------------------------------------------------------
	// QUICKSORT
	
	inicio_vetor = 0; //inicio do vetor � zro (0)
	fim_vetor = tam_vetor - 1; //final do vetor � o valor do seu tamanho menos 1 pois iniciamos da posi��o zero(0)
	
	quicksort (vetor, inicio_vetor, fim_vetor);
	
	//----------------------------------------------------------------
	
	printf ("\n\nO vetor ordenado fica:\n\n");//mostrando o vetor ordenado
	
	for (i = 0; i <= (tam_vetor-1); i++){
		printf("%d - ", vetor[i]); 
	}
	
}
