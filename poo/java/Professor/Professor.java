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
    protected int horas;
    protected double valor;

    /* Construtor */
    public Professor(String nome, int idade, int matricula){
        this.nome = nome;
        this.idade = idade;
        this.matricula = matricula;
    }

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
    public int getHoras(){
        return this.horas;
    }
    public double getValor(){
        return this.valor;
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
    public void setHoras(int horas){
        this.horas = horas;
    }
    public void setValor(double valor){
        this.valor = valor;
    }

    /* Imprime os atributos */
    public void Imprime(){
        System.out.println("\tNome:\t" + this.nome +
                           "\n\tIdade:\t" + this.idade +
                           "\n\tMatricula:\t" + this.matricula);
    }
}
