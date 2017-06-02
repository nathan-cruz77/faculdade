public class Point implements Figure {
    private int x;
    private int y;
    
    public Point(int x, int y){
        this.x = x;
        this.y = y;
    }
    
    public void draw(){
        System.out.println("Pretend a point is being shown");
    }
}
