/*
 *  Programa escrito com propósito didático apenas.
 *  @author Nathan Cruz <nathan.cruz@unifesp.br>
 *  @created 02/06/14
 *  R.A.: 86492
 */

public class ConversaoDeUnidadesDeArea{

    /* Square meter to something else (also square) */
    public static double MeterToFeet(double m){
        return m*10.76;
    }
    public static double MeterToCentimeter(double m){
        return m*10000;
    }
    public static double MeterToAcre(double m){
        return m*0.00024711;
    }

    /* Funcoes que o professor pediu para implementar */
    public static double FeetToCentimeter(double f){
        return f*929;
    }
    public static double MileToAcre(double mi){
        return mi*640;
    }
    public static double AcreToFeet(double a){
        return a*43560;
    }
}
