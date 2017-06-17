public class ReverseText implements Decoratable {
    private Decoratable t;

    public ReverseText(Decoratable t){
        this.t = t;
    }

    public String getText(){
        return new StringBuilder(this.t.getText()).reverse().toString();
    }
}
