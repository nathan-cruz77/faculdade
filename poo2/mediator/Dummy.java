public class Dummy {

    public static void main(String[] args){
        ActualMediator mediator = new ActualMediator();
        
        ActualColleague c1 = new ActualColleague("C1", mediator);
        ActualColleague c2 = new ActualColleague("C2", mediator);
        ActualColleague c3 = new ActualColleague("C3", mediator);

        // c2 and c3 notified
        System.out.println("================");
        c1.send("Python");
        System.out.println("================");

        // c1 and c3 notified
        System.out.println("\n================");
        c2.send("Java");
        System.out.println("================");
        
        // c1 and c2 notified
        System.out.println("\n================");
        c3.send("Javascript");
        System.out.println("================");
    }

}
