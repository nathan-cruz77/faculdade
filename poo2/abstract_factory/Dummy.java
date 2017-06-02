public class Dummy {
    public static void main(String[] args){
        Figure f1, f2, f3;
        
        f1 = FigureFactory.create("square");
        f2 = FigureFactory.create("circle");
        f3 = FigureFactory.create("triangle");
        
        System.out.println("===============");
        System.out.println("Square");
        f1.draw();
        System.out.println("===============\n");
        
        System.out.println("===============");
        System.out.println("Circle");
        f2.draw();
        System.out.println("===============\n");

        System.out.println("===============");
        System.out.println("Triangle");
        f3.draw();
        System.out.println("===============\n");
        
    }
}
