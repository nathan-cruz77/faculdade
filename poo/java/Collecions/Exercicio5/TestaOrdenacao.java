/*
 *  Programa escrito com propósito didático apenas.
 *  @author Nathan Cruz <nathan.cruz@unifesp.br>
 *  @created 04/04/14
 *  R.A.: 86492
 */

import java.util.*;

public class TestaOrdenacao{
	public static void main(String args[]){
		ArrayList<ContaPoupanca> lista = new ArrayList();
		ContaPoupanca aux;
		int i;
		String[] nomes = {"Alfredo", "Mariane", "Rafael", "Joao", "Fernando"};

		/* Inicializa a lista */
		for(i=0; i<5; i++){
			lista.add(new ContaPoupanca(i, nomes[i]));
		}

		/* Coloca saldo nas contas da lista */
		for(i=0; i<5; i++){
			aux = lista.get(i);
			if(i%2 == 0) aux.credita(i*2);
			else aux.credita(i*3);
		}

		/* Imprime as contas desordenadas */
		for(i=0; i<5; i++){
			aux = lista.get(i);
			aux.imprime();
		}

		System.out.println("\n*******************ORDENADA**********************\n");

		/* Ordena as contas de acordo com o saldo */
		Collections.sort(lista);

		/* Imprime as contas ordenadas */
		for(i=0; i<5; i++){
			aux = lista.get(i);
			aux.imprime();
		}

		System.out.println("\n******************INVERTIDA**********************\n");

		/* Inverte a lista */
		Collections.reverse(lista);

		/* Imprime a lista invertida */
		for(i=0; i<5; i++){
			aux = lista.get(i);
			aux.imprime();
		}

		System.out.println("\n******************EMBARALHADA********************\n");

		/* Embaralha a lista */
		Collections.shuffle(lista);

		/* Imprime a lista embaralhada */
		for(i=0; i<5; i++){
			aux = lista.get(i);
			aux.imprime();
		}

		System.out.println("\n******************ROTACIONADA********************\n");

		/* Ordena a lista para mostrar a rotacao a partir desta */
		Collections.sort(lista);

		/* Rotaciona a lista 1 casa para a direita */
		Collections.rotate(lista, 1);

		/* Imprime a lista rotacionada */
		for(i=0; i<5; i++){
			aux = lista.get(i);
			aux.imprime();
		}

	}
}
