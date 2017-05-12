public class SubjectProxy implements Subject {
    private Subject subject;

    public SubjectProxy(Subject sub){
        this.subject = sub;
    }

    public void operation(){
        System.out.println("Proxy call");
        this.subject.operation();
    }
}
