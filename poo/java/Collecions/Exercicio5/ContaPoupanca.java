/*
 *  Programa escrito com propósito didático apenas.
 *  @author Nathan Cruz <nathan.cruz@unifesp.br>
 *  @created 04/04/14
 *  R.A.: 86492
 */

import java.lang.Comparable;

public class ContaPoupanca extends Conta implements Comparable<ContaPoupanca>{

    /* Atributos */
    private String nomeDoCliente;

    /* Construtor */
    public ContaPoupanca(int numero, String nomeDoCliente){
        this.numero = numero;
        this.nomeDoCliente = nomeDoCliente;
    }

    /* Getters */
    public String getNomeDoCliente(){
        return this.nomeDoCliente;
    }

    /* Implementacao da interface */
    public int compareTo(ContaPoupanca aux){
        return this.getNomeDoCliente().compareTo(aux.getNomeDoCliente());
    }

    @Override
    public void atualiza(double taxa){
        this.saldo += 3*(this.saldo * taxa);
    }

    @Override
    public void imprime(){
        System.out.println("Conta " + this.numero + ": " +
                           "titular = " + this.getNomeDoCliente() +
                           " saldo = " + this.saldo );
    }
}
