/*
 *  Programa escrito com propósito didático apenas.
 *  @author Nathan Cruz <nathan.cruz@unifesp.br>
 *  @created 04/04/14
 *  R.A.: 86492
 */

public class Professor{
    
    /* Atributos */
    protected String nome;
    protected int idade;
    protected int matricula;
    protected float salario;

    /* Getters */
    public String getNome(){
        return this.nome;
    }
    public int getIdade(){
        return this.idade;
    }
    public int getMatricula(){
        return this.matricula;
    }
    public float getSalario(){
        return this.salario;
    }

    /* Setters */
    public void setNome(String nome){
        this.nome = nome;
    }
    public void setIdade(int idade){
        this.idade = idade;
    }
    public void setMatricula(int matricula){
        this.matricula = matricula;
    }
    public void setSalario(float salario){
        this.salario = salario;
    }


}
