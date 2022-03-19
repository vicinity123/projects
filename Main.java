import Expressions.Exp;

class Main {
    public static void main(String[] args) {
        Exp exp1 = new Exp("400 ^ 0.5");
        System.out.println(exp1.getExpression() + "\n");
        exp1.evaluate(0);
    }
}
