public class ActualColleague extends Colleague {

    public ActualColleague(String name, Mediator mediator){
        this.mediator = mediator;
        this.name = name;
        
        mediator.addColleague(this);
    }

}
