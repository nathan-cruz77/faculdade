public class Dummy {
    public static void main(String[] args){
        Pair operands = new Pair(1, 2);
        double result;

        System.out.println("=================================================");
        result = operands.accept(new AddOperation());
        System.out.println("" + operands.getFirstOperand() + " + " + operands.getSecondOperand() + " = " + result);
        System.out.println("=================================================");
        result = operands.accept(new MultiplyOperation());
        System.out.println("" + operands.getFirstOperand() + " * " + operands.getSecondOperand() + " = " + result);
        System.out.println("=================================================");
    }
}
