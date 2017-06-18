public class SheetDocument implements Document<Object> {
    public Object accept(Visitor v){
        return v.visit(this);
    }

    public void generateHTML(){
        System.out.println("Pretend we are generating HTML for " + this.getClass().getName());
    }

    public Boolean validate(){
        System.out.println("Pretend this is a validation");
        return new Boolean(true);
    }

    public String toString(){
        return "Example " + this.getClass().getName() + " document";
    }

    public Object generateXML(){
        System.out.println("Generating XML");
        return null;
    }
}
