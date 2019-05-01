/**
 * Dupla: Helter Yordan
 *        Gabriel Alcantara
 */

package TSP_APA;

import java.io.BufferedReader;
import java.io.FileReader;
import java.util.ArrayList;


public class Ler_arquivo {

        String armazena = null;
        String linha = null;
        ArrayList<Integer> vertices = new ArrayList<Integer>();
        ArrayList<Float> x = new ArrayList<Float>();
        ArrayList<Float> y = new ArrayList<Float>();
        String[] string_corte = new String[2];

        
        public void ler(String caminho){
            
            try {
            BufferedReader br = new BufferedReader(new FileReader(caminho));

            while ((linha = br.readLine()) != null) {
                
                //retirando o espaço em branco da frente
                linha = linha.trim();
                //--------------------------------------
                
                //vemos que os valores tem um espaço de 3... dai tiramos esse espaço e gravamos os dados
                string_corte = linha.split("   "); //separa os itens do arquivo de acordo com o separador de 3 espaços
                //---------------------------------------------------------------------------------------------------
                
                
                int i = 0;

                for (String element : string_corte) {
                    switch (i) {
                        case 0:
                            vertices.add(Integer.parseInt(element));
                            break;
                        case 1:
                            x.add(Float.parseFloat(element));
                            break;
                        case 2:
                            y.add(Float.parseFloat(element));
                            break;
                    }
                    i++;
                }
            }
            
            br.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
        
    }
}
        

