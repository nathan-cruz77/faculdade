public class Pair implements OperandPair {
    private double operand1;
    private double operand2;

    public Pair(double a, double b){
        this.operand1 = a;
        this.operand2 = b;
    }

    public double accept(Operation op){
        return op.visit(this);
    }

    public double getFirstOperand(){
        return this.operand1;
    }

    public double getSecondOperand(){
        return this.operand2;
    }
}
