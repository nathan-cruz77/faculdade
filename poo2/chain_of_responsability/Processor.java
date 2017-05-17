import java.util.*;

public abstract class Processor {
    protected Processor sucessor;
    
    public abstract HashMap<String, Integer> process(String input);
}
