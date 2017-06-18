public class HTMLGenerator implements Visitor<Object> {
    public Object visit(SheetDocument x){
        x.generateHTML();
        return null;
    }

    public Object visit(TextDocument t){
        t.generateHTML();
        return null;
    }

    public Object visit(GraphDocument g){
        g.generateHTML();
        return null;
    }
}
