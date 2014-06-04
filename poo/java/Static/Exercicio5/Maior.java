/*
 *  Programa escrito com propósito didático apenas.
 *  @author Nathan Cruz <nathan.cruz@unifesp.br>
 *  @created 04/06/14
 *  R.A.: 86492
 */

public class Maior{

	/* Metodos para achar o maior valor de elementos (int)*/
	public static int MaiorDeDois(int a, int b){
		if(a > b)
			return a;
		return b;
	}
	public static int MaiorDeTres(int a, int b, int c){
		return MaiorDeDois(MaiorDeDois(a, b), c);
	}
	public static int MaiorDeQuatro(int a, int b, int c, int d){
		return MaiorDeDois(MaiorDeDois(a, b), MaiorDeDois(c, d));
	}
	public static int MaiorDeCinco(int a, int b, int c, int d, int e){
		return MaiorDeDois(MaiorDeTres(a, b, c), MaiorDeDois(d, e));
	}

	/* Metodos para achar o maior valor de elementos (double) */
	public static double MaiorDeDois(double a, double b){
		if(a > b)
			return a;
		return b;
	}
	public static double MaiorDeTres(double a, double b, double c){
		return MaiorDeDois(MaiorDeDois(a, b), c);
	}
	public static double MaiorDeQuatro(double a, double b, double c, double d){
		return MaiorDeDois(MaiorDeDois(a, b), MaiorDeDois(c, d));
	}
	public static double MaiorDeCinco(double a, double b, double c, double d, double e){
		return MaiorDeDois(MaiorDeTres(a, b, c), MaiorDeDois(d, e));
	}

}
