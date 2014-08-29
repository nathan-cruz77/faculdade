public class TrabalhadorMedia implements Runnable{
	private double[] dados;
	private double result;
	private int id;
	private double soma = 0;
	private int MAX_THREADS;

	public TrabalhadorMedia(double[] dados, int id, int MAX_THREADS){
		this.dados = dados;
		this.id = id;
		this.MAX_THREADS = MAX_THREADS;
	}

	/* Getter */
	public double getResult(){
		return this.result;
	}

	/* Funcao que vai fazer o trabalho pesado */
	public void run(){
		int pos_inicial, pos_final, tamanho_local, pos;

		tamanho_local = dados.length/MAX_THREADS;
		pos_inicial = tamanho_local*id;
		pos_final = (pos_inicial + tamanho_local)-1;

		//System.out.println("(Thread["+id+"]) pos ["+pos_inicial+" - "+pos_final+"]");
		for(pos=pos_inicial; pos<=pos_final; pos++){
			soma += dados[pos];
		}
		result = soma;
	}
}
