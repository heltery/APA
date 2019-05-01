/**
 * Dupla: Helter Yordan
 *        Gabriel Alcantara
 */

package TSP_APA;

import static TSP_APA.TSP.*;

public class Busca_local {
    
    public int[] OPT (int[][] matriz_adjacencia, int[] solução_inicial, int custo_inicial) {
        
    //iniciamos com nossa matriz de adjacencias, uma solução inicial que corresponde a solução do vizinho mais proximo e o seu custo 
        
        
        //Iniciando com NULL na melhor solução e zerando o melhor custo
        int[] melhor_solucao = null;
        int melhor_custo = 0;
        //-----------------------------------------------------------
        
        
        for (int i = 1; i < solução_inicial.length - 1; i++) {
            
            for (int j = i + 1; j < solução_inicial.length; j++) {
                
                int[] lista_solucao_aux = solução_inicial;
                int aux = lista_solucao_aux[i];
                lista_solucao_aux[i] = lista_solucao_aux[j];
                lista_solucao_aux[j] = aux;
                melhor_custo = obter_custo(matriz_adjacencia, lista_solucao_aux);

                if (melhor_custo < custo_inicial) {
                    custo_inicial = melhor_custo;
                    melhor_solucao = lista_solucao_aux;
                }
            }
        }

        //retorno da melhor solução encontrada
        return melhor_solucao;
        //-----------------------------------
    }

    public int[] Reinsertion (int[][] matriz_adjacencia, int[] solucao_inicial, int custo_inicial) {
    
    //iniciamos com nossa matriz de adjacencias, uma solução inicial que corresponde a solução do vizinho mais proximo e o seu custo
        
        //Iniciando com NULL na melhor solução e zerando o melhor custo
        int[] melhor_solucao = null;
        int novo_custo = 0;
        //-------------------------------------------------------------

        for (int i = 1; i < solucao_inicial.length; i++) {
            int[] lista_solucao_aux = solucao_inicial;
            for (int j = i; j < solucao_inicial.length - 1; j++) {
                int aux = lista_solucao_aux[i];
                lista_solucao_aux[i] = lista_solucao_aux[i+1];
                lista_solucao_aux[i+1] = aux;
                novo_custo = obter_custo(matriz_adjacencia, lista_solucao_aux);

                if (novo_custo < custo_inicial) {
                    custo_inicial = novo_custo;
                    melhor_solucao = lista_solucao_aux;
                }
            }
        }

        //retorno da melhor solucao encontrada
        return melhor_solucao;
        //-----------------------------------
    }
   
}