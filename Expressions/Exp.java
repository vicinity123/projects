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
		// Check for parentheses
		for (int i = startInd; i < expr.length; i++) {
			if (expr[i] == 40) {
				break;
			}
		}
		if (expr[startInd + 1] != 40) {
			System.out.println("Going to recurse");
			evaluate(startInd + 1);
		} else {
			System.out.println("Not parens...");
		}
	}

	public double calculate(double num1, char operator, double num2) {
		// EDGE CASES
		if (operator == '/' && num2 == 0) {
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
