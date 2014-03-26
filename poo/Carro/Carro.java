/*
 *  Programa escrito com propósito didático apenas.
 *  @author Nathan Cruz <nathan.cruz@unifesp.br>
 *  @created 25/03/14
 *  R.A.: 86492
 */

public class Carro{
    /* Atributos */
    private int acelerou;
    private int freou;

    /* Construtor */
    public Carro(){
        this.acelerou = 0;
        this.freou = 0;
    }

    /* Getters */
    public int getAcelerou(){
        return this.acelerou;
    }
    public int getFreou(){
        return this.freou;
    }

    /* Setters */
    public void setAcelerou(int acelerou){
        this.acelerou = acelerou;
    }
    public void setFreou(int freou){
        this.freou = freou;
    }

    /* Metodo para acelerar o carro */
    public void acelerar(int a){
        this.setAcelerou(this.getAcelerou()+1);
        System.out.println("\tAcelerando o carro para velocidade " + a);
    }

    /* Metodo para frear o carro */
    public void frear(){
        this.setFreou(this.getFreou()+1);
        System.out.println("\tFreando o carro");
    }

    /* Metodo que exibe a quantidade de freadas */
    public void vezesFreou(){
        System.out.println("\tFreou " + this.getFreou() + " vezes");
    }

    /* Metodo que exibe a quantidade de aceleradas */
    public void vezesAcelerou(){
        System.out.println("\tAcelerou " + this.getAcelerou() + " vezes");
    }
}
