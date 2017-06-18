public class Validator implements Visitor<Object> {
    public Object visit(GraphDocument g){
        return g.validate();
    }

    public Object visit(TextDocument t){
        return t.validate();
    }

    public Object visit(SheetDocument s){
        return s.validate();
    }
}
