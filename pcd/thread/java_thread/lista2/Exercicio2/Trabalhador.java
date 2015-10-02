import java.util.*;

public class Trabalhador implements Runnable{

    /* Atributos */
    private int[][] dados;
    private int id, MAX_THREADS;

    public Trabalhador(int[][] dados, int id, int MAX_THREADS){
        this.MAX_THREADS = MAX_THREADS;
        this.id = id;
        this.dados = dados;
    }

    /* Corpo da thread */
    public void run(){
        int linha_inicial, linha_final;

        linha_inicial = this.id*(this.dados.length/this.MAX_THREADS);

        if(this.id < MAX_THREADS-1)
            linha_final = linha_inicial+(this.dados.length/this.MAX_THREADS);
        else
            linha_final = this.dados.length-1;

        System.out.println("(Thread["+this.id+"]) Iniciando");

        for(int i=linha_inicial; i<=linha_final; i++){
            Arrays.sort(this.dados[i]);
        }
    }
}
