public class AddOperation implements Operation {
    public double visit(Pair p){
        return p.getFirstOperand() + p.getSecondOperand();
    }
}
