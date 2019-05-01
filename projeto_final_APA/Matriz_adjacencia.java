/**
 * Dupla: Helter Yordan
 *        Gabriel Alcantara
 */
package TSP_APA;

import java.io.*;
import java.io.FileOutputStream;
import java.util.ArrayList;
import javax.swing.JOptionPane;
import static TSP_APA.TSP.Aresta;
import static TSP_APA.TSP.ExibirSolucao;
import static TSP_APA.TSP.obter_custo;


public class Matriz_adjacencia {

    public static int resultado = 0;

    //criação da nossa matriz de adjacencias com os dados obtidos do arquivo
    public int[][] matriz(ArrayList<Integer> v, ArrayList<Float> x, ArrayList<Float> y) throws FileNotFoundException {

        int[][] M = new int[v.size()][v.size()];
        for (int i = 0; i < v.size(); i++) {
            for (int j = 0; j < v.size(); j++) {
                if (M[i][j] == 0) {
                    if (v.get(i) >= v.size()) {
                        break;
                    }
                    if (v.get(i) == v.get(j)) {
                        M[i][j] = 0;
                    } else if (v.get(i) != v.get(j)) {
                        float resultado = Aresta(x.get(i), x.get(j), y.get(i), y.get(j));
                        resultado = Math.round(resultado);
                        M[i][j] = (int) resultado;
                        if (M[i][j] != M[j][i]) {
                            M[j][i] = (int) resultado;
                        }
                    }
                }
            }
        }
        
        return M;
    }
    //---------------------------------------------------------------------------------------------------------------
}
