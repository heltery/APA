
package projeto_apa_tsp;

import static java.lang.System.in;
import javax.swing.JOptionPane;

/**
 *
 * @author yorda
 */
public class knn {
    
    public static int[] solucao;

    // CONSTRUINDO A SOLUÇÃO DO VIZINHO MAIS PROXIMO
    //--------------------------------------------------------------------------
    public static int[] solucao_vizinho_proximo(int[][] m, int origem) {

        solucao = new int[m[0].length];

        for (int i = 0; i < solucao.length; i++) { //INICIANDO COM O VETOR DE SOLUCAO EM INFINITO, TODOS OS CUSTOS EM INFINITO
            solucao[i] = Integer.MAX_VALUE;
        }

        solucao[0] = origem; //ZERO É O VETOR DE ORIGEM E O PRIMIERO A ANALIZARMOS OS SEUS VIZINHOS
        int atual = origem;

        int i = 1;

        while (i < solucao.length) {
            int proxima = cidade_mais_proxima(m[atual]);
            
            if (proxima != -1) { //SE A CIDADE AINDA NÃO FOI VIZITADA ELA É INSERIDA NA SOLUÇÃO E ANALIZAREMOS OS SEUS VIZINHOS
                solucao[i] = proxima;
                atual = proxima;
                i++;
            }
        }
        return solucao;
    }
    //--------------------------------------------------------------------------
    
    // BUSCAMOS O MENOR CUSTO NO CAMINHO A SEGUIR
    //--------------------------------------------------------------------------
    public static int cidade_mais_proxima(int[] caminho) {
        
        int prox_cidade = -1;
        int i = 0;
        int minimo = Integer.MAX_VALUE;

        while (i < caminho.length) { //CASO A CIDADE ESTEJA NA ROTA E SEU CUSTO SEJA O MENOR NA INTERAÇÃO ELA SERA ADCIONADA COMO PROXIMA CIDADE E SEU CUSTO IRA COMPOR O CAMINHO
            
            if (!verif_cidade_trajeto(solucao, i) && caminho[i] < minimo) {
                minimo = caminho[i];
                prox_cidade = i;
            }

            i++;

        }
        return prox_cidade;
    }
    //--------------------------------------------------------------------------

    //VERIFICANDO SE A CIDADE JA ESTA NA SOLUCAO
    //--------------------------------------------------------------------------
    public static boolean verif_cidade_trajeto(int[] solucao, int cidade) {
        for (int i = 0; i < solucao.length; i++) {
            if (solucao[i] == cidade) {
                return true;
            }
        }
        return false;
    }
    //--------------------------------------------------------------------------
    
    // RETORNANDO A SOLUÇÃO DO VIZINHO MAIS PROXIMO
    //--------------------------------------------------------------------------
    public static int[] get_solucao() {
        return solucao;
    }
    //--------------------------------------------------------------------------
}
