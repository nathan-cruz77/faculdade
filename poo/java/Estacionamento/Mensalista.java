/*
 *  Programa escrito com propósito didático apenas.
 *  @author Nathan Cruz <nathan.cruz@unifesp.br>
 *  @created 11/04/14
 *  R.A.: 86492
 */

public class Mensalista extends Veiculo{

    /* Atributos */
    private double valorMensal;

    /* Construtor */
    public Mensalista(String placa, String cor, String modelo,
                      double valorMensal){
        super.setPlaca(placa);
        super.setCor(cor);
        super.setModelo(modelo);
        this.setValorMensal(valorMensal);
    }

    /* Getters */
    public double getValorMensal(){
        return this.valorMensal;
    }

    /* Setters */
    public void setValorMensal(double valorMensal){
        this.valorMensal = valorMensal;
    }

    /* Declarado na super-classe */
    public double PrecoPagar(){
        return this.getValorMensal();
    }

    /* Incrementa o total a pagar em 10% */
    public void AumentaPreco(){
        this.setValorMensal(this.getValorMensal() * 1.10);
    }
}
