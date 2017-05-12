import java.util.*;

public abstract class Observable {
    private List<Observer> observers = new ArrayList<Observer>();
    protected int id;
    
    public void add_obs(Observer obs){
        this.observers.add(obs);
    }
    
    public void custom_notify(){
        for(Observer o: this.observers) o.update(this);
    }
    
    public int getId(){
        return this.id;
    }
}
