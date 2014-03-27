/*
 *  Programa escrito com propósito didático apenas.
 *  @author Nathan Cruz <nathan.cruz@unifesp.br>
 *  @created 24/03/14
 *  R.A.: 86492
 */

public class Triangulo{
    /* Atributos */
    private int base;
    private int altura;

    /* Construtores */
    public Triangulo(){
        this.base = 10;
        this.altura = 10;
    }
    public Triangulo(int base, int altura){
        this.base = base;
        this.altura = altura;
    }

    /* Getters */
    public int getBase(){
        return this.base;
    }
    public int getAltura(){
        return this.altura;
    }

    /* Setters */
    public void setBase(int base){
        this.base = base;
    }
    public void setAltura(int altura){
        this.altura = altura;
    }

    /* Calcula a area do triangulo */
    public float Area(){
        return (this.getBase()*this.getAltura())/2;
    }
    
    /* Mostra os valores dos atributos do objeto */
    public void Mostra(){
        System.out.println("\tBase: " + this.getBase());
        System.out.println("\tAltura: " + this.getAltura());
        System.out.println("\tArea: " + this.Area());
    }
}
