import java.util.*;

public class Institution implements Component {
  private List<Component> sons;

  public Institution(){
    this.sons = new ArrayList<Component>();
  }

  public void addSon(Component son){
    this.sons.add(son);
  }

  public int getSeats(){
    int sum = 0;

    for(Component c: this.sons){
      sum += c.getSeats();
    }

    return sum;
  }

  public int getParticipants(){
    return 1 + this.getSeats();
  }
}
