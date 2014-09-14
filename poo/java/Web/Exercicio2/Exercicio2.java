import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

/*
 * <applet code="Exercicio2" height="200" width="200"></applet>
 */

public class Exercicio2 extends JApplet implements ActionListener{

    /* Atributos */
    private JButton b1;
    private JLabel n1, n2, n3, result;
    private JTextField N1, N2, N3;


    /* Main da aplicacao */
    public void init(){

        /* Inicializa os elementos */
        this.n1 = new JLabel("Primeiro numero: ");
        this.n2 = new JLabel("Segundo numero: ");
        this.n3 = new JLabel("Terceiro numero: ");
        this.N1 = new JTextField(15);
        this.N2 = new JTextField(15);
        this.N3 = new JTextField(15);
        this.b1 = new JButton("Calcular");
        this.result = new JLabel();

        this.b1.addActionListener(this);

        setLayout(new GridLayout(4, 2));
        add(this.n1);
        add(this.N1);

        add(this.n2);
        add(this.N2);

        add(this.n3);
        add(this.N3);

        add(this.b1);
        add(this.result);
    }

    /* Responde aos eventos */
    public void actionPerformed(ActionEvent e){
        /* Auxiliares */
        double a, b, c;

        if(e.getSource() == this.b1){
            a = Double.parseDouble(this.N1.getText());
            b = Double.parseDouble(this.N2.getText());
            c = Double.parseDouble(this.N3.getText());
            this.result.setText(String.valueOf(this.MaiorDeTres(a, b, c)));
        }
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
