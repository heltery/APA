
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
                    
                    System.out.println("--------------------------------------"); 
                    System.out.println("SOLUCAO NO 2-OPT: " + imprimir_solucao(solucao_2opt));
                    System.out.println("Custo:" + custo_inicial + "\n");             
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
        int novo_custo_reinsertion;
        int i, j;

        for (j = 1; j < solucao_reinsertion.length; j++) {

            int[] aux_solucao = solucao_reinsertion;

            for (i = j; i < solucao_reinsertion.length - 1; i++) {

                int aux = aux_solucao[i];
                aux_solucao[i] = aux_solucao[i + 1];
                aux_solucao[i + 1] = aux;

                novo_custo_reinsertion = cal_custo(m, solucao_reinsertion);

                if (novo_custo_reinsertion < custo_inicial) {

                    custo_inicial = novo_custo_reinsertion;
                    solucao_reinsertion = aux_solucao.clone();
                    
                    System.out.println("--------------------------------------"); 
                    System.out.println("SOLUCAO NO REINSERTION: " + imprimir_solucao(solucao_reinsertion));
                    System.out.println("Custo:" + custo_inicial + "\n");

                }

            }

        }
        return solucao_reinsertion;
    }
    //--------------------------------------------------------------------------
    
    // VND
    //--------------------------------------------------------------------------
    public void vnd(int custo, int[][] m, int[] solucao_inicial) {

        int[] lista_solucao_R = solucao_inicial.clone();
        int[] aux_solucao_R = lista_solucao_R.clone();
        int interacao = 0;
        int custo_anterior = custo;
        int novo_custo;
        int[] melhor_solucao;
        int flag_VND = 0;

        while (interacao < 10) {
            
            if (flag_VND == 0)  {            
                
                lista_solucao_R = dois_opt(m, aux_solucao_R, custo_anterior);
                novo_custo = cal_custo(m, lista_solucao_R);
                
                if (novo_custo >= custo_anterior) {
                    
                    novo_custo = custo_anterior;
                    lista_solucao_R = aux_solucao_R.clone();
                    
                    interacao = interacao + 1;
                    flag_VND = 1;

                } 
                
                else {
                    aux_solucao_R = lista_solucao_R.clone();
                    custo_anterior = novo_custo;
                    System.out.println("(-------------------------------------");
                    System.out.println("(*)MELHOR SOLUCAO DO 2-OPT NO VND: " + imprimir_solucao(lista_solucao_R) + "0");
                    System.out.println("(*)CUSTO: " + custo_anterior + "\n");

                }
            }    

            lista_solucao_2opt = lista_solucao_R.clone();

            if (flag_VND == 1) {
                
                lista_solucao_2opt = reinsertion(m, lista_solucao_R, custo_anterior);
                
                novo_custo = cal_custo(m, lista_solucao_2opt);
                
                if (novo_custo > custo_anterior) {
                    
                    lista_solucao_2opt = lista_solucao_R.clone();
                    novo_custo = custo_anterior;
                    interacao = interacao + 1;
                    flag_VND = 0;

                } 
                
                else {

                    aux_solucao_R = lista_solucao_2opt.clone();
                    custo_anterior = novo_custo;
                    
                    System.out.println("(-------------------------------------");
                    System.out.println("(*)MELHOR SOLUCAO DO 2-OPT NO VND: " + imprimir_solucao(aux_solucao_R) + "0");
                    System.out.println("(*)CUSTO: " + custo_anterior + "\n");

                }

            }
        }
            System.out.println("---> NUMERO DE INTERACOES: " + interacao + "\n");
 }
    //--------------------------------------------------------------------------
}