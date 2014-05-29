/*
 *  Programa escrito com propósito didático apenas.
 *  @author Nathan Cruz <nathan.cruz@unifesp.br>
 *  @created 04/04/14
 *  R.A.: 86492
 */

import java.text.*;

public abstract class Conta {

    /* Atributos */
    protected double saldo;
    protected int numero;
    protected String nome;

    public void credita(double quantia) {
        if (quantia > 0){
            this.saldo += quantia;
        }
        else{
            System.err.println("Não se pode depositar uma quantia negativa");
        }
    }

    public void debita(double quantia) {
        if (quantia>0){
            this.saldo -= quantia;
        }
        else{
            System.err.println("Não se pode sacar uma quantia negativa");
        }
    }

    public abstract void atualiza(double taxa);

    /* Getters */
    public double getSaldo(){
        return this.saldo;
    }
    public double getNumero(){
        return this.numero;
    }
    public String getNome(){
        return this.nome;
    }

    public void imprime(){
        DecimalFormat casas = new DecimalFormat("#.00");
        System.out.println("Conta " + numero + ":\n" +
                           "\tTitular: " + nome +
                           "\n\tSaldo: R$" + casas.format(saldo) );
    }

    public String toString(){
        return " - Numero da Conta: "  + this.numero +
               "\n - Nome do Cliente: " + this.nome +
               "\n - Saldo: R$" + this.saldo;
    }
}
