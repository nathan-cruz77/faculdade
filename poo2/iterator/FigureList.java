import java.util.*;

public class FigureList {
    private List<Figure> actualList;
    private FigureListIterator iterator;

    public FigureList(){
        this.actualList = new ArrayList<Figure>();
        this.iterator = new FigureListIterator(this.actualList);
    }

    public FigureListIterator iterator(){
        return this.iterator;
    }

    public void add(Figure f){
        this.actualList.add(f);
    }
}
