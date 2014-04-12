/*
 *  Programa escrito com propósito didático apenas.
 *  @author Nathan Cruz <nathan.cruz@unifesp.br>
 *  @created 11/04/14
 *  R.A.: 86492
 */

public abstract class Veiculo{

    /* Atributos */
    private String placa;
    private String cor;
    private String modelo;

    /* Getters */
    public String getPlaca(){
        return this.placa;
    }
    public String getCor(){
        return this.cor;
    }
    public String getModelo(){
        return this.modelo;
    }

    /* Setters */
    public void setPlaca(String placa){
        this.placa = placa;
    }
    public void setCor(String cor){
        this.cor = cor;
    }
    public void setModelo(String modelo){
        this.modelo = modelo;
    }

    /* Obriga as classes derivadas a implementarem */
    public abstract double PrecoPagar();
}
