public class MultiplyOperation implements Operation {
    public double visit(Pair p){
        return p.getFirstOperand() * p.getSecondOperand();
    }
}
