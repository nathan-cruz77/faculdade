/*
 *  Programa escrito com propósito didático apenas.
 *  @author Nathan Cruz <nathan.cruz@unifesp.br>
 *  @created 25/03/14
 *  R.A.: 86492
 */

public class Quadrado{

    /* Atributos */
    private float lado;

    /* Construtores */
    public Quadrado(){
        this.lado = 10;
    }
    public Quadrado(float lado){
        this.lado = lado;
    }

    /* Setters */
    public void setLado(float lado){
        this.lado = lado;
    }

    /* Getters */
    public float getLado(){
        return this.lado;
    }

    /* Calcula a area */
    public float Area(){
        return (this.lado)*(this.lado);
    }

    /* Aumenta o tamanho do quadrado */
    public void Aumenta(float val){
        this.setLado(this.getLado()+val);
    }
}
