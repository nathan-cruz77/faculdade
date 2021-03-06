/*
 *  Programa escrito com propósito didático apenas.
 *  @author Nathan Cruz <nathan.cruz@unifesp.br>
 *  @created 04/04/14
 *  R.A.: 86492
 */

public class ContaPoupanca extends Conta{

    /* Construtor */
    public ContaPoupanca(int i){
        super(i);
    }

    @Override
    public void atualiza(double taxa){
        this.saldo += 3*(this.saldo * taxa);
    }
}
