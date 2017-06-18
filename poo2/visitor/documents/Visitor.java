public interface Visitor<T> {
    public T visit(GraphDocument g);
    public T visit(TextDocument g);
    public T visit(SheetDocument g);
}
