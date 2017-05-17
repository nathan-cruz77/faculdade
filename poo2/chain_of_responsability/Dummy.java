import java.util.*;

public class Dummy {
    public static void main(String[] args){
        Processor p1 = new FrequencyCounter(" ", null);
        Processor p2 = new FrequencyCounter("a", p1);
        Processor p3 = new FrequencyCounter(".", p2);
        
        // Faz de conta que isso foi lido da entrada padrão
        String input = "blablabla blablablabla lba vlavla la l al ac ";

        // 6 de tudo
        String input2 = "aaaaaa      ......";
        
        System.out.println();
        print_count(p3.process(input));
        print_count(p3.process(input2));
    }
    
    
    public static void print_count(HashMap<String, Integer> x){
        System.out.println("================================");

        for(String k: x.keySet()){
            System.out.println("'" + k + "'" + ": " + x.get(k));
        }
        
        System.out.println("================================\n");
    }
}
