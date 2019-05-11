
package projeto_apa_tsp;

import java.io.BufferedReader;
import java.io.FileReader;

/**
 *
 * @author yorda
 */
public class arquivo_teste {
    
    public void ler_arquivo_teste(String caminho){
        
        int i, j;
        String aux;
        String guardar = null;
        String linha = null;
        
        try {
            BufferedReader hy = new BufferedReader(new FileReader(caminho));
            
            while((linha = hy.readLine()) != null){
                
            }
            
            
        }
        catch (Exception e) {
                e.printStackTrace();
        }
    }
        
}
