/*
 *  Programa escrito com propósito didático apenas.
 *  @author Nathan Cruz <nathan.cruz@unifesp.br>
 *  @created 28/03/14
 *  R.A.: 86492
 */

import java.util.*;
import javax.swing.*;

public class Entrada{
    public static void main(String args[]){
        String s;
        Triangulo tri;
        Retangulo ret;
        float n1, n2, n3;

        s = JOptionPane.showInputDialog(null, "O que deseja criar?[R/T]");

        if(s.toUpperCase().equals("R")){
            s =JOptionPane.showInputDialog(null,
                                           "Entre com a base: ");
            n1 = Float.valueOf(s.trim()).floatValue();
            s = JOptionPane.showInputDialog(null,
                                            "Entre com a altura: ");
            n2 = Float.valueOf(s.trim()).floatValue();

            ret = new Retangulo(n1, n2);
            System.out.println("Area: " + ret.Area());
            System.out.println("Perimetro: " + ret.Perimetro());
        }
        else if(s.toUpperCase().equals("T")){
            s = JOptionPane.showInputDialog(null,
                                             "Entre com o primeiro lado: ");
            n1 = Float.valueOf(s.trim()).floatValue();

            s = JOptionPane.showInputDialog(null,
                                             "Entre com o segundo lado: ");
            n2 = Float.valueOf(s.trim()).floatValue();

            s = JOptionPane.showInputDialog(null,
                                             "Entre com o segundo lado: ");
            n3 = Float.valueOf(s.trim()).floatValue();

            tri = new Triangulo(n1, n2, n3);
            System.out.println("Area: " + tri.Area());
            System.out.println("Perimetro: " + tri.Perimetro());
            tri.Tipo();
        }
        else{
            JOptionPane.showMessageDialog(null,
                                          "Valor inválido! Favor entrar com R ou T");
        }
    }
}
