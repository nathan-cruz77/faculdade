public class CircleCreator implements Creator {
    public Circle create() {
        Point p1 = (Point) FigureFactory.create("point");

        return new Circle(p1, 10);
    }
}
