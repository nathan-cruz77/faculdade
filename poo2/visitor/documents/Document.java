public interface Document<T> {
    public T accept(Visitor v);
}
