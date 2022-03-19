package Expressions;

import java.util.Arrays;

public class Exp {
    public char[] expr;
    public double result;

    // Constructor
    public Exp(String _expr) {
        this.expr = _expr.replace(" ", "").toCharArray();
    }

    // GET Method
    public String getExpression() {
        return String.valueOf(this.expr);
    }

    public void evaluate(int startInd) {
        char operator = '\u0000';
        String num1 = "", num2 = "";
        int numLength = 0;
        for (int i = 0; i < expr.length; i++) {
            if (expr[i] == 37 || expr[i] == 42 || expr[i] == 43 || expr[i] == 45 || expr[i] == 47 || expr[i] == 94) {
                operator = expr[i];
                continue;
            }
            while (i + numLength < expr.length && ((expr[i + numLength] > 47 && expr[i + numLength] < 58) || (expr[i + numLength] == 46))) {
                numLength++;
            }
            if (num1.equals("")) {
                num1 = String.valueOf(Arrays.copyOfRange(expr, i, i + numLength));
            } else {
                num2 = String.valueOf(Arrays.copyOfRange(expr, i, i + numLength));
            }
            i += numLength - 1;
            // Reset numLength to 0
            numLength = 0;
        }
        if (num1.equals("") != true && num2.equals("") != true && operator != '\u0000') {
            try {
                result = calculate(Double.parseDouble(num1), operator, Double.parseDouble(num2));
                System.out.println(result);
            } catch (IllegalArgumentException e) {
                System.out.println("Invalid divisor input. (Division by zero error)");
            }
        } else {
            System.out.println("Invalid input given...");
        }
    }
    public double calculate(double num1, char operator, double num2) {
        // EDGE CASES
        if(operator == '/' && num2 == 0) {
            throw new IllegalArgumentException();
        }
        if (operator == '+') { // ASCII: 43
            return num1 + num2;
        } else if (operator == '-') { // ASCII: 45
            return num1 - num2;
        } else if (operator == '*') { // ASCII: 42  
            return num1 * num2;
        } else if (operator == '/') { // ASCII: 47  
            return num1 / num2;
        } else if (operator == '%') { // ASCII: 37
            return num1 % num2;
        } else if (operator == '^') { // ASCII: 94
            return Math.pow(num1, num2);
        }
        return 0.1234575333;
    }
}
