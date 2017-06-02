public class Triangle implements Figure {
    private Point point_1;
    private Point point_2;
    private Point point_3;
    
    public Triangle(Point a, Point b, Point c){
        this.point_1 = a;
        this.point_2 = b;
        this.point_3 = c;
    }

    public void draw(){
        System.out.println("Pretend a triangle is being shown");
    }
}
