/*
 *  Programa escrito com propósito didático apenas.
 *  @author Nathan Cruz <nathan.cruz@unifesp.br>
 *  @created 11/04/14
 *  R.A.: 86492
 */

public class Horista extends Veiculo{

    /* Atributos */
    private double valorHora;
    private int horasEstacionado;

    /* Construtor */
    public Horista(String placa, String cor, String modelo,
                   double valorHora, int horasEstacionado){
        super.setPlaca(placa);
        super.setCor(cor);
        super.setModelo(modelo);
        this.setValorHora(valorHora);
        this.setHorasEstacionado(horasEstacionado);
    }

    /* Getters */
    public double getValorHora(){
        return this.valorHora;
    }
    public int getHorasEstacionado(){
        return this.horasEstacionado;
    }

    /* Setters */
    public void setValorHora(double valorHora){
        this.valorHora = valorHora;
    }
    public void setHorasEstacionado(int horasEstacionado){
        this.horasEstacionado = horasEstacionado;
    }

    /* Declarado na super-classe */
    public double PrecoPagar(){
        double preco =  this.getValorHora() * this.getHorasEstacionado();
        return preco;
    }
}
