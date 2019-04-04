#include <iostream>
#include <list>
#include <queue>

#define INFINITO 10000000

using namespace std;

//IMPRIMIR MEUS DADOS
//------------------------------------------------------
void aluno(){
	cout << "\n\t----------------------------------------------------------";
	cout << "\n\tANALISE DE PROJETO E ALGORITMOS - APA (2018.2)";
	cout << "\n\tALUNO: Helter Yordan";
	cout << "\n\tMATRICULA: 11406573";
	cout << "\n\n\tALGORITMO DIJKSTRA - Problema do caminho minimo\n";
	cout << "\t----------------------------------------------------------\n\n";	
}
//------------------------------------------------------

//ABERTURA E LEITURA DO ARQUIVO
//------------------------------------------------------
int GetV(char * str){

    FILE *f;
    f = fopen(str, "r");
    int aux;
    fscanf(f, "%d", &aux);

    fclose(f);

    return aux;

}
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
//-----------------------------------------------------

class Grafo{
	
	private:
		int V; //NUMERO DE VERTICES DO NOSSO GRAFO
		
		
		//PONTEIRO PARA O ARRAY COM AS LISTAS DE ADJACENCIAS
		//----------------------------------------
		list<pair<int, int> > * adj;
		//----------------------------------------
		
		
	public:
		
		//CONSTRUTOR DO GRAFO
		//---------------------------------------
		Grafo(int V){
			this->V = V;
						
			/*CRIA A LISTA QUE VAI CONTER AS LISTAS DE ADJACENCIAS
			FORMADA PELO VERTICE DE DESTINO E O CUSTO*/
			//------------------------------
			adj = new list<pair<int, int> >[V]; //criando uma lista composta por uma lista para cada vertice que será preenchida com seus vertices adjacentes
			//------------------------------
					
		}
		//---------------------------------------
		
		
		//ADICIONANDO ARESTA AO GRAFO DE v1 A v2
		//---------------------------------------
		void adicionar_aresta(int v1, int v2, int custo){
			adj[v1].push_back(make_pair(v2, custo)); //insira da lista de vertice v1 o vertice v2 com um custo
		}
		//---------------------------------------
		
		
		//ALGORITMO DE DIJKSTRA
		//---------------------------------------
		int dijkstra(int origem, int destino){
			
			//CRIANDO UM VETOR DE DISTANCIAS
			//-------------------------------
			int distancia[V];
			//-------------------------------
			
			//CRIANDO UM VETOR PARA SALVAR OS VERTICES QUE JÁ FORAM VISITADOS
			//-------------------------------
			int visitados[V];
			//-------------------------------
			
			//DECLARANDO A FILA DE PRIORIDADE UTILIZANDO O QUE JÁ ESTA IMPLEMENTADO NA BIBLIOTECA
			//-------------------------------
			priority_queue < pair <int, int>, //PRIMEIRO int -> distancia; SEGUNDO int -> vertice
				vector<pair<int, int> >, greater<pair<int, int> > > pq; //a priority_queue por padrão na sql é uma fila de prioridade maxima, aqui estamos alterando para uma lista minima.
			//-------------------------------
			
			//INICIANDO O VETOR DE DISTANCIA E DE VISITADOS
			//-------------------------------
			for(int i=0; i < V; i++){
				distancia[i] = INFINITO;
				visitados[i] = false;
			}
			
			distancia[origem] = 0; //setando a distancia da origem até ela mesma para 0 pois ela é a raiz, o inicio
			//-------------------------------
			
			//INSERINDO NA FILA
			//-------------------------------
			pq.push(make_pair(distancia[origem], origem)); //inserindo na fila de prioridades - PRIMEIRO elemento é distancia e SEGUNDO é o vertice.
			//-------------------------------
			
			//LOOP - enquanto nossa fila não estiver vazia vamos fazer ...
			//-------------------------------
			while(!pq.empty()){ 
				pair<int, int> p = pq.top(); // pegando o "pair", o par, do top
				int u = p.second; // obtem o vertice do par e salva em 'u'. O vertice é o segundo elemento, o segundo INT.
				pq.pop(); // dando um POP nos removemos da fila o par que foi analisado.
				
				//VERIFICAR SE O VERTICE JÁ FOI VISITADO
				//--------------------------------------
				if(visitados[u] == false){
					
					visitados[u] = true; // caso ele estivesse informando que ainda não tinha sido visitado, apos entrar no IF nos setamos para TRUE para informar que agora ele foi visitado
					
					list<pair<int, int> >::iterator it; // percorrendo a lista dos adjacentes do vertice - busca em largura
					
					
					//PERCORRENDO OS VERTICES 'v' ADJACENTES DE 'u'
					//--------------------------------------------
					for(it = adj[u].begin(); it != adj[u].end(); it++){
						
						int v = it->first; //obtendo o valor do vertice
						int custo_aresta = it->second; //obtendo o valor do custo da aresta
						
						if(distancia[v] > distancia[u] + custo_aresta){ //verificando se a distancia de 'v' até 'u' ainda é maior que a que já temos
							
							distancia[v] = distancia[u] + custo_aresta; // caso a distancia atual seja maior então vamos substituir aqui pela menor
							pq.push(make_pair(distancia[v], v)); // vamos substituir o novo valor encontrado acima na lista de distancias
							
						}
					}
					//--------------------------------------------
					
				}
				//--------------------------------------
				
			}
			//-------------------------------
			
			return distancia[destino];
		}
		//---------------------------------------
		
};


