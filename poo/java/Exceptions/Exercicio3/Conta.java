/*
 *  Programa escrito com propósito didático apenas.
 *  @author Nathan Cruz <nathan.cruz@unifesp.br>
 *  @created 04/04/14
 *  R.A.: 86492
 */

public abstract class Conta {

    /* Atributos */
    protected double saldo;
    protected int numero;

    public void credita(double quantia) throws ValorInvalidoException{
        if (quantia > 0){
            this.saldo += quantia;
        }
        else{
            throw new ValorInvalidoException("Não se pode depositar uma quantia negativa");
        }
    }

    public void debita(double quantia) throws ValorInvalidoException{
        if (quantia>0){
            this.saldo -= quantia;
        }
        else{
            throw new ValorInvalidoException("Não se pode sacar uma quantia negativa");
        }
    }

    /* Getters */
    public double getSaldo(){
        return saldo;
    }
    public double getNumero(){
        return numero;
    }

    public void imprime(){
        System.out.println("Conta " + numero + ": " +
                           "saldo = " + saldo );
    }
}
