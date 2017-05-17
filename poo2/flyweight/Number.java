public class Number implements Digit {
    private String digit;
    
    public Number(String x){
        this.digit = x;
    }
    
    public String toString(){
        return this.digit;
    }
}
