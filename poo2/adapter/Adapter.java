import java.util.Iterator;

public class Adapter extends OldApiProvider implements Iterator<Integer> {
    public Adapter(int i){
        super(i);
    }

    @Override
    public boolean hasNext(){
        return this.hasMoreElements();
    }

    @Override
    public Integer next(){
        return this.nextElement();
    }

    @Override
    public void remove(){}
}
