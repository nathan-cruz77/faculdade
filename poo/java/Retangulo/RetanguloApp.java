/*
 *  Programa escrito com propósito didático apenas.
 *  @author Nathan Cruz <nathan.cruz@unifesp.br>
 *  @created 24/03/14
 *  R.A.: 86492
 */

public class RetanguloApp{
    public static void main(String args[]){
        Retangulo r1 = new Retangulo();
        Retangulo r2 = new Retangulo(3, 6);
        

        System.out.println("Dados do objeto r1:");
        r1.Mostra();
        System.out.println("\nDados do objeto r2:");
        r2.Mostra();

        r1.setBase(2);
        r1.setAltura(4);
        r2.setBase(1);
        r2.setAltura(2);

        System.out.println("\nDados do objeto r1:");
        r1.Mostra();
        System.out.println("\nDados do objeto r2:");
        r2.Mostra();
    }
}
