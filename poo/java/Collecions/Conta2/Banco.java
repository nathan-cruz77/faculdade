/*
 *  Programa escrito com propósito didático apenas.
 *  @author Nathan Cruz <nathan.cruz@unifesp.br>
 *  @created 04/04/14
 *  R.A.: 86492
 */

import java.text.*;

public class Banco{

    /* Atributos */
    private double dinheiro;
    private Conta[] contas;
    private double tributos;

    /* Construtor */
    public Banco(){
        this.dinheiro = 0.0;
        this.contas = new Conta[15];
        this.tributos = 0.0;
    }

    /* Registra nova conta */
    public void Registra(Conta conta){
        ContaCorrente aux;
        CDB aux2;

        if(conta instanceof ContaCorrente){
            aux = (ContaCorrente) conta;
            this.tributos += aux.calculaTributos();
        }
        else if(conta instanceof CDB){
            aux2 = (CDB) conta;
            this.tributos += aux2.calculaTributos();
        }
        this.dinheiro += conta.getSaldo();
    }

    /* Imprime o total do banco */
    public void Imprime(){
        DecimalFormat casas = new DecimalFormat("#.00");
        System.out.println("Saldo do banco: " + casas.format(this.dinheiro));
        System.out.println("Tributos do banco: " + casas.format(this.tributos));
    }

    public static void main(String args[]){
        Banco banco = new Banco();
        ContaCorrente[] cc = new ContaCorrente[5];
        ContaPoupanca[] cp = new ContaPoupanca[5];
        CDB[] cdb = new CDB[5];
        int i, j;

        for(i=0;i<5;i++){
            cc[i] = new ContaCorrente(i);
            cp[i] = new ContaPoupanca(i);
            cdb[i] = new CDB(i);
        }

        for(i=0,j=0;i<15;i+=3,j++){
            banco.contas[i] = cc[j];
            banco.contas[i+1] = cp[j];
            banco.contas[i+2] = cdb[j];
        }

        for(i=0;i<15;i++){
            banco.contas[i].credita(12);
            banco.contas[i].debita(3);
            banco.Registra(banco.contas[i]);
        }

        banco.Imprime();

    }
}
