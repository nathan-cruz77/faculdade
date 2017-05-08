public class Dummy {
    public static void main(String[] args){
        Curso c1 = Curso.getInstance();
        Curso c2 = Curso.getInstance();

        if(c1 == c2){
            System.out.println("Singleton!");
        }
        else{
            System.out.println("Not a singleton!");
        }
        
    }
}
