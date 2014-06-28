public class Exercicio1{
	public static void main(String args[]){

		/* Quantidade de threads */
		int max_threads = 8;

		/* Valores que o professor pediu */
		double elevado_5 = 100000;
		double elevado_6 = 1000000;
		double elevado_7 = 10000000;

		/* Variaveis para guardar o tempo */
		double tempo_parcial;
		double tempo_total;

		/* Threads */
		Fluxo[] threads = new Fluxo[quantidade];

		/* Cria todas as threads, dispara e mede o tempo */
		tempo_total = System.currentMillis();

		/* Dispara as threads */
		for(int j=0; j<max_threads; j++){
			for(int i=0; i<quantidade; i++){
				threads[i] = new Thread(new Fluxo(elevado_5));
				threads[i].start();
			}
		}

		/*  */

		tempo_total -= System.currentMillis();
	}
}
