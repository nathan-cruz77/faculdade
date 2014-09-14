/*
 *  Programa escrito com propósito didático apenas.
 *  @author Nathan Cruz <nathan.cruz@unifesp.br>
 *  @created 04/04/14
 *  R.A.: 86492
 */

public class CarbonFootprintApp{
    public static void main(String args[]){
        CarbonFootprint objetos[] = new CarbonFootprint[6];
        int i;

        /* Objetos Car */
        objetos[0] = new Car();
        objetos[1] = new Car("Uno", "Gasolina", 1200, 5);

        /* Objetos Building */
        objetos[2] = new Building();
        objetos[3] = new Building(12, true, 36, true);

        /* Objetos Bicycle */
        objetos[4] = new Bicycle();
        objetos[5] = new Bicycle("Velha", "Ferrugem, Pneu furado");

        /* Lista as pegadas de carbono */
        for(i = 0; i < 6; i++){
            if(i == 2 || i == 4) System.out.println("\n");
            System.out.println(objetos[i]);
        }

    }
}
