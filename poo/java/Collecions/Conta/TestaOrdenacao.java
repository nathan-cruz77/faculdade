/*
 *  Programa escrito com propósito didático apenas.
 *  @author Nathan Cruz <nathan.cruz@unifesp.br>
 *  @created 04/04/14
 *  R.A.: 86492
 */

import java.util.*;

public class TestaOrdenacao{
    public static void main(String args[]){
        ArrayList<ContaPoupanca> lista = new ArrayList();
        ContaPoupanca aux;
        int i;

        /* Inicializa a lista */
        for(i=0; i<20; i++){
            lista.add(new ContaPoupanca(i));
        }

        /* Coloca saldo nas contas da lista */
        for(i=0; i<20; i++){
            aux = lista.get(i);
            if(i%2 == 0) aux.credita(i*2);
            else aux.credita(i*3);
        }

        /* Imprime as contas desordenadas */
        for(i=0; i<20; i++){
            aux = lista.get(i);
            aux.imprime();
        }

        System.out.println("\n********************************************************\n");

        /* Ordena as contas de acordo com o saldo */
        Collections.sort(lista);

        /* Imprime as contas ordenadas */
        for(i=0; i<20; i++){
            aux = lista.get(i);
            aux.imprime();
        }
    }
}
