/*
 *  Programa escrito com propósito didático apenas.
 *  @author Nathan Cruz <nathan.cruz@unifesp.br>
 *  @created 02/06/14
 *  R.A.: 86492
 */

public class VeiculoAVenda{

    /* Atributos */
    private Tipo tipo;
    private int ano;
    private double precoDeVenda;

    /* Construtor */
    public VeiculoAVenda(Tipo tipo, int ano, double precoDeVenda){
        this.tipo = tipo;
        this.ano = ano;
        this.precoDeVenda = precoDeVenda;
    }

    /* Representacao textual do objeto */
    public String toString(){
        return "Tipo do veiculo: " + this.tipo +
               "\nAno do veiculo: " + this.ano +
               "\nPreco do veiculo: R$" + this.precoDeVenda;
    }
}
