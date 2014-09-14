/*
 *  Programa escrito com propósito didático apenas.
 *  @author Nathan Cruz <nathan.cruz@unifesp.br>
 *  @created 04/04/14
 *  R.A.: 86492
 */

import java.text.*;
import java.util.*;
import java.io.*;

public class Banco{

    /* Atributos */
    private double dinheiro;
    private Map<String, Conta> contas;
    private double tributos;

    /* Construtor */
    public Banco(){
        this.dinheiro = 0.0;
        this.contas = new HashMap<String, Conta>();
        this.tributos = 0.0;
    }

    /* Busca conta dado o nome do cliente */
    public Conta buscaPorNome(String nome){
        return this.contas.get(nome);
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
        this.contas.put(conta.getNome(), conta);
    }

    /* Imprime o total do banco */
    public void Imprime(){
        DecimalFormat casas = new DecimalFormat("#.00");
        System.out.println("Saldo do banco: " + casas.format(this.dinheiro));
        System.out.println("Tributos do banco: " + casas.format(this.tributos));
    }

    /* Salva contas num arquivo */
    public void Salva(PrintWriter pw){
        for(Conta conta: this.contas.values()){
            pw.println(conta.toString() + "\n");
        }
    }

    public static void main(String args[]){
        Banco banco = new Banco();
        ContaCorrente[] cc = new ContaCorrente[2];
        ContaPoupanca[] cp = new ContaPoupanca[2];
        CDB[] cdb = new CDB[2];
        int i, j;
        PrintWriter pw;
        String[] nomes = {"Nathan", "Mariane", "Eduardo", "Alexandre", "Felipe", "Matheus"};

        /* Inicializa as contas */
        cc[0] = new ContaCorrente(0, nomes[0]);
        cc[1] = new ContaCorrente(1, nomes[1]);

        cp[0] = new ContaPoupanca(2, nomes[2]);
        cp[1] = new ContaPoupanca(3, nomes[3]);

        cdb[0] = new CDB(2, nomes[4]);
        cdb[1] = new CDB(3, nomes[5]);

        /* Faz alteracoes nas contas */
        for(i=0; i<2; i++){
            cc[i].credita(12);
            cc[i].debita(3);

            cp[i].credita(12);
            cp[i].debita(3);

            cdb[i].credita(12);
            cdb[i].debita(3);
        }

        /* Registra todas as contas no banco */
        for(i=0; i<2; i++){
            banco.Registra(cc[i]);
            banco.Registra(cp[i]);
            banco.Registra(cdb[i]);
        }

        /* Testa se funciona o mapa */
        for(i=0; i<6; i++){
            banco.buscaPorNome(nomes[i]).imprime();
        }

        /* Imprime contas para arquivo */
        try{
            pw = new PrintWriter(new FileWriter("Teste.txt"));
            banco.Salva(pw);
            pw.close();
        }
        catch(IOException e){
            System.out.println(e.getMessage());
        }

    }
}
