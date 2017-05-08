import java.util.List;

import javax.swing.JTextField;
import javax.swing.JList;
import javax.swing.DefaultListModel;

public class MatriculaGui {

    private JList<Aluno> list;
    private DefaultListModel<Aluno> displayList;
    private JTextField cursoFld;
    
    public MatriculaGui(){
        this.displayList = new DefaultListModel<>();
        this.list = new JList<Aluno>(this.displayList);
        this.cursoFld = new JTextField();
    }

    public void matricular(int codAluno, int codCurso, Turma turma){
        if(turma == null){
            turma = new Turma();
            Curso c = Escola.getCurso(codCurso);
            turma.setCurso(c);
        }
        
        Aluno rex = Escola.getAluno(codAluno);
        turma.addAluno(rex);
    }
    
    public void exibirStatus(Turma turma){
        this.cursoFld.setText(turma.getCurso().getNome());
        
        Aluno[] alunos = turma.getAlunos();
        
        for(int i = 0; i < alunos.length; i++){
            this.displayList.addElement(alunos[i]);
        }
    }

}
