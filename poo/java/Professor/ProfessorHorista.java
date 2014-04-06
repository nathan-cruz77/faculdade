/*
 *  Programa escrito com propósito didático apenas.
 *  @author Nathan Cruz <nathan.cruz@unifesp.br>
 *  @created 06/04/14
 *  R.A.: 86492
 */

public class ProfessorHorista extends Professor{

    /* Construtor */
    public ProfessorHorista(String nome, int idade,
                            int matricula, double valor, int horas){
        super(nome, idade, matricula);
        this.valor = valor;
        this.horas = horas;
    }

    /* Getters
    public int getHoras(){
        return this.horas;
    }
    public double getValor(){
        return this.valor;
    }*/

    /* Getter para salario */
    public double getSalario(){
        return this.horas * this.valor;
    }

    /* Setters
    public void setHoras(int horas){
        this.horas = horas;
    }
    public void setValor(double valor){
        this.valor = valor;
    }*/
    
    @Override
    /* Imprime os atributos */
    public void Imprime(){
        super.Imprime();
        System.out.println("\tHoras Trabalhadas:\t" + this.horas +
                           "\n\tValor da Hora:\t" + this.valor +
                           "\n\tSalário:\t" + this.getSalario());
    }

}
