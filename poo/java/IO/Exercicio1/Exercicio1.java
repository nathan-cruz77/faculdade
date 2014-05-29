/*
 *  Programa escrito com propósito didático apenas.
 *  @author Nathan Cruz <nathan.cruz@unifesp.br>
 *  @created 28/03/14
 *  R.A.: 86492
 */

import java.util.*;
import java.io.*;

public class Exercicio1{
	public static void main(String args[]){
		Scanner entrada = new Scanner(System.in);
		FileReader arquivo;
		File arq;
		String s;
		char c;
		int contador, i;

		System.out.println("Entre com o nome do arquivo: ");
		s = entrada.nextLine();
		arq = new File(s);

		if(arq.exists() && arq.isFile()){
			contador = 0;
			try{
				arquivo = new FileReader(s);
				while(true){
					i = arquivo.read();
					if( i == -1) break;
					c = (char) i;
					if(c == 'a' || c == 'A')
						contador++;
				}
				arquivo.close();
			}
			catch(IOException e){
				System.out.println(e);
			}
			System.out.println(contador + " ocorrencias do caractere 'a' ou 'A' encontradas em " + s);
		}
		else{
			System.out.println("Arquivo inexistente!");
		}
	}
}
