/*
 *  Programa escrito com propósito didático apenas.
 *  @author Nathan Cruz <nathan.cruz@unifesp.br>
 *  @created 25/03/14
 *  R.A.: 86492
 */

public class ContadorApp{
    public static void main(String args[]){
        Contador c1 = new Contador();
        int contador;

        c1.Mostra();
        c1.Incrementa();
        c1.Mostra();
        c1.Incrementa(10);
        c1.Mostra();
        c1.Decrementa(10);
        c1.Mostra();
        c1.Decrementa();
        c1.Mostra();
        contador = c1.getCounter();
        System.out.println("Contador = " + contador);
    }
}
