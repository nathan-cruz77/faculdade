/*
 *  Programa escrito com propósito didático apenas.
 *  @author Nathan Cruz <nathan.cruz@unifesp.br>
 *  @created 06/04/14
 *  R.A.: 86492
 */

public class ProfessorApp{
    public static void main(String args[]){
        Professor[] professores = new Professor[10];
        String[] nomes = { "Alberto", "José", "Nathan", "Mariane", "Fulano", "Fulana", "Thais", "Regina", "Luiz", "Silvia" };
        int i, aux2;
        
        /* Instancia os professores */
        for(i=0;i<10;i++){
            if(i%2==0){
                professores[i] = new ProfessorHorista(nomes[i], i+20,
                                                     (i+1)*(10+i),
                                                     (i+1)*(20.36+i),
                                                     (i+1)*5);
            }
            else{
                professores[i] = new ProfessorIntegral(nomes[i], i+20,
                                                       i*(10+i), (i+1)*1000);
            }
        }
        /* Exibe o estado de todos os objetos */
        for(i=0;i<10;i++){
            aux2 = i+1;
            System.out.println("Objeto: " + aux2);
            professores[i].Imprime();
        }

        /* Aumenta algumas horas para todos os professores */
        for(i=0;i<10;i++){
            Professor aux = professores[i];
            if(i%2==0) aux.setHoras(aux.getHoras()+i);
        }
        
        System.out.println("\n### HORAS TRABALHADAS ADICIONADAS ###\n");
            
        /* Exibe o estado de todos os objetos */        
        for(i=0;i<10;i++){
            aux2 = i+1;
            System.out.println("Objeto: " + aux2);
            professores[i].Imprime();
        }

    }
}
