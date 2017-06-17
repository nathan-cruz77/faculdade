public class FigureFactory {
    public static Figure create(String type){
        Creator c = null;
        
        if(type == "square") c = new SquareCreator();
        if(type == "circle") c = new CircleCreator();
        if(type == "triangle") c = new TriangleCreator();
        
        return c.create();
    }
}
