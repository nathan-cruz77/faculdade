/*
 *  Programa escrito com propósito didático apenas.
 *  @author Nathan Cruz <nathan.cruz@unifesp.br>
 *  @created 25/03/14
 *  R.A.: 86492
 */

import java.lang.*;

public class QuadradoApp{
    public static void main(String args[]){
        Quadrado[] obj = new Quadrado[10];
        int i;
        float soma = 0;

        for(i=0;i<10;i++){
            obj[i] = new Quadrado((float) Math.random()*10);
            soma += obj[i].Area();
        }
        System.out.println("A soma eh: " + soma);        
    }
}
