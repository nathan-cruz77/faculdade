import java.io.*;
import java.net.*;

public class Cliente{
	public static void main(String[] args) throws Exception{
		String palavra1, palavra2;

		BufferedReader do_usuario = new BufferedReader(new InputStreamReader(System.in));
		Socket cliente = new Socket("localhost", 8080);
		DataOutputStream para_servidor = new DataOutputStream(cliente.getOutputStream());
		BufferedReader do_servidor = new BufferedReader(new InputStreamReader(cliente.getInputStream()));

		palavra1 = do_usuario.readLine();
		para_servidor.writeBytes(palavra1 + '\n');

		palavra2 = do_servidor.readLine();
		System.out.println("VINDO DO SERVIDOR: " + palavra2);

		cliente.close();
	}
}
