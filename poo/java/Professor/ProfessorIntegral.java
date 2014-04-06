/*
 *  Programa escrito com propósito didático apenas.
 *  @author Nathan Cruz <nathan.cruz@unifesp.br>
 *  @created 04/04/14
 *  R.A.: 86492
 */

public class ProfessorIntegral extends Professor{
    
    /* Atributos */
    private float salario;

    /* Construtor */
    public ProfessorIntegral(String nome, int idade, 
                             int matricula, float salario){
        super(nome, idade, matricula);
        this.salario = salario;
    }

    /* Getters */
    public float getSalario(){
        return this.salario;
    }

    /* Setters */
    public void setSalario(float salario){
        this.salario = salario;
    }

    @Override
    /* Imprime os atributos */
    public void Imprime(){
        super.Imprime();
        System.out.println("\tSalário:\t" + this.getSalario());
    }

}
