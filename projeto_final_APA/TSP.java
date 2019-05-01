package TSP_APA;

import java.awt.Dimension;
import java.io.*;
import static java.lang.Math.*;
import java.util.*;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JTable;
import static TSP_APA.Vizinho_Proximo.*;
import static TSP_APA.Matriz_adjacencia.resultado;

/**
 *
 * @author erber
 */
public class TSP {

    int[] custoTotal = null;

    public static float Aresta(float x1, float x2, float y1, float y2) {

        float aresta = 0;
        float x;
        float y;
        x = x1 - x2;
        y = y1 - y2;
        aresta = (float) sqrt(Math.pow(x, 2) + Math.pow(y, 2));
        return aresta;
    }

    public static int obter_custo(int[][] M, int[] listaSolucao) {

        int custo = 0;
        int i = 0;
        for (i = 0; i < listaSolucao.length - 1; i++) {
            custo += M[listaSolucao[i]][listaSolucao[i + 1]];
            //System.out.println("Os valores da Solução: " + listaSolucao[i]);
        }

        custo += M[listaSolucao[i]][0];

        return custo;
    }

    public static String ExibirSolucao(int[] solucao) {
        String arraySolucao = "";
        for (int i = 0; i < solucao.length; i++) {
            arraySolucao += String.valueOf(solucao[i]) + ", ";

        }

        return arraySolucao;
    }

    public static void main(String[] args) throws FileNotFoundException {

        String caminho = JOptionPane.showInputDialog("Digite a instância");
        System.out.println(caminho);
        BufferedReader br = new BufferedReader(new FileReader(caminho));

        Ler_arquivo arquivo = new Ler_arquivo();
        Matriz_adjacencia matrizAdj = new Matriz_adjacencia();
        Vizinho_Proximo menor = new Vizinho_Proximo();
        Busca_local rein = new Busca_local();
        Busca_local twoOpt = new Busca_local();

        arquivo.ler(caminho);
        ArrayList<Float> x = arquivo.x;
        ArrayList<Float> y = arquivo.y;
        ArrayList<Integer> v = arquivo.vertices;

        int[][] recebeMatriz = matrizAdj.matriz(v, x, y);

        int[] solucaoKNN = menor.Menor_distancia(recebeMatriz, 0);
        int custoKNN = obter_custo(recebeMatriz, solucaoKNN);

        System.out.println("Solucão KNN: \n" + ExibirSolucao(solucaoKNN) + "0");
        System.out.println("O Custo da Solução KNN: " + custoKNN);

        //twoOpt
        //int[] solucaoTwoOpt = twoOpt.TwoOpt(recebeMatriz, solucaoKNN, custoKNN);
        //int custoTwoOpt = obter_custo(recebeMatriz, solucaoTwoOpt);
        
        //System.out.println("Solucão twoOpt: \n" + ExibirSolucao(solucaoTwoOpt) + "0");
        //System.out.println("O Custo da Solução TwoOpt: " + custoTwoOpt);

        //reinsertion
        int[] solucaoRein = rein.Reinsertion(recebeMatriz, solucaoKNN, custoKNN);
        int custoRein = obter_custo(recebeMatriz, solucaoRein);
        System.out.println("Solucão REINSERTION: \n" + ExibirSolucao(solucaoRein) + "0");
        System.out.println("O Custo da Solução REINSERTION: " + custoRein);
    }
}
