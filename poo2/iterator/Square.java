public class Square implements Figure{
    private int side_1;
    private int side_2;
    
    public Square(int s1, int s2){
        this.side_1 = s1;
        this.side_2 = s2;
    }
    
    public void draw(){ System.out.println("Pretend a square is being shown"); }
}
