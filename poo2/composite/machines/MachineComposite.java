import java.util.*;

public class MachineComposite implements MachineComponent{

    private List<MachineComponent> components = new ArrayList<MachineComponent>();

    public void add(MachineComponent comp){
        this.components.add(comp);
    }
    
    public MachineComponent getSon(int index){
        return this.components.get(index);
    }
    
    public int getMachineCount(){
        int sum = 0;
        
        for(int i = 0; i < this.components.size(); i++){
            sum += this.components.get(i).getMachineCount();
        }
        
        return sum;
    }
}
