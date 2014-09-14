/*
 *  Programa escrito com propósito didático apenas.
 *  @author Nathan Cruz <nathan.cruz@unifesp.br>
 *  @created 04/04/14
 *  R.A.: 86492
 */

import java.util.*;

public class TestaPerformance {
    public static void main(String[] args) {

        System.out.println("Iniciando...");
        long inicio_global = System.currentTimeMillis();
        long fim_global;
        long tempo_global;

        long inicio = System.currentTimeMillis();

        /* Inicializa estruturas de dados (collections) */
        Collection<Integer> teste1 = new ArrayList<Integer>();
        Collection<Integer> teste2 = new LinkedList<Integer>();
        Collection<Integer> teste3 = new HashSet<Integer>();

        /* Inicializa variaveis auxiliares */
        int total = 30000;
        long fim;
        long tempo;

        /* Exibe o tempo de inicializacao das variaveis */
        fim = System.currentTimeMillis();
        tempo = fim - inicio;
        System.out.println("\nTempo de inicializacao das variaveis: " + tempo + "ms");

        /* Faz testes com a estrutura ArrayList */
        System.out.println("\nTestes com a estrutura ArrayList:");
        inicio = System.currentTimeMillis();

        /* Popula o ArrayList */
        for (int i = 0; i < total; i++) {
            teste1.add(i);
        }

        /* Imprime o tempo de preenchimento da estrutura ArrayList */
        fim = System.currentTimeMillis();
        tempo = fim - inicio;
        System.out.println("\tTempo de preenchimento: " + tempo + "ms");

        inicio = System.currentTimeMillis();
        /* Pesquisa os elementos no vetor */
        for (int i = 0; i < total; i++) {
            teste1.contains(i);
        }

        /* Imprime o tempo de pesquisa na estrutura ArrayList */
        fim = System.currentTimeMillis();
        tempo = fim - inicio;
        System.out.println("\tTempo de pesquisa: " + tempo + "ms");



        /* Faz testes com a estrutura LinkedList */
        System.out.println("\nTestes com a estrutura LinkedList:");
        inicio = System.currentTimeMillis();

        /* Popula o LinkedList */
        for (int i = 0; i < total; i++) {
            teste2.add(i);
        }

        /* Imprime o tempo de preenchimento da estrutura LinkedList */
        fim = System.currentTimeMillis();
        tempo = fim - inicio;
        System.out.println("\tTempo de preenchimento: " + tempo + "ms");

        inicio = System.currentTimeMillis();
        /* Pesquisa os elementos no vetor */
        for (int i = 0; i < total; i++) {
            teste2.contains(i);
        }

        /* Imprime o tempo de pesquisa na estrutura LinkedList */
        fim = System.currentTimeMillis();
        tempo = fim - inicio;
        System.out.println("\tTempo de pesquisa: " + tempo + "ms");



        /* Faz testes com a estrutura HashSet */
        System.out.println("\nTestes com a estrutura HashSet:");
        inicio = System.currentTimeMillis();

        /* Popula o HashSet */
        for (int i = 0; i < total; i++) {
            teste3.add(i);
        }

        /* Imprime o tempo de preenchimento da estrutura HashSet */
        fim = System.currentTimeMillis();
        tempo = fim - inicio;
        System.out.println("\tTempo de preenchimento: " + tempo + "ms");

        inicio = System.currentTimeMillis();
        /* Pesquisa os elementos no vetor */
        for (int i = 0; i < total; i++) {
            teste3.contains(i);
        }

        /* Imprime o tempo de pesquisa na estrutura ArrayList */
        fim = System.currentTimeMillis();
        tempo = fim - inicio;
        System.out.println("\tTempo de pesquisa: " + tempo + "ms");

        /* Imprime tempo total gasto */
        fim_global = System.currentTimeMillis();
        tempo_global = fim_global - inicio_global;
        System.out.println("\nTempo total: " + tempo_global + "ms");
    }
}

