
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int controle_VND = 0;

struct matriz {
	int dimensao;
	int** elementos;
};


// IMPRIMIR MEUS DADOS
//------------------------------------------------------
void aluno(){
	printf("\n\t----------------------------------------------------------");
	printf("\n\tANALISE DE PROJETO E ALGORITMOS - APA (2018.2)");
	printf("\n\tDUPLA: Helter Yordan");
	printf("\n\t       Gabriel Alcantara");
	printf("\n\n\t\t>>>> Projeto Final <<<<\n");
	printf("\n\n\t    Resolver o problema do caixeiro viajante\n");
	printf("\t----------------------------------------------------------\n\n");	
}
//------------------------------------------------------

// LENDO A DIMENSAO DO ARQUIVO
//------------------------------------------------------
void LerArquivo(struct matriz* m, char nome_arq[]){
	
	int i, j;
	char *vetor_aux[50];
	
	FILE *arq = fopen(nome_arq, "r");
	
	if(arq == NULL){
   		printf("ERRO!!! - Nao foi possivel abrir o arquivo!\n");
   	}
   	
	else{
		
		//COLETANDO O VALOR DA DIMENSAO DA MATRIZ
		//---------------------------------------
  		while (fscanf(arq, "%s", &vetor_aux[i])){
        	if (!strcmp(&vetor_aux[i], "DIMENSION:")){
            	fscanf(arq, "%d\nEDGE_WEIGHT_SECTION\n", &m->dimensao);
            	break;
        	}
		}
		
		printf("\nDIMENSAO = %d\n", m->dimensao);
		
		m->elementos = malloc(m->dimensao*sizeof(int*));
		
		for(i = 0; i < m->dimensao; i++){
			m->elementos[i] = malloc(m->dimensao*sizeof(int));
			for(j = 0; j < m->dimensao; j++){
				fscanf(arq, "%d  ", &m->elementos[i][j]);
			}
		}
		
		fclose(arq);
	}
	
}
//------------------------------------------------------

// IMPRIMIR MATRIZ
//------------------------------------------------------
void ImprimirMatriz(struct matriz m){
	
	int i, j;
	
	for(i = 0; i < m.dimensao; i++){
        printf("\n");
        for(j = 0; j < m.dimensao; j++){
            printf("\t[%d] ", m.elementos[i][j]);
        }
    }
    printf("\n\n");
	
}
//------------------------------------------------------

// CONSTRUÇAO DO CAMINHO INICIAL - BUSCA LOCAL (VISINHO MAIS PROXIMO)
//------------------------------------------------------
void caminho(struct matriz m, int* percurso){
	
/* 		A construção do meu caminho inicial se deu da seguinte forma:
	
			temos um duplo FOR onde estando no NÓ "i" vamos comparar todos os demais nos "j" e vemos dois pontos:
				1- se ele já foi inserido na solução, comparando com o vetor de visitados;
				2- se o custo dele pra o NÓ "i" é menor que o valor que adotamos como referencia; (adotei um valor de referencia bem alto pra sempre dar certo)
			dai vamos montando nosso caminho inicial e marcando como visitado no vetor de visitados. Quando o vetor de visitados
			estiver completo com TRUE quer dizer que visitamos todos os NÓS, logo o caminho inicial esta completo.
			
			Lembrando que a soluçao inicial não precisa ter o melhor desempenho, é apenas o ponta pé inicial!
*/
	
	
	int i, j;
	
	int *visitados = malloc(m.dimensao * sizeof(int)); //alocando vetor para guardar elementos já visitados
	
	for (i = 0; i < m.dimensao; i++){				   //iniciando com FALSE todas as casas desse vetor
		visitados[i] = FALSE;
	}
	
	percurso[0] = 0; //dando um valor para inicio
	visitados[0] = TRUE; //colocando como TRUE (visitado) o nó 0 que é o que estamos iniciando por ele
	
	for (i = 0; i < m.dimensao; i++){
		
		int comparador = 1000000000; //comparador é o valor que vamos ter para comparar com o custo do deslocamento de "i" para "j" vamos colocar um valor bem alto pra iniciar pois vamos compara-lo com o custo da aresta e ele nunca pode ser menor
		int vizinho_escolhido = 0; //numero do visinho que foi escolhido como com menor custo para podermos dar baixa no vetor de visitados
		
		for(j = 0; j < m.dimensao; j++){
			
			if(!visitados[j] && comparador > m.elementos[i][j]){ //se o nó de valor "j" não tiver sido visita E seu custo de deslocamento de "i" para "j" for menor que o valor do comparador
				vizinho_escolhido = j;
				comparador = m.elementos[i][j];
			}
			
		}
		
		percurso[i+1] = vizinho_escolhido; //cadastramos o vizinho que vimos que era a melhor opção no vetor do percurso
		visitados[vizinho_escolhido] = TRUE; //cadastramos como TRUE (visitado) o visinho que identificamos acima
		
		
	}
	
	percurso[m.dimensao] = 0;
	
	free(visitados); //desalocando a memoria que tinhamos destinado ao vetor de nos visitados
	
}
//------------------------------------------------------

