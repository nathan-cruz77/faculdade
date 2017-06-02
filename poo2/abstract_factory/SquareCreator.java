public class SquareCreator implements Creator {
    public Square create(){
        Point p1 = (Point) FigureFactory.create("point");
        Point p2 = (Point) FigureFactory.create("point");
        
        return new Square(p1, p2);
    }
}
