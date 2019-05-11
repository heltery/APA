
package projeto_apa_tsp;

import static projeto_apa_tsp.Projeto_APA_TSP.*;
/**
 *
 * @author yorda
 */
public class mov_vizinhanca {
    
    int[] lista_solucao_2opt;
    
    // 2-OPT
    //--------------------------------------------------------------------------
    public int[] dois_opt(int[][] m, int[] solucao_inicial, int custo_inicial) {

        int[] solucao_2opt = solucao_inicial.clone();
        int i, j;

        int novo_custo_2opt;

        for (i = 1; i < solucao_2opt.length - 1; i++) {

            int[] aux_solucao = solucao_2opt.clone();

            for (j = i + 1; j < solucao_2opt.length; j++) {

                int aux = aux_solucao[i];
                aux_solucao[i] = aux_solucao[j];
                aux_solucao[j] = aux;

                novo_custo_2opt = cal_custo(m, aux_solucao);

                if (novo_custo_2opt < custo_inicial) {
                    custo_inicial = novo_custo_2opt;
                    solucao_2opt = aux_solucao.clone();
                    
                 //   System.out.println("--------------------------------------"); 
                  //  System.out.println("SOLUCAO NO 2-OPT: " + imprimir_solucao(solucao_2opt));
                  //  System.out.println("Custo:" + custo_inicial + "\n");             
                }
            }
        }

        return solucao_2opt;
    }
    //--------------------------------------------------------------------------
    
    // RE-INSERTION
    //--------------------------------------------------------------------------
    public static int[] reinsertion(int[][] m, int[] solucao_inicial, int custo_inicial) {

        int[] solucao_reinsertion = solucao_inicial.clone();
        int aux_custo;
        int aux;
        int i, j;

        for (j = 1; j < solucao_reinsertion.length; j++) {

            int[] aux_solucao = solucao_reinsertion.clone();

            for (i = 1; i < solucao_reinsertion.length - 1; i++) {

                aux = aux_solucao[j];
                aux_solucao[j] = aux_solucao[i];
                aux_solucao[i] = aux;

                aux_custo = cal_custo(m, aux_solucao);

                if (aux_custo < custo_inicial) {

                    custo_inicial = aux_custo;
                    solucao_reinsertion = aux_solucao.clone();

                }
                
            }

        }
        return solucao_reinsertion;
    }
    //--------------------------------------------------------------------------
    
    // VND
    //--------------------------------------------------------------------------
    public void vnd(int custo, int[][] m, int[] solucao_inicial) {

        int[] aux_solucao = solucao_inicial.clone();
        int aux_custo = custo;
        
        int[] lista_solucao_2opt = null;
        int[] lista_solucao_reinsertion = null;
       
        int novo_custo = 0;
        
        int controle_k = 1; 
        int r = 2; //quantidade movimentos de vizinhança

        while ( controle_k <= r ){
           
            if (controle_k == 1){
                
            // -> EXECUTA O 2OPT
            //------------------------------------------------------------------         
                
                lista_solucao_2opt = dois_opt(m, aux_solucao, aux_custo);
                novo_custo = cal_custo(m, lista_solucao_2opt);
                
                if (novo_custo < aux_custo) {
                    
                    aux_solucao = lista_solucao_2opt.clone();
                    aux_custo = novo_custo;
                    controle_k = 1;
                
                } 
                
                else {
                    
                    novo_custo = aux_custo; //volto o custo anterior
                    lista_solucao_2opt = aux_solucao.clone();//volto a solucao anterior que era menor
                    controle_k = controle_k + 1;
                    
                    System.out.println("Finalizando Execução do 2-OPT no VND");
                    System.out.println("Solução: "+ imprimir_solucao(aux_solucao) + "");
                    System.out.println("Custo: " + aux_custo + "");
                }
                
                
            
            //------------------------------------------------------------------
            }
            
            lista_solucao_reinsertion = lista_solucao_2opt.clone();
            aux_solucao = lista_solucao_reinsertion.clone();
            aux_custo = novo_custo;
            
            if(controle_k == 2){
                
            // -> EXECUTA O REINSERTION
            //------------------------------------------------------------------
              
                lista_solucao_reinsertion = reinsertion(m, aux_solucao, aux_custo);
                
                novo_custo = cal_custo(m, lista_solucao_reinsertion);
                
                if (novo_custo < aux_custo) {
                    
                    aux_solucao = lista_solucao_reinsertion.clone();
                    aux_custo = novo_custo;
                    controle_k = 2;
                     
                } 
                
                else {

                    lista_solucao_reinsertion = aux_solucao.clone();
                    novo_custo = aux_custo;
                    controle_k = controle_k + 1;
                    
                    System.out.println("Finalizando Execução do REINSERTION no VND");
                    System.out.println("Solução: "+ imprimir_solucao(aux_solucao) + "");
                    System.out.println("Custo: " + aux_custo + "");
                }
                
            }
                //--------------------------------------------------------------
        }
     }
    //--------------------------------------------------------------------------
    
  }