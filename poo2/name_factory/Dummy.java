public class Dummy {
    public static void main(String[] args){
        // Pretend these come from stdin
        String s1 = "Stormrage, Illidan";
        String s2 = "Illidan Stormrage";
        
        System.out.println("\n===============================");
        System.out.println("Read: \"" + s1 + "\"");
        System.out.println("Repr: \"" + NameFactory.create(s1).toString() + "\"");
        System.out.println("===============================\n");
        
        System.out.println("===============================");
        System.out.println("Read: \"" + s2 + "\"");
        System.out.println("Repr: \"" + NameFactory.create(s2).toString() + "\"");
        System.out.println("===============================\n");
    }
}
