public class Curso {
    private String nome;
    private int codigo;

    private static Curso instance = null;
    
    private Curso(){}
    
    // Pretend no one calls this
    public Curso(int codigo, String nome){
        this.codigo = codigo;
        this.nome = nome;
    }
    
    public String getNome(){
        return this.nome;
    }
    
    public int getCodigo(){
        return this.codigo;
    }
    
    public static Curso getInstance(){
        if(instance == null){
            instance = new Curso();
        }
        
        return instance;
    }
}
