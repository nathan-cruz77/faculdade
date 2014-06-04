/*
 *  Programa escrito com propósito didático apenas.
 *  @author Nathan Cruz <nathan.cruz@unifesp.br>
 *  @created 04/06/14
 *  R.A.: 86492
 */

public class MaiorApp{
	public static void main(String args[]){

		/* Testa as funcoes com int */
		System.out.println("9, 3: " + Maior.MaiorDeDois(9, 3));
		System.out.println("9, 3, 15: " + Maior.MaiorDeTres(9, 3, 15));
		System.out.println("32, 9, 3, 5: " + Maior.MaiorDeQuatro(32, 9, 3, 5));
		System.out.println("32, 9, 3, 5, 96: " + Maior.MaiorDeCinco(32, 9, 3, 5, 96));

		/* Testa as funcoes com double */
		System.out.println("\n9.6, 9.8: " + Maior.MaiorDeDois(9.6, 9.8));
		System.out.println("9.6, 9.5, 9.8: " + Maior.MaiorDeTres(9.6, 9.5, 9.8));
		System.out.println("18.3, 93.6, 14.6, 88.0: " + Maior.MaiorDeQuatro(18.3, 93.6, 14.6, 88.0));
		System.out.println("32.54, 18.3, 93.6, 14.6, 88.0: " + Maior.MaiorDeCinco(32.54, 18.3, 93.6, 14.6, 88.0));

	}
}
