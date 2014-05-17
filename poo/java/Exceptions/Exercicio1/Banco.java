/*
 *  Programa escrito com propósito didático apenas.
 *  @author Nathan Cruz <nathan.cruz@unifesp.br>
 *  @created 04/04/14
 *  R.A.: 86492
 */

public class Banco{

    /* Atributos */
    private double dinheiro;
    private Conta[] contas;

    /* Construtor */
    public Banco(){
        this.dinheiro = 0.0;
        this.contas = new Conta[10];
    }

    /* Registra nova conta */
    public void Registra(Conta conta){
            this.dinheiro += conta.getSaldo();
    }

    /* Imprime o total do banco */
    public void Imprime(){
        System.out.println("Saldo do banco: " + this.dinheiro);
    }

    public static void main(String args[]){
        Banco banco = new Banco();
        ContaCorrente[] cc = new ContaCorrente[5];
        ContaPoupanca[] cp = new ContaPoupanca[5];
        int i, j;

        for(i=0;i<5;i++){
            cc[i] = new ContaCorrente(i);
            cp[i] = new ContaPoupanca(i);
        }

        for(i=0,j=0;i<10;i+=2,j++){
            banco.contas[i] = cc[j];
            banco.contas[i+1] = cp[j];
        }

        for(i=0;i<10;i++){
			try{
            	banco.contas[i].credita(-12);
    	        banco.contas[i].debita(3);
	            banco.Registra(banco.contas[i]);
			}
			catch(IllegalArgumentException e){
				System.out.println(e.getMessage());
			}
        }

        banco.Imprime();

    }
}