int main(int argc, char *argv[]){
	
	int quant_vertice;
	int vertice_origem;
	int vertice_destino;
	int menor_custo;
	int i, j;
	
	//MEUS DADOS
	//-----------------
	aluno();
	//------------------
	
	
	//ABRINDO E LENDO O ARQUIVO COM A MATRIZ PARA TESTE
	//-----------------
	quant_vertice = GetV("dij10.txt");
    int table[quant_vertice][quant_vertice];
	FillTable("dij10.txt", &table[0][0]);
	//-----------------
	
	
	//IMPRIMINDO NOSSA MATRIZ
    //-----------------------------------------------------------------------------
	for(i = 0; i < quant_vertice; i++){
        printf("\n");
        for(j = 0; j < quant_vertice; j++){
            printf("\t[%d] ", table[i][j]);
        }
    }
    printf("\n\n");
    //----------------------------------------------------------------------------
	
	
	cout << "\tNosso grafo tem [ " << quant_vertice << " ] vertices.\n" << endl;
	Grafo g(quant_vertice); //criando GRAFO - g() = quantidade de vertices
	
	
	//LENDO NOSSA MATRIZ DE ADJACENCIAS E CRIANDO NOSSA LISTA DE ADJACENCIA ADICIONANDO AS ARESTAS CORRESPONDENTES QUE CONSTAM NA MATRIZ E SEUS PESOS
	//--------------------------------------------
	for(i = 0; i < quant_vertice; i++){
        for(j = 0; j < quant_vertice; j++){
            g.adicionar_aresta(i,j,table[i][j]); //FUNÇÃO QUE ESTA EM "GRAFO" QUE CRIA AS ARESTAS, CRIAR AS ARESTAS QUER DIZER ADCIONAR AS LISTAS DE ADJACENCIAS DE CADA VERTICE
        }
    }
    //--------------------------------------------	
		
	cout << "\tQual o vertice de origem: "; // solicitando o vertice de origem
	cin >> vertice_origem;
	cout << "\tQual o vertice de destino: "; // solicitando o vertice de destino
	cin >> vertice_destino;
	
	menor_custo = g.dijkstra(vertice_origem,vertice_destino); // chamando o dijkstra e colocando o resultado do menor custo na variavel 'menor_custo'
	
	
	//IMPRIMINDO O RESULTADO DO CUSTO DE PERCORRER DO VERTICE DE ORIGEM AO DE DESTINO
	//-----------------------------------------------------------------------------------------------------------------------------------
	if (menor_custo == INFINITO){ // se o custo estiver em INFINITO que foi o valor que eu coloquei para todos os custos no inicio então quer dizer que apos percorrer todas as arestas existentes esse caminho não foi verificado, logo ele não existe!
		cout << "\n\t -> O custo minimo para ir de "<< vertice_origem << " ate " << vertice_destino << " = NAO TEM CAMINHO PARA IR DE " << vertice_origem << " PARA " << vertice_destino << endl;
	}
	else{ // o caminho existindo aqui teremos o menor custo para percorre-lo.
		cout << "\n\t -> O custo minimo para ir de "<< vertice_origem << " ate " << vertice_destino << " = " << menor_custo << endl;
	}
	//------------------------------------------------------------------------------------------------------------------------------------
	
	return 0;
}
