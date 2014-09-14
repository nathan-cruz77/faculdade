/*
 *  Programa escrito com propósito didático apenas.
 *  @author Nathan Cruz <nathan.cruz@unifesp.br>
 *  @created 04/04/14
 *  R.A.: 86492
 */

/* Criacao de excecao propria */

public class ValorInvalidoException extends RuntimeException{

    /* Construtor */
    public ValorInvalidoException(String mensagem){
        super(mensagem);
    }
}
