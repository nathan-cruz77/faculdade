/*
 *  Programa escrito com propósito didático apenas.
 *  @author Nathan Cruz <nathan.cruz@unifesp.br>
 *  @created 04/04/14
 *  R.A.: 86492
 */

import java.text.*;
import java.util.*;
import java.io.*;
import java.lang.*;

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

    /* Recupera contas do arquivo */
    public void Recupera(BufferedReader br) throws IOException{
        String input, nome, tipo;
        int numero;
        float saldo;

        input = br.readLine();
        while(input != null){

            numero = Integer.valueOf(Arrays.asList(input.split(":")).get(1).trim());
            input = br.readLine();

            nome = Arrays.asList(input.split(":")).get(1).trim();
            input = br.readLine();

            saldo = Float.valueOf(Arrays.asList(input.split("\\$")).get(1).trim());
            input = br.readLine();

            tipo = Arrays.asList(input.split(":")).get(1).trim();
            input = br.readLine();
            input = br.readLine();

            if(tipo.equals("Conta Corrente")){
                this.contas.put(nome, new ContaCorrente(numero, nome));
                this.contas.get(nome).credita(saldo + 0.1);
            }
            else if(tipo.equals("Poupanca")){
                this.contas.put(nome, new ContaPoupanca(numero, nome));
                this.contas.get(nome).credita(saldo);
            }
            else if(tipo.equals("CDB")){
                this.contas.put(nome, new CDB(numero, nome));
                this.contas.get(nome).credita(saldo);
            }
        }
    }

    public static void main(String args[]){
        Banco banco = new Banco();
        BufferedReader br;

        /* Tenta recuperar dados a inserir no mapa */
        try{
            br = new BufferedReader(new FileReader("Teste.txt"));
            banco.Recupera(br);
            br.close();
        }
        catch(IOException e){
            System.out.println(e.getMessage());
        }

        /* Imprime o mapa */
        for(String a: banco.contas.keySet()){
            System.out.println(banco.contas.get(a));
            System.out.println();
        }
    }
}
