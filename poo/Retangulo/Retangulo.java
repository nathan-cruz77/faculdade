/*
 *  Programa escrito com propósito didático apenas.
 *  @author Nathan Cruz <nathan.cruz@unifesp.br>
 *  @created 24/03/14
 *  R.A.: 86492
 */

public class Retangulo{
    /* Atributos */
    private int base;
    private int altura;

    /* Construtores */
    public Retangulo(){
        this.setBase(10);
        this.setAltura(10);
    }
    public Retangulo(int base, int altura){
        this.setBase(base);
        this.setAltura(altura);
    }

    /* Getters */
    public int getBase(){
        return this.base;
    }
    public int getAltura(){
        return this.altura;
    }

    /* Setters */
    public void setBase(int base){
        this.base = base;
    }
    public void setAltura(int altura){
        this.altura = altura;
    }
    
    /* Calcula a area */
    public float Area(){
        return this.getBase() * this.getAltura();
    }

    /* Calcula o perimetro */
    public float Perimetro(){
        return 2*(this.getBase()) + 2*(this.getAltura());
    }
    
    /* Relacao entre os atributos... ta certo isso? */
    public float Relacao(){
        return (float) this.base/this.altura;
    }

    /* Verifica se o retangulo eh quadrado */
    public boolean isQuadrado(){
        if(this.getAltura() == this.getBase()) return true;
        return false;
    }

    /* Imprime os atributos do objeto */
    public void Mostra(){
        System.out.println("\tBase: " + this.getBase());
        System.out.println("\tAltura: " + this.getAltura());
        System.out.println("\tArea: " + this.Area());
        System.out.println("\tPerimetro: " + this.Perimetro());
        System.out.println("\tRelacao: " + this.Relacao());
        if(this.isQuadrado())
            System.out.println("\tEste retangulo eh um quadrado!");
        else
            System.out.println("\tEste retangulo nao eh um quadrado!");
    }
}


