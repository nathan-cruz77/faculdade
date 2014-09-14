/*
 *  Programa escrito com propósito didático apenas.
 *  @author Nathan Cruz <nathan.cruz@unifesp.br>
 *  @created 28/03/14
 *  R.A.: 86492
 */

import java.util.*;
import java.io.*;
import java.lang.*;

public class Exercicio3{
    public static void main(String args[]){
        BufferedReader arq;
        String arquivo = "teste.txt";
        Map<String, Integer> mapa = new HashMap<String, Integer>();

        try{
            arq = new BufferedReader(new FileReader(arquivo));
            while( (arquivo = arq.readLine()) != null){
                mapa.put(Arrays.asList(arquivo.split(" ")).get(0), Integer.valueOf(Arrays.asList(arquivo.split(" ")).get(1)));
            }
            arq.close();

        }
        catch(IOException e){
            System.out.println(e);
        }

        /* Imprime o hash */
        for(String s: mapa.keySet()){
            System.out.println(s + " "  + mapa.get(s));
        }
    }
}
