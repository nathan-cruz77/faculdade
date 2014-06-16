import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.*;

/*
 * <applet code="Exercicio3" height="200" width="200"></applet>
 */

public class Exercicio3 extends JApplet implements ActionListener{

	/* Atributos */
	private JButton b1;
	private JLabel l1, l2;
	private JTextField usuario;
	private int result, tent;


	/* Main da aplicacao */
	public void init(){

		Random aux = new Random();

		/* Inicializa os elementos */
		this.tent = 0;
		this.result = aux.nextInt(10);
		this.b1 = new JButton("Tentar");
		this.usuario = new JTextField(10);
		this.l1 = new JLabel("Entre com um numero: ");
		this.l2 = new JLabel("Tentativas: " + this.tent);

		this.b1.addActionListener(this);

		setLayout(new GridLayout(2, 2));
		add(l1);
		add(usuario);

		add(b1);
		add(l2);
	}

	/* Responde aos eventos */
	public void actionPerformed(ActionEvent e){
		/* Auxiliares */
		int a;

		a = Integer.parseInt(this.usuario.getText());
		if(a == this.result)
			l2.setText("Acertou!");
		else
			l2.setText("Tentativas: " + this.tent);
	}

	/* Calcula o maior de alguns numeros */
	public double MaiorDeDois(double a, double b){
		if(a > b)
			return a;
		return b;
	}
	public double MaiorDeTres(double a, double b, double c){
		if(this.MaiorDeDois(a, b) > c)
			return this.MaiorDeDois(a, b);
		return c;
	}

}
