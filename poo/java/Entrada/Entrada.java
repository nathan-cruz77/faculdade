/*
 *  Programa escrito com propósito didático apenas.
 *  @author Nathan Cruz <nathan.cruz@unifesp.br>
 *  @created 28/03/14
 *  R.A.: 86492
 */

import java.util.*;

public class Entrada{
    public static void main(String args[]){
        Scanner entrada = new Scanner(System.in);
        String s;
        Triangulo tri;
        Retangulo ret;
        float n1, n2, n3;

        System.out.println("O que deseja criar?[R/T]");
        s = entrada.next();
        if(s.toUpperCase() == "R"){
            System.out.println("Entre com a base: ");
            n1 = (float) entrada.nextDouble();
            System.out.println("Entre com a altura: ");
            n2 = (float) entrada.nextDouble();

            ret = new Retangulo(n1, n2);
            System.out.println("Area: " + ret.Area());
            System.out.println("Perimetro: " + ret.Perimetro());
        }
        else if(s.toUpperCase() == "T"){
            System.out.println("Entre com o primeiro lado: ");
            n1 = (float) entrada.nextDouble();
            System.out.println("Entre com o segundo lado: ");
            n2 = (float) entrada.nextDouble();
            System.out.println("Entre com o terceciro lado: ");
            n3 = (float) entrada.nextDouble();

            tri = new Triangulo(n1, n2, n3);
            System.out.println("Area: " + tri.Area());
            System.out.println("Perimetro: " + tri.Perimetro());
            tri.tipo();
        }
        else{
        }
    }
}
