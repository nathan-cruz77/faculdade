/*
 *  Programa escrito com propósito didático apenas.
 *  @author Nathan Cruz <nathan.cruz@unifesp.br>
 *  @created 25/03/14
 *  R.A.: 86492
 */

public class ConversaoDeUnidadesDeAreaApp{
    public static void main(String args[]){
        double campo = 8250;

        System.out.println("Campo de futebol em pes quadrados: " +
                           ConversaoDeUnidadesDeArea.MeterToFeet(campo));

        System.out.println("Campo de futebol em centimetros quadrados: " +
                           ConversaoDeUnidadesDeArea.MeterToCentimeter(campo));

        System.out.println("Campo de futebol em acres: " +
                           ConversaoDeUnidadesDeArea.MeterToAcre(campo));
    }
}