// IMPRIMIR O CAMINHO
//------------------------------------------------------
void imprimir_caminho(int x, int* percurso){
	int i;
	
	for(i = 0; i < x; i++){
		printf("- %d - ", percurso[i]);
	}
	printf("\n\n");
}
//------------------------------------------------------

// CALCULAR O CUSTO DO PERCURSO
//------------------------------------------------------
int custo_caminho(struct matriz m, int* percurso){
	
	int custo = 0;
	int i;
	
	for(i = 0; i < m.dimensao; i++){
		custo = custo + m.elementos[percurso[i]][percurso[i+1]];
	}
	
	return custo;	
}
//------------------------------------------------------

// RE-INSERTION
//------------------------------------------------------
int reinsertion(struct matriz m, int* solucao, int* solucao_inicial, int* custo){
	
	int i, c, j, aux, novo_custo;
	int *aux_solucao = malloc((m.dimensao + 1)*sizeof(int));
	
	
	for (i = 1; i < m.dimensao; i++){
		
		//---------------------------------- copiando o vetor da solução inicial para inicialziar o vetor da solução final onde vamos formatalo agora
		for (c = 0; c < m.dimensao; c++){
			aux_solucao[c] = solucao_inicial[c];
		}
		//----------------------------------
		
		for (j = i; j < (m.dimensao-1); j++){
			
			aux = aux_solucao[j];
			aux_solucao[j] = aux_solucao[j+1];
			aux_solucao[j+1] = aux;
			
			novo_custo = custo_caminho(m, aux_solucao);
			
			if(novo_custo < *custo){
				*custo = novo_custo;
				
				//-------------------------------------- copiando o novo vetor de solução encontrado que esta com "aux_solucao" para o vetor da nova solução.
				for (c = 0; c < m.dimensao; c++){
					solucao[c] = aux_solucao[c];
				}
				//--------------------------------------
				
			}
		}
		 
		 
	}
	
	free(aux_solucao);	
}
//------------------------------------------------------

// 2-OPT
//------------------------------------------------------
int two_opt(struct matriz m, int* solucao, int* solucao_inicial, int* custo){
	
	int i, c, j, aux, novo_custo;
	int *aux_solucao = malloc((m.dimensao + 1)*sizeof(int));
	
	
	for (i = 1; i < m.dimensao; i++){
		
		//---------------------------------- copiando o vetor da solução inicial para inicialziar o vetor da solução final onde vamos formatalo agora
		for (c = 0; c < m.dimensao; c++){
			aux_solucao[c] = solucao_inicial[c];
		}
		//----------------------------------
		
		for (j = i; j < (m.dimensao-1); j++){
			
			aux = aux_solucao[i];
			aux_solucao[i] = aux_solucao[j];
			aux_solucao[j] = aux;
			
			novo_custo = custo_caminho(m, aux_solucao);
			
			if(novo_custo < *custo){
				*custo = novo_custo;
				
				//-------------------------------------- copiando o novo vetor de solução encontrado que esta com "aux_solucao" para o vetor da nova solução.
				for (c = 0; c < m.dimensao; c++){
					solucao[c] = aux_solucao[c];
				}
				//--------------------------------------
				
			}
		}
		 
		 
	}
	
	free(aux_solucao);	
}
//------------------------------------------------------

