public class Dummy {
    public static void main(String[] args) {
        Document doc = new TextDocument();

        System.out.println("=================================================");
        doc.accept(new HTMLGenerator());
        System.out.println("=================================================");
        Boolean aux = (Boolean) doc.accept(new Validator());
        System.out.println("=================================================");
        doc.accept(new XMLGenerator());
        System.out.println("=================================================");

        if(aux) System.out.println(doc + " valid!");
    }
}
