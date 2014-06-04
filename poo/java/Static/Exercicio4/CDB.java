/*
 *  Programa escrito com propósito didático apenas.
 *  @author Nathan Cruz <nathan.cruz@unifesp.br>
 *  @created 04/04/14
 *  R.A.: 86492
 */

public class CDB extends Conta implements Tributavel{

    /* Construtor */
    public CDB(int numero, String nome){
        this.numero = numero;
        this.nome = nome;
    }

    @Override
    public void atualiza(double taxa){
        this.saldo += 2.5*(this.saldo * taxa);
    }

    /* Implementacao da interface */
    public double calculaTributos(){
        return 42;
    }

    @Override
    public String toString(){
        return super.toString() +
               "\n - Tipo de Conta: CDB";
    }
}
