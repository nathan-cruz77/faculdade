import java.io.*;
import java.net.*;

public class Servidor{
	public static void main(String[] args) throws Exception{
		String palavra_cliente, palavra_modificada;

		ServerSocket welcomeSocket = new ServerSocket(8080);

		while(true){
			Socket conexao = welcomeSocket.accept();

			BufferedReader do_cliente =
				new BufferedReader(new InputStreamReader(conexao.getInputStream()));

			DataOutputStream para_cliente = new DataOutputStream(conexao.getOutputStream());

			palavra_cliente = do_cliente.readLine();
			palavra_modificada = palavra_cliente.toUpperCase() + '\n';

			para_cliente.writeBytes(palavra_modificada);
		}
	}
}
