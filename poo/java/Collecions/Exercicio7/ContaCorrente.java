/*
 *  Programa escrito com propósito didático apenas.
 *  @author Nathan Cruz <nathan.cruz@unifesp.br>
 *  @created 04/04/14
 *  R.A.: 86492
 */

public class ContaCorrente extends Conta implements Tributavel{

    /* Construtor */
    public ContaCorrente(int numero, String nome){
        this.numero = numero;
        this.nome = nome;
    }

    @Override
    public void atualiza(double taxa){
        this.saldo += 2*(this.saldo * taxa);
    }

    @Override
    public void credita(double quantia) {
        if (quantia > 0){
            this.saldo += quantia;
            this.saldo -= 0.10;
        }
        else{
            System.err.println("Não se pode depositar uma quantia negativa");
        }
    }

    /* Implementacao da interface */
    public double calculaTributos(){
        if(this.saldo > 0)
            return (this.saldo/100);
        System.out.println("Valor do saldo invalido");
        return 0;
    }
}
