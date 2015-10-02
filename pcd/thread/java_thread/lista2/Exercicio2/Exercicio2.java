import java.util.*;

public class Exercicio2{
    public static void print_matrix(int[][] dados){
        System.out.println();
        for(int i=0; i<dados.length; i++){
            for(int j=0; j<dados.length; j++){
                if(dados[i][j] < 0)
                    System.out.printf("%d ", dados[i][j]);
                else
                    System.out.printf(" %d ", dados[i][j]);
            }
            System.out.printf("\n");
        }
    }

    public static void main(String[] args){
        int MAX_THREADS = 3;
        int TAMANHO = 10000; // 10**3

        /* Matriz de dados a serem ordenados */
        int[][] dados = new int[TAMANHO][TAMANHO];

        /* Geracao de dados aleatorios */
        Random rand = new Random();

        /* Auxiliares */
        long inicio, fim, tempo;

        /* Vetor auxiliar */
        Thread[] threads = new Thread[MAX_THREADS];

        /* Preenche a matriz aleatoriamente */
        for(int lin=0; lin<TAMANHO; lin++){
            for(int col=0; col<TAMANHO; col++){
                dados[lin][col] = rand.nextInt() % 10;
            }
        }

        //Exercicio2.print_matrix(dados);

        /* Dispara as threads */
        inicio = System.currentTimeMillis();
        for(int id=0; id<MAX_THREADS; id++){
            threads[id] = new Thread(new Trabalhador(dados, id, MAX_THREADS));
            threads[id].start();
        }

        /* Aguarda as threads finalizarem */
        for(int id=0; id<MAX_THREADS; id++){
            try{
                threads[id].join();
            }
            catch(Exception e){
                System.out.println("Erro no join");
            }
        }
        fim = System.currentTimeMillis();

        tempo = fim - inicio;

        //Exercicio2.print_matrix(dados);
        System.out.println("Tempo de ordenacao: "+ tempo +"ms");
    }
}
