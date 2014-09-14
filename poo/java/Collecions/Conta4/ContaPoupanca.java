/*
 *  Programa escrito com propósito didático apenas.
 *  @author Nathan Cruz <nathan.cruz@unifesp.br>
 *  @created 04/04/14
 *  R.A.: 86492
 */

import java.lang.Comparable;

public class ContaPoupanca extends Conta implements Comparable<ContaPoupanca>{

    /* Construtor */
    public ContaPoupanca(int numero){
        this.numero = numero;
    }

    /* Implementacao da interface */
    public int compareTo(ContaPoupanca aux){
        if(this.saldo > aux.saldo) return 1;
        else if(this.saldo < aux.saldo) return -1;
        else return 0;
    }

    @Override
    public void atualiza(double taxa){
        this.saldo += 3*(this.saldo * taxa);
    }
}
