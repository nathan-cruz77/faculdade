public class Dummy {
    public static void main(String[] args){
        Text t = new Text("Bla");
        UpperText upper = new UpperText((Decoratable) t);
        ReverseText reverse = new ReverseText((Decoratable) t);
        BoldText bold = new BoldText((Decoratable) t);

        System.out.println("\n=================== Simple  ===================");
        System.out.println(t.getText());
        System.out.println("\n===================  Upper  ===================");
        System.out.println(upper.getText());
        System.out.println("\n=================== Reverse ===================");
        System.out.println(reverse.getText());
        System.out.println("\n===================  Bold   ===================");
        System.out.println(bold.getText());
        System.out.println("\n=================== Upper && Reverse ==========");
        UpperText new_upper = new UpperText(reverse);
        System.out.println(new_upper.getText());

        System.out.println();
    }
}
