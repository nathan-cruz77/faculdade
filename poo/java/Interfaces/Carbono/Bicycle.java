/*
 *  Programa escrito com propósito didático apenas.
 *  @author Nathan Cruz <nathan.cruz@unifesp.br>
 *  @created 04/04/14
 *  R.A.: 86492
 */

public class Bicycle implements CarbonFootprint{

    /* Atributos */
    private String modelo;
    private String acessorios;

    /* Construtor */
    public Bicycle(String modelo, String acessorios){
        this.modelo = modelo;
        this.acessorios = acessorios;
    }
    public Bicycle(){
        this.modelo = "Esportiva";
        this.acessorios = "Buzina, adesivos, enfeites de roda";
    }

    /* Implementacao da interface */
    public double getCarbonFootprint(){
        return 0;
    }

    public String toString(){
        return "\nTipo: Bicycle\nModelo: " + this.modelo + "\nAcessórios: " +
                this.acessorios + "\nPegada de Carbono: " +
                this.getCarbonFootprint();
    }
}
