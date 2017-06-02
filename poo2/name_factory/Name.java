public abstract class Name {
    protected String name;
    protected String lastName;
    
    public String toString(){
        return this.name + " " + this.lastName;
    }
    
    public void setName(String name){
        this.name = name;
    }
    
    public void setLastName(String lastName){
        this.lastName = lastName;
    }
}
