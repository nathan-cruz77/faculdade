/*
 *  Programa escrito com propósito didático apenas.
 *  @author Nathan Cruz <nathan.cruz@unifesp.br>
 *  @created 25/03/14
 *  R.A.: 86492
 */

public class Contador{
    /* Atributos */
    private int counter;

    /* Construtor */
    public Contador(){
        this.counter = 0;
    }
    public Contador(int counter){
        this.counter = counter;
    }

    /* Getters */
    public int getCounter(){
        return this.counter;
    }

    /* Setters */
    public void setCounter(int counter){
        this.counter = counter;
    }

    /* Incrementar o contador */
    public void Incrementa(){
        this.counter += 1;
    }
    public void Incrementa(int counter){
        this.counter += counter;
    }

    /* Decrementar o contador */
    public void Decrementa(){
        this.counter -= 1;
    }
    public void Decrementa(int counter){
        this.counter -= counter;
    }

    public void Mostra(){
        System.out.println("Contador = " + this.getCounter());
    }
}
