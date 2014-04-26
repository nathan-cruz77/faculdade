/*
 *  Programa escrito com propósito didático apenas.
 *  @author Nathan Cruz <nathan.cruz@unifesp.br>
 *  @created 04/04/14
 *  R.A.: 86492
 */

public class Building{

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
}
