import java.util.Random;

public class ProdutoEscalar implements Runnable {

    static int n = 100000, nT = 1, intervalo;
    static double[] vet1, vet2;
    static double resultado;

    synchronized void incrementa(double a){
        this.resultado += a;
    }

    public static void main(String[] args) throws InterruptedException {
        nT = Integer.parseInt(args[0]);
        n = Integer.parseInt(args[1]);
        System.out.println("Threads: " + nT);
        System.out.println("Entrada: " + n);

        intervalo = n / nT;
        resultado = 0;

        vet1 = new double[n];
        vet2 = new double[n];

        Random rand = new Random();

        for (int i = 0; i < n; i++)
        {
            vet1[i] = rand.nextDouble();
            vet2[i] = rand.nextDouble();
        }

        long tempoInicial = System.currentTimeMillis();

        Thread[] th = new Thread[nT];
        ProdutoEscalar[] pe = new ProdutoEscalar[nT];
        for(int i = 0; i < nT; i++)
        {
            pe[i] = new ProdutoEscalar(i);
            th[i] = new Thread(pe[i]);
            th[i].start();
        }

        for(int i = 0; i < nT; i++)
        {
            th[i].join();
            //System.out.println("thread " + i + " acabou");
    }

        long tempoFinal = System.currentTimeMillis() - tempoInicial;

        System.out.println(tempoFinal + "ms");
    }

    private final int id;

    public ProdutoEscalar(int id)
    {
        this.id = id;
    }

    @Override
    public void run()
    {
        soma();
    }

    private void soma()
    {
        try{
            int ini = intervalo * id;
            int fim = ini + intervalo;

            double soma = 0;

            while(ini < fim)
            {
                soma += vet1[ini] * vet2[ini];

                ini++;
            }

            this.incrementa(soma);
        }

        catch (Exception ex){
            System.out.println("ERRO");
        }
    }
}
