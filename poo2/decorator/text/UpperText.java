public class UpperText implements Decoratable {
    private Decoratable t;

    public UpperText(Decoratable t){
        this.t = t;
    }

    public String getText(){
        return t.getText().toUpperCase();
    }
}
