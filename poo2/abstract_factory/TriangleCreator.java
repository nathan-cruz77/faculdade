public class TriangleCreator implements Creator {
    public Triangle create(){
        Point p1 = (Point) FigureFactory.create("point");
        Point p2 = (Point) FigureFactory.create("point");
        Point p3 = (Point) FigureFactory.create("point");

        return new Triangle(p1, p2, p3);
    }
}
