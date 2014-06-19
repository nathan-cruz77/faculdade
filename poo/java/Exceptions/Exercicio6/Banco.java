/*
 *  Programa escrito com propósito didático apenas.
 *  @author Nathan Cruz <nathan.cruz@unifesp.br>
 *  @created 04/04/14
 *  R.A.: 86492
 */

import java.util.*;

public class Banco{

    /* Atributos */
    private double dinheiro;
    private HashSet<Conta> contas = new HashSet<Conta>();

    /* Construtor */
    public Banco(){
        this.dinheiro = 0.0;
    }

    /* Registra nova conta */
    public void Registra(Conta conta) throws ExcecaoElementoJaExistente{
        if(this.contas.add(conta)){
            this.dinheiro += conta.getSaldo();
        }
        else{
            throw new ExcecaoElementoJaExistente("Conta ja cadastrada");
        }
    }

    /* Imprime o total do banco */
    public void Imprime(){

        /* Atualiza o valor de this.dinheiro antes de imprimir */
        for(Conta conta: this.contas){
            this.dinheiro += conta.getSaldo();
        }
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

        for(i=0;i<5;i++){
            try{
                banco.Registra(cc[2]);
                banco.Registra(cp[i]);
            }
            catch(ExcecaoElementoJaExistente e){
                System.out.println(e.getMessage());
            }
        }

        for(Conta conta: banco.contas){
            try{
                conta.credita(12);
                conta.debita(13);
            }
            catch(ValorInvalidoException e){
                System.out.println(e.getMessage());
            }
        }

        banco.Imprime();

    }
}
