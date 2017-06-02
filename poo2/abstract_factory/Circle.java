public class Circle implements Figure {
    private int radius;
    private Point center;
    
    public Circle(Point center, int radius){
        this.radius = radius;
        this.center = center;
    }
    
    public void draw(){ System.out.println("Pretend a circle is being shown"); }
}
