/*
 *  Programa escrito com propósito didático apenas.
 *  @author Nathan Cruz <nathan.cruz@unifesp.br>
 *  @created 26/03/14
 *  R.A.: 86492
 */

public class CarroApp{
    public static void main(String args[]){
        Carro c1 = new Carro();
        Carro c2 = new Carro();
        
        System.out.println("Objeto c1: ");
        c1.acelerar(10);
        c1.frear();
        c1.vezesFreou();
        c1.vezesAcelerou();

        System.out.println("Objeto c2: ");
        c2.acelerar(15);
        c2.frear();
        c2.vezesFreou();
        c2.vezesAcelerou();
    }
}
