
package projeto_apa_tsp;

import java.io.*;
import java.io.FileOutputStream;
import java.util.ArrayList;
import javax.swing.JOptionPane;
import static projeto_apa_tsp.Projeto_APA_TSP.cal_distancia_euclidiana;

/**
 *
 * @author yorda
 */
public class matriz {
    
    public static int resultado = 0;
    
    // CRIANDO NOSSA MATRIZ DE ADJACENCIA
    //--------------------------------------------------------------------------
    public int[][] matriz_adj(ArrayList<Integer> v, ArrayList<Float> x, ArrayList<Float> y) throws FileNotFoundException {

        int[][] m = new int[v.size()][v.size()];
        int i, j;
        
        for (i = 0; i < v.size(); i++) {
            for (j = 0; j < v.size(); j++) {
                if (m[i][j] == 0) {
                    if (v.get(i) >= v.size()) {
                        break;
                    }
                    if (v.get(i) == v.get(j)) {
                        m[i][j] = 0;
                    } else if (v.get(i) != v.get(j)) {
                        float resultado = cal_distancia_euclidiana(x.get(i), x.get(j), y.get(i), y.get(j));
                        resultado = Math.round(resultado);
                        m[i][j] = (int) resultado;
                        if (m[i][j] != m[j][i]) {
                            m[j][i] = (int) resultado;
                        }
                    }
                }
            }
        }
        
        return m;
    }
    //--------------------------------------------------------------------------
}
