/*
 *  Programa escrito com propósito didático apenas.
 *  @author Nathan Cruz <nathan.cruz@unifesp.br>
 *  @created 04/06/14
 *  R.A.: 86492
 */

public class ConversaoDeUnidadesDeVolume{

	/* Metodos de conversao de unidade */
	public static double LiterToCentimeter(double l){
		return l*1000;
	}
	public static double GalToInch(double g){
		return g*231;
	}
	public static double GalToLiter(double g){
		return g*3.785;
	}

	/* Funcoes que vou utilizar */
	public static double MeterToLiter(double m){
		return m*1000;
	}
	public static double MeterToFeet(double m){
		return m*35.32;
	}
	public static double MeterToCentimeter(double m){
		return m*1000000;
	}
}
