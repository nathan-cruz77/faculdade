import java.util.*;

public class DigitFactory {
    private HashMap<String, Digit> cache = new HashMap<String, Digit>();
    
    public Digit getDigit(String id){
        if(this.cache.containsKey(id))
            return this.cache.get(id);
        
        this.cache.put(id, new Number(id));
        return this.cache.get(id);
    }
    
    public int size(){
        return this.cache.size();
    }
}
