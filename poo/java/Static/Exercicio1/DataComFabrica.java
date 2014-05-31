/*
 *  Programa escrito com propósito didático apenas.
 *  @author Nathan Cruz <nathan.cruz@unifesp.br>
 *  @created 25/03/14
 *  R.A.: 86492
 */

public class DataComFabrica{

	/* Atributos */
	private byte dia, mes;
	private int ano;

	public DataComFabrica(byte d, byte m, int a){
		this.dia = d;
		this.mes = m;
		this.ano = ano;
	}

	public String toString(){
		return this.dia + "/" + this.mes + "/" + this.ano;
	}

	/* Fabricas de instancias */
	public static DataComFabrica Natal2(int ano){
		return new DataComFabrica((byte) 25, (byte) 12, ano);
	}

	public static DataComFabrica seteDeSetembro(int ano){
		return new DataComFabrica((byte) 7, (byte) 9, ano);
	}

	public static DataComFabrica primeiroDoMes(byte mes, int ano){
		return new DataComFabrica((byte) 1, mes, ano);
	}
}
