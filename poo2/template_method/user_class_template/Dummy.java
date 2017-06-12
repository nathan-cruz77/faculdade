public class Dummy {
    public static void main(String[] args){
        if(args.length < 2){
            System.out.println("Usage:\n  java Dummy <CLASS_NAME> <MESSAGE>");
        }

        String name = args[0];
        String msg = "";
        for(int i = 1; i < args.length; i++){ msg += args[i]; }

        Namer n = new ConcreteNamer(name);
        Extender e = new ConcreteExtender("");
        Methoder m = new ConcreteMethoder("DumbMethod", msg);

        try {
            new ClassTemplate(n, e, m).buildClass();
        } catch(Exception x){
            System.out.println("blah");
            x.printStackTrace();
        }
    }
}
