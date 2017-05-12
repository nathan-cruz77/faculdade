public class Client {
    private Subject subject;
    
    public Client(Subject sub){
        this.subject = sub;
    }
    
    public void remoteOperation(){
        this.subject.operation();
    }
}