// VND
//------------------------------------------------------
int vnd(int* custo, struct matriz m, int* solucao, int* solucao_inicial, int controle_VND){
	
	int i, j, c;
	int interacao = 0;
	int *aux_solucao = malloc((m.dimensao + 1)*sizeof(int));
	
	
	for (c = 0; c < m.dimensao; c++){ //copiando o vetor da solução inicial para o vetor aux criado
		aux_solucao[c] = solucao_inicial[c];
	}
	
	int aux_custo = *custo;
	
	while (interacao < 100){
		
		
		if(controle_VND == 0){
			
			reinsertion (m, solucao, solucao_inicial, &aux_custo);
			
			if(*custo < aux_custo){
				controle_VND = 0;
				interacao++;
			}

			else{
				
				controle_VND = 1;
				interacao++;
			}
			
		}
		
		if(controle_VND == 1){
			
			two_opt (m, solucao, aux_solucao, &aux_custo);
			
			if(*custo < aux_custo){
				controle_VND = 0;
				interacao++;
			}
			
			else{
				controle_VND = 0;
				interacao++;
			}	
		
		}
		*custo = aux_custo;
	}
	
	free(aux_solucao);
}
//------------------------------------------------------




int main(int argc, char *argv[]){
	
	struct matriz m;
	int i, j;
	int custo;
	char nome_arq[15]; //string para armazenar o nome do arquivoq ue vamos abrir
	
	//MEUS DADOS
	//-------------------
	aluno();
	//-------------------
	
	//INFORMAR O NOME DO ARQUIVO
	//-------------------
	printf("\n\n\t1) Informe o nome do arquivo: ");
	scanf("%s", &nome_arq);
	//-------------------
	
	//LER ARQUIVO
	//-------------------
	LerArquivo(&m, nome_arq);
	ImprimirMatriz(m);
	//-------------------
	
	//APARTIR DE UMA SOLUCAO INICIAL CALCULAR NOSSA SOLUCAO INICIAL - BUSCA LOCAL (VISINHO MAIS PROXIMO)
	//------------------
	int *solucao_inicial = malloc((m.dimensao + 1)*sizeof(int)); //alocando espaço pro vetor que vai armazenar a solução inicial
	caminho(m, solucao_inicial);
	printf("\nSolucao Inicial: ");
	imprimir_caminho(m.dimensao+1, solucao_inicial);
	//------------------
	
	//OBTENDO O CUSTO DA NOSSA SOLUÇÃO INICIAL
	//------------------
	custo = custo_caminho(m, solucao_inicial);
	printf("\nCusto da solucao inicial: %d\n", custo);
	//------------------
	
	
	
	// CHAMANDO VND
	//------------------
	int *solucao = malloc((m.dimensao + 1)*sizeof(int)); //alocando espaço pro vetor que vai armazenar a solução inicial
	vnd(&custo, m, solucao, solucao_inicial, controle_VND);
	printf("\nSolucao depois de executar o VND: ");
	imprimir_caminho(m.dimensao+1, solucao);
	printf("\n\nCusto depois de executar o VND: %d\n", custo);
	
	//------------------*/
	
	
	
	
	
	/*reinsertion testes
	//------------------
	int *solucao = malloc((m.dimensao + 1)*sizeof(int)); //alocando espaço pro vetor que vai armazenar a solução inicial
	reinsertion(m, solucao, solucao_inicial, &custo);
	printf("\nSolucao com reinsertion: ");
	imprimir_caminho(m.dimensao+1, solucao);
	
	printf("\n\nCusto da solucao com reinsertion: %d\n", custo);
	//------------------*/
	
	/*2-opt testes
	//------------------
	int *solucao = malloc((m.dimensao + 1)*sizeof(int)); //alocando espaço pro vetor que vai armazenar a solução inicial
	two_opt(m, solucao, solucao_inicial, &custo);
	printf("\nSolucao com 2-OPT: ");
	imprimir_caminho(m.dimensao+1, solucao);
	
	printf("\n\nCusto da solucao com 2-OPT: %d\n", custo);
	//------------------*/
	
	
	
	
	
	
return 0;
}
