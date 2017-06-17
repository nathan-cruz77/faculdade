import java.util.*;
import java.lang.*;

public class FigureListIterator implements ListIterator<Figure> {
    private List<Figure> list;
    private int currentIndex;

    public FigureListIterator(List<Figure> list){
        this.list = list;
        this.currentIndex = -1;
    }

    public void add(Figure f) throws UnsupportedOperationException {
        throw new UnsupportedOperationException();
    }

    public void set(Figure f) throws UnsupportedOperationException {
        throw new UnsupportedOperationException();
    }

    public void remove() throws UnsupportedOperationException {
        throw new UnsupportedOperationException();
    }

    public boolean hasNext(){
        return this.currentIndex + 1 < list.size();
    }

    public boolean hasPrevious(){
        return this.currentIndex - 1 >= 0;
    }

    public Figure next(){
        this.currentIndex += 1;
        return this.list.get(this.currentIndex);
    }

    public int nextIndex(){
        return this.currentIndex + 1;
    }

    public Figure previous(){
        this.currentIndex -= 1;
        return this.list.get(this.currentIndex);
    }

    public int previousIndex(){
        return this.currentIndex - 1;
    }
}
