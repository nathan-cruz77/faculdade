/*
 *  Programa escrito com propósito didático apenas.
 *  @author Nathan Cruz <nathan.cruz@unifesp.br>
 *  @created 02/06/14
 *  R.A.: 86492
 */

public class VeiculoAVendaApp{
    public static void main(String args[]){
        VeiculoAVenda obj1, obj2, obj3;

		/* Cria um veiculo de cada tipo */
		obj1 = new VeiculoAVenda(Tipo.CAMINHAO, 1996, 200000.56);
		obj2 = new VeiculoAVenda(Tipo.MOTOCICLETA, 2007, 3285.99);
		obj3 = new VeiculoAVenda(Tipo.AUTOMOVEL, 2010, 12365.00);

		/* Imprime a representacao dos objetos */
		System.out.println(obj1 + "\n");
		System.out.println(obj2 + "\n");
		System.out.println(obj3 + "\n");
    }
}
