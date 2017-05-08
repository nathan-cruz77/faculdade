public class Escola {

    public static Curso getCurso(int cod){
        return new Curso(cod, "Direito na unip");
    }
    public static Aluno getAluno(int cod){
        return new Aluno(cod, "Joaozinho");
    }
}
