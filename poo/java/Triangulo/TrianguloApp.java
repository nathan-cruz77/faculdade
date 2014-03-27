/*
 *  Programa escrito com propósito didático apenas.
 *  @author Nathan Cruz <nathan.cruz@unifesp.br>
 *  @created 25/03/14
 *  R.A.: 86492
 */

public class TrianguloApp{
    public static void main(String args[]){
        Triangulo t1 = new Triangulo();
        Triangulo t2 = new Triangulo(3, 6);
        

        System.out.println("Dados do objeto t1:");
        t1.Mostra();
        System.out.println("\nDados do objeto t2:");
        t2.Mostra();

        t1.setBase(2);
        t1.setAltura(4);
        t2.setBase(1);
        t2.setAltura(2);

        System.out.println("\nDados do objeto t1:");
        t1.Mostra();
        System.out.println("\nDados do objeto t2:");
        t2.Mostra();


    }
}
