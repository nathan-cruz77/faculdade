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
		String mensagem;

		/* Verifica se a quantia a ser sacada esta disponivel */
		if (quantia <= this.saldo && quantia > 0){
            this.saldo -= quantia;
        }
        else{
			if(quantia < 0){
				mensagem = "Não se pode realizar um saque com valor negativo";
			}
			else{
				mensagem = "Não se pode realizar um saque com valor maior que o disponivel";
			}
            throw new ValorInvalidoException(mensagem);
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
