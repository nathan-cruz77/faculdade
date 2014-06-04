/*
 *  Programa escrito com propósito didático apenas.
 *  @author Nathan Cruz <nathan.cruz@unifesp.br>
 *  @created 04/06/14
 *  R.A.: 86492
 */

public class ConversaoDeUnidadesDeVolumeApp{
    public static void main(String args[]){
        double pscina = 1890;

        System.out.println("Em uma pscina olimpica cabe: " +
                           ConversaoDeUnidadesDeVolume.MeterToLiter(pscina) +
                           "L");
        System.out.println("Em uma pscina olimpica cabe: " +
                           ConversaoDeUnidadesDeVolume.MeterToFeet(pscina) +
                           "pes cubicos");
        System.out.println("Em uma pscina olimpica cabe: " +
                           ConversaoDeUnidadesDeVolume.MeterToCentimeter(pscina) +
                           "cm cubicos");
    }
}
