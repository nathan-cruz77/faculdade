import java.util.concurrent.ThreadLocalRandom;

public class Dummy {
    public static void main(String[] args){
        DigitFactory factory = new DigitFactory();
        
        for(int i = 0; i < 10; i++){
            genNumber(factory);
        }
        
        System.out.println("Digit objects count: " + factory.size());
    }
    
    public static void genNumber(DigitFactory factory){
        int rand_num;
        
        System.out.println("================================");
        for(int i = 0; i < 10; i++){
            rand_num = ThreadLocalRandom.current().nextInt(0, 10);
            System.out.printf("%s", factory.getDigit("" + rand_num).toString());
        }
        System.out.println("\n================================\n");
    }
}
