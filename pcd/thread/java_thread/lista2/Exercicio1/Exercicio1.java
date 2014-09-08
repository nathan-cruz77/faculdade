import java.util.*;
import java.lang.*;

public class Exercicio1{
	public static void main(String[] args){
		/* Constantes */
		int MAX_THREADS = 8;
		double TAMANHO = 100000000;

		/* Auxiliares */
		double soma, media, final_result;
		Random rand = new Random();

		/* Vetor de dados */
		double[] dados = new double[(int) TAMANHO];

		/* Vetores de trabalhadores */
		Thread[] threads_1 = new Thread[MAX_THREADS];
		Thread[] threads_2 = new Thread[MAX_THREADS];

		TrabalhadorMedia[] trabalhadores_1 = new TrabalhadorMedia[MAX_THREADS];
		TrabalhadorDesvio[] trabalhadores_2 = new TrabalhadorDesvio[MAX_THREADS];

		/* Preenche o vetor aleatoriamente */
		for(int id=0; id<TAMANHO; id++){
			dados[id] = rand.nextLong();
		}

		/* Dispara as threads para calculo da media*/
		for(int id=0; id<MAX_THREADS; id++){
			trabalhadores_1[id] = new TrabalhadorMedia(dados, id, MAX_THREADS);
			threads_1[id] = new Thread(trabalhadores_1[id]);
			threads_1[id].start();
		}

		/* Aguarda as threads finalizarem */
		soma = 0;
		for(int id=0; id<MAX_THREADS; id++){
			try{
				threads_1[id].join();
			}
			catch(Exception e){
				System.out.println("Erro");
			}

			//System.out.println("(Thread["+ id +"]) retornou " + trabalhadores_1[id].getResult());
			soma += trabalhadores_1[id].getResult();
		}

		media = soma/TAMANHO;

		//System.out.println("Media = " + media);

		/* Dispara as threads para calculo do desvio */
		for(int id=0; id<MAX_THREADS; id++){
			trabalhadores_2[id] = new TrabalhadorDesvio(dados, id, MAX_THREADS, media);
			threads_2[id] = new Thread(trabalhadores_2[id]);
			threads_2[id].start();
		}

		/* Aguarda as threads finalizarem */
		soma = 0;
		for(int id=0; id<MAX_THREADS; id++){
			try{
				threads_2[id].join();
			}
			catch(Exception e){
				System.out.println("Erro");
			}
			soma += trabalhadores_2[id].getResult();
		}

		//System.out.println("soma = " + soma);

		/* Calcula o resultado final */
		final_result = Math.sqrt(1/(TAMANHO-1)*soma);

		/*System.out.printf("Vetor de dados utilizado:\n[");
		for(int id=0; id<TAMANHO; id++)
			System.out.printf("%.2f ", dados[id]);
		System.out.printf("]\n");*/

		/* Exibe o desvio padrao calculado */
		System.out.println("Desvio padrao calculado: " + final_result);
	}
}
