public class Text implements Decoratable {
    private String text;

    public Text(String t){
        this.text = t;
    }

    public String getText(){
        return this.text;
    }
}
