/*
 *  Programa escrito com propósito didático apenas.
 *  @author Nathan Cruz <nathan.cruz@unifesp.br>
 *  @created 04/04/14
 *  R.A.: 86492
 */

public class Building implements CarbonFootprint{

    /* Atributos */
    private int pessoas;
    private boolean renovavel;
    private int lampadas;
    private boolean arCondicionado;

    /* Construtor */
    public Building(int pessoas, boolean renovavel,
                    int lampadas, boolean arCondicionado){
        this.pessoas = pessoas;
        this.renovavel = renovavel;
        this.lampadas = lampadas;
        this.arCondicionado = arCondicionado;
    }
    public Building(){
        this.pessoas = 5;
        this.renovavel = false;
        this.lampadas = 15;
        this.arCondicionado = false;
    }

    /* Implementacao da interface */
    public double getCarbonFootprint(){
        int limpo = 0;
        int ar = 0;

        if(this.renovavel) limpo = 1;
        if(this.arCondicionado) ar = 1;

        return (this.pessoas*0.6 + this.pessoas*ar*0.2 +
                this.lampadas*0.1 - limpo*0.5);
    }

    public String toString(){
        return "\nTipo: Building\nQuantidade de pessoas: " + this.pessoas + "\nEnergia renovavel: " +
                this.renovavel + "\nQuantidade de lampadas: " + this.lampadas + "\nAr condicionado: "+
                this.arCondicionado + "\nPegada de Carbono: " + this.getCarbonFootprint();
    }
}
