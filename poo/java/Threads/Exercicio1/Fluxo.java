import java.lang.*;

public class Fluxo implements Runnable{

    /* Atributos */
    private double[] vetor;
    private double tamanho;
    public static double result;

    public Fluxo(double tamanho){
        this.vetor = new double[tamanho];
        this.tamanho = tamanho;
    }

    /* Popula o vetor */
    private void Popula(){
        Random aux = new Random();

        for(double i=0; i<this.tamanho; i++){
            this.vetor[i] = aux.nextDouble(this.tamanho);
        }
    }

    /* Calcula o desvio padrao */
    private void Desvio(){
        double fracao, media=0, soma=0;

        fracao = 1/(this.tamanho-1);

        /* Calcula a madia aritimetica */
        for(double i=0; i<this.tamanho; i++){
            media += this.vetor[i]/this.tamanho;
        }

        /* Calcula a soma */
        for(double i=0; i<this.tamanho; i++){
            soma += this.vetor[i] - media;
        }

        /* Eleva a soma ao quadrado */
        soma *= soma;

        this.result = Math.sqrt(fracao * soma);
    }

    /* Main da thread */
    public void run(){

        /* Popula o vetor */
        Popula();

        /* Calcula o desvio padrao */
        Desvio();
    }
}
