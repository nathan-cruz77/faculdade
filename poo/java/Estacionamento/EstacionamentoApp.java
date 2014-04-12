/*
 *  Programa escrito com propósito didático apenas.
 *  @author Nathan Cruz <nathan.cruz@unifesp.br>
 *  @created 11/04/14
 *  R.A.: 86492
 */

public class EstacionamentoApp{
    public static void main(String args[]){
        
        Veiculo[] vagas = new Veiculo[7];
        String[] modelos = {"Fusca", "Brasilia", "Passati", "Uno", "Kombi", "Corsa", "Celta"};
        String[] cores = {"Azul", "Amarelo", "Preto", "Prateado", "Rosa", "Vermelho", "Branco"};
        String[] placas = {"AAA-1234", "BBB-1234", "CCC-1234", "DDD-1234", "EEE-1234", "FFF-1234", "GGG-1234"};
        int i;

        /* Popula o vetor de veiculos */
        for(i=0;i<7;i++){
            if(i%2==0) vagas[i] = new Horista(placas[i], cores[i], modelos[i], 10.0, i);
            else vagas[i] = new Mensalista(placas[i], cores[i], modelos[i], 60.0);
        }

        /* Lista os dados dos objetos */
        for(i=0;i<7;i++){
            System.out.println("Dados do veiculo: ");
            System.out.println("\tModelo: " + vagas[i].getModelo());
            System.out.println("\tCor: " + vagas[i].getCor());
            System.out.println("\tPlaca: " + vagas[i].getPlaca());
            System.out.println("\tTotal a pagar: " + vagas[i].PrecoPagar());
        }
        
        /* Incrementa os precos dos veiculos mensalistas */
        for(i=0;i<7;i++){
            if(vagas[i] instanceof Mensalista) vagas[i].setValorMensal(vagas[i].getValorMensal()*1.10);
        }

        System.out.println("\n### PRECOS INCREMENTADOS ###");

        /* Lista os dados dos objetos */
        for(i=0;i<7;i++){
            System.out.println("Dados do veiculo: ");
            System.out.println("\tModelo: " + vagas[i].getModelo());
            System.out.println("\tCor: " + vagas[i].getCor());
            System.out.println("\tPlaca: " + vagas[i].getPlaca());
            System.out.println("\tTotal a pagar: " + vagas[i].PrecoPagar());
        }


    }
}   
