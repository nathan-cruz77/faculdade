public class ActualPersonBuilder implements PersonBuilder {
    private Person person;

    public ActualPersonBuilder(){
        this.person = new Person();
    }

    @Override
    public Person build(){
        return this.person;
    }

    @Override
    public PersonBuilder setName(String name){
        this.person.setName(name);
        return this;
    }

    @Override
    public PersonBuilder setId(String id){
        this.person.setId(id);
        return this;
    }
}
