import java.util.*;

public class ActualMediator implements Mediator {
    private List<Colleague> colleagues = new ArrayList<Colleague>();
    
    public void send(String msg, Colleague source){
        for(Colleague c: this.colleagues){
            if(c != source) c.receive(msg, source);
        }
    }

    public void addColleague(Colleague c){
        this.colleagues.add(c);
    }
}
