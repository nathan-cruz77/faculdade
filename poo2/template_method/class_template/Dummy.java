public class Dummy {
    public static void main(String[] args){
        Namer n = new ConcreteNamer("DumbClass");
        Extender e = new ConcreteExtender("");
        Methoder m = new ConcreteMethoder("DumbMethod");

        try {
            new ClassTemplate(n, e, m).buildClass();
        } catch(Exception x){
            System.out.println("blah");
            x.printStackTrace();
        }
    }
}
