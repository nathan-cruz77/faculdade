public abstract class Colleague {
    protected Mediator mediator;
    protected String name;

    public void send(String msg){
        this.mediator.send(msg, this);
    }
    
    public void receive(String msg, Colleague source){
        System.out.print("Colleague<" + this.name + "> received ");
        System.out.print("\"" + msg + "\" from: Colleague<" + source.name + ">\n");
    }
}
