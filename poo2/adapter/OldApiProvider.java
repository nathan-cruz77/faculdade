import java.util.Enumeration;

public class OldApiProvider implements Enumeration {
    private int[] vet;
    int index = 0;

    public OldApiProvider(int i){
        this.vet = new int[i];
        for(int j = 0; j < this.vet.length; j++) vet[j] = j;
    }

    @Override
    public boolean hasMoreElements(){
        return this.index < this.vet.length;
    }

    @Override
    public Integer nextElement(){
        Integer aux = (Integer) this.vet[this.index];
        this.index++;

        return aux;
    }
}
