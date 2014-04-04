/*
 *  Programa escrito com propósito didático apenas.
 *  @author Nathan Cruz <nathan.cruz@unifesp.br>
 *  @created 28/03/14
 *  R.A.: 86492
 */

import java.lang.*;
import javax.swing.*;

public class Triangulo{

    /* Atributos */
    private float lado1;
    private float lado2;
    private float lado3;

    /* Construtor */
    public Triangulo(float lado1, float lado2, float lado3){
        this.lado1 = lado1;
        this.lado2 = lado2;
        this.lado3 = lado3;
    }

    /* Verifica se eh equilatero */
    private boolean isEquilatero(){
        if(this.lado1 == this.lado2 && this.lado1 == this.lado3)
            return true;
        return false;
    }

    /* Verifica se eh isoceles */
    private boolean isIsoceles(){
        if(this.lado1 == this.lado2 ||
           this.lado1 == this.lado3 ||
           this.lado2 == this.lado3)
            return true;
        return false;
    }

    /* Verifica o tipo do triangulo */
    public void Tipo(){
        if(this.isEquilatero()){
            JOptionPane.showMessageDialog(null, "Triangulo equilatero");
        }
        else if(this.isIsoceles()){
            JOptionPane.showMessageDialog(null, "Triangulo isoceles");
        }
        else{
            JOptionPane.showMessageDialog(null, "Triangulo escaleno");
        }
    }

    /* Calcula o perimetro */
    public float Perimetro(){
        return (this.lado1 + this.lado2 + this.lado3);
    }

    /* Calcula a area */
    public double Area(){
        double p = this.Perimetro()/2.0;
        return Math.sqrt((double) p*(p-this.lado1)*(p-this.lado2)*(p-this.lado3));
    }
}
