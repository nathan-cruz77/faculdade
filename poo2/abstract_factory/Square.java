public class Square implements Figure{
    private Point p1;
    private Point p2;
    
    public Square(Point p1, Point p2){
        this.p1 = p1;
        this.p2 = p2;
    }
    
    public void draw(){ System.out.println("Pretend a square is being shown"); }
}
