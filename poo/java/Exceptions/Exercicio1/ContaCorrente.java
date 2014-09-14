/*
 *  Programa escrito com propósito didático apenas.
 *  @author Nathan Cruz <nathan.cruz@unifesp.br>
 *  @created 04/04/14
 *  R.A.: 86492
 */

public class ContaCorrente extends Conta{

    /* Construtor */
    public ContaCorrente(int numero){
        this.numero = numero;
        this.saldo = 0;
    }

    public void atualiza(double taxa){
        this.saldo += 2*(this.saldo * taxa);
    }

    @Override
    public void credita(double quantia) throws IllegalArgumentException{
        if (quantia > 0){
            this.saldo += quantia;
            this.saldo -= 0.10;
        }
        else{
            throw new IllegalArgumentException("Não se pode depositar uma quantia negativa");
        }
    }
}
