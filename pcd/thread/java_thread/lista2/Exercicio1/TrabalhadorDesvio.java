import java.lang.*;

public class TrabalhadorDesvio implements Runnable{

    /* Atributos */
    private double[] dados;
    private double result, media;
    private int id, MAX_THREADS;

    public TrabalhadorDesvio(double[] dados, int id,
                             int MAX_THREADS, double media){
        this.dados = dados;
        this.id = id;
        this.MAX_THREADS = MAX_THREADS;
        this.media = media;
    }

    /* Getter */
    public double getResult(){
        return this.result;
    }

    /* Funcao que vai fazer o trabalho pesado */
    public void run(){
        int i, pos;
        double soma, tamanho_parcial;

        tamanho_parcial = dados.length/MAX_THREADS;
        soma = 0;

        System.out.println("(Thread["+ this.id +"]) Iniciada");

        for(i=0, pos=(int) tamanho_parcial*this.id; i<tamanho_parcial; i++, pos++){
            soma += Math.pow(dados[pos] - this.media, 2);
        }

        /* Salva o resultado da soma */
        result = soma;
    }
}
