import java.util.*;

public class FrequencyCounter extends Processor {
    private String count_key;

    public FrequencyCounter(String count_key, Processor next){
        this.sucessor = next;
        this.count_key = count_key;
    }
    
    public HashMap<String, Integer> process(String input){
        int index = 0;
        int count = 0;
        HashMap<String, Integer> result = new HashMap<String, Integer>();
        
        while(index != -1){
            index = input.indexOf(this.count_key, index);

            if(index != -1){
                count++;
                index += this.count_key.length();
            }
        }
        
        result.put(this.count_key, count);

        if(this.sucessor != null) result.putAll(this.sucessor.process(input));
        
        return result;
    }
}
