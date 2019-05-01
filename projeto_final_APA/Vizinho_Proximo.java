/**
 * Dupla: Helter Yordan
 *        Gabriel Alcantara
 */
package TSP_APA;

import static java.lang.System.in;
import java.util.ArrayList;
import javax.swing.JOptionPane;

public class Vizinho_Proximo {

    String solucao_array = "";
    
    //criação das cariaveis para melhor solucao e melhor caminho
    public static int[] melhor_solucao;
    public static int melhor_caminho = 0;
    //---------------------------------------------------------

    
    //funcao para encontrar a menor distancia onde dentro dela vamos chamar a funcao para comparar as cidades vizinahs e os custos de deslocamento
    public static int[] Menor_distancia(int[][] matriz_adjacencia, int origem) {

        melhor_solucao = new int[matriz_adjacencia[0].length];

        //preenchendo os dados do melhor caminho
        for (int i = 0; i < melhor_solucao.length; i++) {
            melhor_solucao[i] = Integer.MAX_VALUE;
        }
        //---------------------------------------

        melhor_solucao[0] = origem;
        
        // vamos usar x para guardar a cidade atual
        int x = origem;
        //-----------------------------------------

        int i = 1;
        int count = 0;
        
        //verificar até o termino do numero de cidades
        while (i < melhor_solucao.length) {
            // encontro a próxima cidade
            int proxima = Menor_custo(matriz_adjacencia[x]);
            // se a cidade for diferente de - 1 (significa que a mesma não foi visitada)
            if (proxima != -1) {
                // adiciono a cidade ao melhor_caminho
                melhor_solucao[i] = proxima;
                // atualizo a cidade atual e o contador
                x = proxima;

                i++;
                count++;
            }

        }
        //----------------------------------------------
        
               return melhor_solucao;
    }
    //---------------------------------------------------------------------------------------------
    
    
    
    //veificar os custos das cidades vizinhas para obter o menor custo para se deslocar de uma cidade para outra
    public static int Menor_custo(int[] row) {
        //encontro o menor custo
        //na linha passada por parametro (int[] row)
        int cidade_prox = -1;
        int i = 0;
        int minimo = Integer.MAX_VALUE;

        
        //verifica o custo da cidade e compara com o minimo
        while (i < row.length) {
            if (!Verif_cidade(melhor_solucao, i) && row[i] < minimo) {
                minimo = row[i];
                cidade_prox = i;
            }
            i++;
        }
        //-----------------------------------------------------

        if (i == melhor_solucao.length) {
            melhor_caminho = melhor_caminho + minimo;
        }
        
        return cidade_prox;
    }
    //---------------------------------------------------------------------------------------------------
    
    

    //afim de verificar se a cidade esta na melhor rota que temos
    public static boolean Verif_cidade(int[] aolucao, int cidade) {
        for (int i = 0; i < aolucao.length; i++) {
            if (aolucao[i] == cidade) {
                return true;
            }
        }
        return false;
    }
    //------------------------------------------------------------------

    
    public static int[] getSolucao() {
        return melhor_solucao;
    }
}
