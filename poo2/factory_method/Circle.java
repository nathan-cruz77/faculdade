public class Circle implements Figure {
    private int radius;
    
    public Circle(int radius){
        this.radius = radius;
    }
    
    public void draw(){ System.out.println("Pretend a circle is being shown"); }
}
