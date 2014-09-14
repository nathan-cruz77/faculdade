/*
 *  Programa escrito com propósito didático apenas.
 *  @author Nathan Cruz <nathan.cruz@unifesp.br>
 *  @created 25/03/14
 *  R.A.: 86492
 *
 *  Professor: Todos os anos estao sendo impressos como 0.
 *  Nao sei o motivo. Se souber, por favor, me fale.
 */

public class DemoDataComFabrica{
    public static void main(String args[]){
        DataComFabrica Natal2De1966, Natal2De1970, Natal2De2000;
        DataComFabrica SeteDe1966, SeteDe1970, SeteDe2000;
        DataComFabrica PrimeiroDe1966, PrimeiroDe1970, PrimeiroDe2000;

        Natal2De1966 = DataComFabrica.Natal2((short) 1966);
        Natal2De1970 = DataComFabrica.Natal2((short) 1970);
        Natal2De2000 = DataComFabrica.Natal2((short) 2000);

        SeteDe1966 = DataComFabrica.seteDeSetembro((short) 1966);
        SeteDe1970 = DataComFabrica.seteDeSetembro((short) 1970);
        SeteDe2000 = DataComFabrica.seteDeSetembro((short) 2000);

        PrimeiroDe1966 = DataComFabrica.primeiroDoMes((byte) 3, (short) 1966);
        PrimeiroDe1970 = DataComFabrica.primeiroDoMes((byte) 5, (short) 1970);
        PrimeiroDe2000 = DataComFabrica.primeiroDoMes((byte) 7, (short) 2000);

        System.out.println(Natal2De1966);
        System.out.println(Natal2De1970);
        System.out.println(Natal2De2000);

        System.out.println(SeteDe1966);
        System.out.println(SeteDe1970);
        System.out.println(SeteDe2000);

        System.out.println(PrimeiroDe1966);
        System.out.println(PrimeiroDe1970);
        System.out.println(PrimeiroDe2000);
    }
}
