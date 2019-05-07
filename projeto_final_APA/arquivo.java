
package projeto_apa_tsp;

import java.io.BufferedReader;
import java.io.FileReader;
import java.util.ArrayList;

/**
 *
 * @author yorda
 */
public class arquivo {
        String guardar = null;
        String linha = null;
        String[] brokeString = new String[2];
        
        // ARMAZENANDO OS VALORES DE VERTICE E COORDENADAS X E Y
        //----------------------------------------------------------------------
        ArrayList<Integer> v = new ArrayList<Integer>();
        ArrayList<Float> x = new ArrayList<Float>();
        ArrayList<Float> y = new ArrayList<Float>();
        //----------------------------------------------------------------------
        
        public void ler_arquivo(String caminho){
            try {
            BufferedReader hy = new BufferedReader(new FileReader(caminho));

            while ((linha = hy.readLine()) != null) {
                linha = linha.trim(); //TRATANDO O ESPAÇO INICIAL
                brokeString = linha.split("   "); //TRATANDO OS 3 ESPAÇOS OBSERVADOS ENTRE AS COORDENADAS

                int h = 0;

                for (String element : brokeString) {
                    switch (h) {
                        case 0:
                            v.add(Integer.parseInt(element));
                            break;
                        case 1:
                            x.add(Float.parseFloat(element));
                            break;
                        case 2:
                            y.add(Float.parseFloat(element));
                            break;
                    }
                    h++;
                }
            }
            hy.close();
            }   
            catch (Exception e) {
                e.printStackTrace();
            }
    }
}
