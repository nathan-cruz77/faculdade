public class Dummy {
    public static void main(String[] args){
        FigureList list = new FigureList();
        Figure f = null;

        list.add(FigureFactory.create("square"));
        list.add(FigureFactory.create("circle"));
        list.add(FigureFactory.create("triangle"));

        System.out.println();
        for(FigureListIterator it = list.iterator(); it.hasNext();){
            f = it.next();
            System.out.println("======================");
            f.draw();
            System.out.println("======================");
        }
        System.out.println();
    }
}
