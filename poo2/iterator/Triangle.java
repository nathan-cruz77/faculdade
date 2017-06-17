public class Triangle implements Figure {
    private int side_1;
    private int side_2;
    private int side_3;
    
    public Triangle(int a, int b, int c){
        this.side_1 = a;
        this.side_2 = b;
        this.side_3 = c;
    }

    public void draw(){
        System.out.println("Pretend a triangle is being shown");
    }
}
