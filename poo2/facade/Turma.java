import java.util.List;
import java.util.ArrayList;

public class Turma {
    private List<Aluno> alunos = new ArrayList<Aluno>();
    private Curso curso;
    
    public void setCurso(Curso c){
        this.curso = c;
    }
    
    public Curso getCurso(){
        return this.curso;
    }
    
    public void addAluno(Aluno a){
        this.alunos.add(a);
    }
    
    public Aluno[] getAlunos(){
        Aluno[] aux = new Aluno[this.alunos.size()];
        this.alunos.toArray(aux);
        return aux;
    }
}
