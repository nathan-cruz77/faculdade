import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

/*
 * <applet code="Exercicio1" height="200" width="200"></applet>
 */

public class Exercicio1 extends JApplet implements ActionListener{

	/* Atributos */
	private JButton b1;
	private JButton b2;
	private JTextField clicado;

	/* Main da aplicacao */
	public void init(){
		this.clicado = new JTextField(20);
		this.b1 = new JButton("Botao1");
		this.b2 = new JButton("Botao2");

		this.b1.addActionListener(this);
		this.b2.addActionListener(this);

		setLayout(new FlowLayout());
		add(this.b1);
		add(this.b2);
		add(this.clicado);
	}

	/* Responde aos eventos */
	public void actionPerformed(ActionEvent e){
		if(e.getSource() == this.b1)
			this.clicado.setText("Clicado: Botao1");
		else
			this.clicado.setText("Clicado: Botao2");
	}

}
