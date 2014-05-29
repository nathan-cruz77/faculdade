/*
 *  Programa escrito com propósito didático apenas.
 *  @author Nathan Cruz <nathan.cruz@unifesp.br>
 *  @created 28/03/14
 *  R.A.: 86492
 */

import java.util.*;
import java.io.*;

public class Exercicio2{

	/* Funcao que faz a transferencia de conteudo entre arquivos
	 * statica pois nao depende da classe onde eh descrita e,
	 * portanto nao precisa estar vinculada a nenhum objeto */
	public static void transfere(FileReader entrada, FileWriter saida) throws IOException{
			for(int i=0; i != -1; i = entrada.read())
				saida.write(i);
			entrada.close();
			saida.close();
	}

	public static void main(String args[]){
		Scanner entrada = new Scanner(System.in);
		String s1, s2;
		FileReader arq1;
		FileWriter arq2;

		System.out.print("Entre com o nome do arquivo de entrada: ");
		s1 = entrada.nextLine();
		System.out.print("Entre com o nome do arquivo de saida: ");
		s2 = entrada.nextLine();

		try{
			arq1 = new FileReader(s1);
			arq2 = new FileWriter(s2);

			System.out.println("Iniciando a transferencia...");
			transfere(arq1, arq2);
			System.out.println("Transferencia completa");
		}
		catch(IOException e){
			System.out.println(e);
		}
	}
}
