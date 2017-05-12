public class ActualObserver implements Observer {
    private int id;
    
    public ActualObserver(int id){
        this.id = id;
    }
    
    public void update(Observable o){
        System.out.print("Observer{" + this.id + "} received message ");
        System.out.print("from Observable{" + o.getId() + "}\n");
    }
}
