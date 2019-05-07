
package projeto_apa_tsp;

import java.awt.Dimension;
import java.io.*;
import static java.lang.Math.*;
import java.util.*;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.SwingConstants;

/**
 *
 * @author yorda
 */
public class Projeto_APA_TSP {

    int[] custoTotal = null;

    // CALCULANDO O CUSTO DA SOLUCAO ENCONTRADA
    //--------------------------------------------------------------------------
    public static int cal_custo(int[][] M, int[] solucao) {

        int custo = 0;
        int i = 0;
        for (i = 0; i < solucao.length - 1; i++) {

            custo = custo + M[solucao[i]][solucao[i + 1]];
        }
        custo = custo + M[solucao[i]][0];

        return custo;
    }
    //--------------------------------------------------------------------------
    
    // IMPRIMIR O VETOR DE SOLUCAO QUE ENCONTRAMOS
    //--------------------------------------------------------------------------
    public static String imprimir_solucao(int[] solucao) {
        String vetor_solucao = "";
        for (int i = 0; i < solucao.length; i++) {
            vetor_solucao += String.valueOf(solucao[i]) + ", ";
        }
        return vetor_solucao;
    }
    //--------------------------------------------------------------------------
    
    // CALCULANDO A DISTANCIA EUCLIDIANA ENTRE OS PONTOS DE COORDENADAS X E Y
    //--------------------------------------------------------------------------
    public static float cal_distancia_euclidiana(float x1, float x2, float y1, float y2) {

        float dist = 0;
        float x;
        float y;
        x = x1 - x2;
        y = y1 - y2;
        dist = (float) sqrt(Math.pow(x, 2) + Math.pow(y, 2));
        return dist;
    }
    //--------------------------------------------------------------------------

    public static void main(String[] args) throws FileNotFoundException {

        // APRESENTAÇÃO DO TRABALHO + SOLICITAÇÃO DO NOME DO ARQUIVO
        //----------------------------------------------------------------------
        
        JOptionPane.showMessageDialog(null, "\n"
                + "                         U.F.P.B\n"
                + "ANALISE E PROJETOS DE ALGORITMOS\n"
                + "\n"
                + " --------------------DUPLA:-----------------\n"
                + "HELTER YORDAN\n"
                + "GABRIEL ALCANTARA\n"
                + "------------------------------------------------\n"
                + "\n"
                + "PROJETO FINAL - CAIXEIRO VIAJANTE (TSP)"
                + "\n");
        
        String percurso = JOptionPane.showInputDialog(" ---> Digite a instância: ");
        System.out.println(percurso);
        BufferedReader br = new BufferedReader(new FileReader(percurso));
        //----------------------------------------------------------------------

        arquivo arq = new arquivo();
        matriz matriz_adjacencia = new matriz();
        knn solucao_inicial_knn = new knn();
        //mov_vizinhanca mov_reinsertion = new mov_vizinhanca();
        mov_vizinhanca mov_VND = new mov_vizinhanca();

        arq.ler_arquivo(percurso);
        ArrayList<Float> x = arq.x;
        ArrayList<Float> y = arq.y;
        ArrayList<Integer> v = arq.v;

        int[][] recebeMatriz = matriz_adjacencia.matriz_adj(v, x, y);
        int[] solucaoKNN = solucao_inicial_knn.solucao_vizinho_proximo(recebeMatriz, 0);
        int custoKNN = cal_custo(recebeMatriz, solucaoKNN);

        
        System.out.println("--------------------------------------"); 
        System.out.println("SOLUÇÃO PARA O KNN: \n" + imprimir_solucao(solucaoKNN) + "0");
        System.out.println("CUSTO: " + custoKNN);
        System.out.println("--------------------------------------"); 

         mov_VND.vnd(custoKNN, recebeMatriz, solucaoKNN);

    }
}