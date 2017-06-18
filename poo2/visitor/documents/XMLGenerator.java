public class XMLGenerator implements Visitor<Object> {
    public Object visit(SheetDocument x){
        x.generateXML();
        return null;
    }

    public Object visit(TextDocument t){
        t.generateXML();
        return null;
    }

    public Object visit(GraphDocument g){
        g.generateXML();
        return null;
    }
}
