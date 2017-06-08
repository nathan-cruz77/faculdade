import java.util.*;

public class Dummy {
    public static void main(String[] args){
        Strategy strategy;
        int day = (new GregorianCalendar()).get(Calendar.DAY_OF_WEEK);
        
        if(day == Calendar.MONDAY) strategy = new MondayStrategy();
        else if(day == Calendar.TUESDAY) strategy = new TuesdayStrategy();
        else strategy = new DefaultStrategy();
        
        System.out.println("\n================ Strategy ================");
        strategy.execute();
        System.out.println("==========================================\n");
    }
}
