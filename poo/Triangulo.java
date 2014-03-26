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
        return base;
    }
    public int getAltura(){
        return altura;
    }

    /* Setters */
    public void setBase(int base){
        this.base = base;
    }
    public void setAltura(int altura){
        this.altura = altura;
    }


    /* Funções requisitadas */
    public float area(){
        return (this.base * this.altura)/2;
    }
    public void mostra(){
        System.out.println("Base: " + this.base);
        System.out.println("Altura: " + this.altura);
    }

}
