import java.util.Iterator;

public class NewApiProvider implements Iterator {
    private int[] vet;
    int index = 0;

    public NewApiProvider(int i){
        vet = new int[i];
        for(int j = 0; j < vet.length; j++) vet[j] = j;
    }

    @Override
    public boolean hasNext(){
        return this.index < this.vet.length;
    }

    @Override
    public Integer next(){
        Integer aux = (Integer) this.vet[this.index];
        this.index++;

        return aux;
    }

    @Override
    public void remove(){}
}
