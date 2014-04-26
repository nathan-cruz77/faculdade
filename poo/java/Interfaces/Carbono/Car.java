/*
 *  Programa escrito com propósito didático apenas.
 *  @author Nathan Cruz <nathan.cruz@unifesp.br>
 *  @created 04/04/14
 *  R.A.: 86492
 */

public class Car{

	/* Atributos */
	private String modelo;
	private String combustivel;
	private float cilindrada;
	private int passageiros;

	/* Construtores */
	public Car(String modelo, String combustivel,
				float cilindrada, int passageiros){
		this.modelo = modelo;
		this.combustivel = combustivel;
		this.cilindrada = cilindrada;
		this.passageiros = passageiros;
	}
	public Car(){
		this.modelo = "Corsa";
		this.combustivel = "Alcool";
		this.cilindrada = 1000;
		this.passageiros = 4;
	}


}
