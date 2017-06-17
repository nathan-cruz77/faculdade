public class BoldText implements Decoratable {
    private Decoratable t;

    public BoldText(Decoratable t){
        this.t = t;
    }

    public String getText(){
        return "<b>" + t.getText() + "</b>";
    }
}
