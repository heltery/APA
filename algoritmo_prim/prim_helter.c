#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//FUNÇÃO FEITA PRA IMPRIMIR NOSSA MST
//-------------------------------------------------------
void imprimir_mst(int *pai, int *key, int tam){
    	int soma = 0;
    	int i;

	    printf("Aresta          Custo\n\n");
	
	    for(i = 1; i<tam; i++){
	        printf("%d ---- %d      %d\n", pai[i], i, key[i]);
	        soma = soma + key[i];
	    }
	    
	    printf("\nCusto Total: %d\n\n", soma);
}
//------------------------------------------------------

//VERIFICANDO E MOVENDO OS MENORES VALORES DOS FILHOS E RAIZ DA BUS-ARVORE
//------------------------------------------------------
void heapify(int * arr, int n, int i, int * key){

    int menor = i;  	// Toma o primeiro elemento como sendo o menor
    int e = 2*i + 1;  	// esquerda = 2*i + 1
    int d = 2*i + 2;  	// direita = 2*i + 2



    // SE O FILHO DA ESQUERDA POR MENOR QUE O ATUAL ELE FAZ A TROCA
	//-----------------------------------------------------------------
    if (e < n && key[arr[e]] < key[arr[menor]]){
        menor = e;
	}
	//-----------------------------------------------------------------



    // SE O FILHO DA DIREITA POR MENOR QUE O ATUAL ELE FAZ A TROCA
	//-----------------------------------------------------------------
    if (d < n && key[arr[d]] < key[arr[menor]]){
        menor = d;
    }
    //-----------------------------------------------------------------



    // VERIFICANDO SE O MENOR É A RAIZ DA SUB-ARVORE, SE NÃO FOR FAZ A TROCA
    //------------------------------------------------------------------
    if (menor != i){

        int aux = arr[menor];
        arr[menor] = arr[i];
        arr[i] = aux;

        // Continua Consertando o heap
		//----------------------------------
        heapify(arr, n, menor, key);
		//---------------------------------
		
    }

}
//------------------------------------------------------

//CONSTRUINDO NOSSA ARVORE
//------------------------------------------------------
void arvore_min(int * heap, int tam, int * key){

    int i;

    for (i = tam / 2 - 1; i >= 0; i--){
        heapify(heap, tam, i, key);
	}

}
//------------------------------------------------------


int HeapExtMin(int * heap, int * tam, int * key){

    int min = heap[0];

    heap[0] = heap[*(tam) -1];
    *tam = *tam-1;
    heapify(heap, *tam, 0, key);

    return min;

}



void HeapDecrease(int * heap, int a, int dec, int tam, int * key){

    int i;

    for(i = 0; i < tam; i++){
        if(heap[i]==a){
			break;
		}
    }
    
    if(key[a] < dec){
	;
    }
    
	else{
        key[a] = dec;
        int parent = (i-1)/2;

        while(i > 0 && (key[heap[parent]] > key[heap[i]])){

            int aux = heap[i];
            heap[i] = heap[parent];
            heap[parent] = aux;
            i = parent;
            parent = (i-1)/2;

        }
    }
}


//ALGORITMO PARA TRABALHO COM ARQUIVO
//------------------------------------------------------
int GetV(char * str){

    int aux;
    
	FILE *f;
    f = fopen(str, "r");
   
    fscanf(f, "%d", &aux);
    fclose(f);

    return aux;
}
//------------------------------------------------------

//ALGORITMO PARA PREENCHER NOSSA TABELA
//------------------------------------------------------
void FillTable(char * str, int * table){

    //ABRINDO O ARQUIVO
	//----------------------------------------
	FILE *f;
	f = fopen(str, "r");
	//-----------------------------------------

    int aux;
    int v;
    int i;
    
    fscanf(f, "%d", &v);
    
    for(i = 0; i < v; i++){

        int j;

        for(j = i; j < v; j++){
            if(j == i){
                *((table+j*v)+i) = 0;
            }
			else{
                fscanf(f,"%d", &aux);
                *((table+j*v)+i) = aux;
                *((table+i*v)+j) = aux;
            }
        }

    }

fclose(f);

}
//------------------------------------------------------

//ALGORITMO DO PRIM
//-------------------------------------------------------
void algoritmo_prim(int * w, int tam, int d){

    int i;
    int key[tam];
    int pai[tam];
    int entrada[tam];
    
    for(i = 0; i < tam; i++){

        key[i] = INT_MAX;
		pai[i] = -1;
        entrada[i] = 0;

    }

    key[d] = 0;
    entrada[d] = 1;

    int q_tam = tam;
    int q[tam];

    //PREENCHENDO A FILA
    //----------------------------------------------------------

    for(i = 0; i<tam; i++){
		q[i] = i;
	}
	//----------------------------------------------------------

    //CHAMANDO A FUNÇÃO QUE VAI CONSTRUIR NOSSA ARVORE MINIMA
    //----------------------------------------------------------
	arvore_min(&q[0], tam, &key[0]);
	//----------------------------------------------------------

    //ENQUANTO A FILA NÃO ESTIVE VAZIA
    //---------------------------------------------------------

    while(q_tam > 0){

        int u = HeapExtMin(&q[0], &q_tam, &key[0]);
        printf("\n Fila: {");
        for(i = 0; i < q_tam; i++){
            printf(" (%d,%d)", q[i], key[q[i]]);
    	}
        printf("}\n\n");

        entrada[u] = 1;

        //PARA CADA VIZINHO DE 'U' VAMOS FAZER
        //------------------------------------------------

        int v;
        for(v = 0; v < tam; v++){
            if(u == v){
			;}
			else{                          //w[u][v]
                if((entrada[v]==0) && (  (*((w+u*tam)+v))  < (key[v]))){
                    pai[v] = u;
                    HeapDecrease(&q[0], v, (*((w+u*tam)+v)), tam, &key[0]);
                }
            }
        }

    }
    //----------------------------------------------------------------------------



    //IMPRIMINDO A MST
    //---------------------------------------------------------------------------
	imprimir_mst(pai, key, tam);
	//--------------------------------------------------------------------------
}
//-------------------------------------------------------

int main(){

	//ABRINDO ARQUIVO DE TESTE E GERANDO NOSSA MATRIZ COM OS PESOS DAS ARESTAS
	//------------------------------------------------------------------------------
    int tam = GetV("dij10.txt");
    int table[tam][tam];
    int i,j;

    FillTable("dij10.txt", &table[0][0]);
    
    //-----------------------------------------------------------------------------

    //PRINTANDO NOSSA MATRIZ
    //-----------------------------------------------------------------------------
	for(i = 0; i < tam; i++){
        printf("\n");
        for(j = 0; j < tam; j++){
            printf("\t[%d] ", table[i][j]);
        }
    }
    printf("\n\n");
    
    //----------------------------------------------------------------------------

	//CHAMANDO O ALGORITMO PRIM
	//---------------------------------------------------------------------------
    algoritmo_prim(&table[0][0], tam, 0);
    //--------------------------------------------------------------------------

    return 0;

}
