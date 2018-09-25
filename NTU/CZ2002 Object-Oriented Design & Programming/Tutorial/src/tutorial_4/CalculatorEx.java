/*
Write a program that implements a simple calculator. The calculator keeps track of a
single number (of type double) that is called result and that starts out as 0.0. The
user is allowed to repeatedly add, subtract, multiply, or divide the result by a second
number. The result of one of the operations becomes the new value of result. The
calculation ends when the user enters the character ‘Q’ or ‘q’ for quit. In addition,
if the user enters any operator symbol other than +, -, *, or /, the
UnknownOperatorException is thrown and the user is asked to reenter that line of
input. You are also required to define the class UnknownOperatorException.

A sample dialog of using the calculator is given below:

Calculator is on
result = 0.0
+
5
result + 5.0 = 5.0
updated result = 5.0
*
2.2
result * 2.2 = 11.0
updated result = 11.0
%
10
% is an unknown operator
Please reenter:
updated result = 11.0
*
0.1
result * 0.1 = 1.1
updated result = 1.1
q
Final result = 1.1
End of Program

The UML diagram for the class UnknownOperatorException and the class
ClaculatorEx is given below. Also write the static main() method in the CalculatorEx
class when starting the calculator.


*** UML ***
UnknownOperatorException
+ UnknownOperatorException()
+ UnknownOperatorException(op: char)
+ UnknownOperatorException(message: String)


CalculatorEx
- result: double
+ CalculatorEx()
+ resultValue(): double // return the result
+ doCalculation (): void // perform the calculation
+ evaluate(char op, double n1, double n2) : double // evaluate computation
+ handleUnknownOpException (): double // handle unknown operator exception
 									  // and ask user to reenter data again
*/

package tutorial_4;

import java.util.*;

public class CalculatorEx {
	//initialization
	private double result;
	Scanner sc = new Scanner(System.in);
	
	//constructor
	public CalculatorEx()
	{
		result = 0.0f;
	}
	
	//return the result
	public double resultValue()
	{
		return result;
	}
	
	//perform calculation
	public void doCalculation() throws Exception
	{
		char op = sc.next().charAt(0);
		double val;
		
		//if user wants to off calculator
		if(Character.toLowerCase(op) == 'q')
			throw new Exception();
		else
			val = sc.nextDouble();
		
		try
		{
			//get calculation result
			result = evaluate(op, result, val);
			System.out.println("result " + Character.toString(op) + " " + val + " = " + result);
		}
		catch (UnknownOperatorException e)
		{
			//handles error
			System.out.println(e.getMessage());
			result = handleUnknownOpException();
		}
	}
	
	//evaluate computation
	public double evaluate(char op, double n1, double n2) throws UnknownOperatorException
	{
		switch(op)
		{
			case '+':	return n1 + n2;
			case '-':	return n1 - n2;
			case '*':	return n1 * n2;
			case '/':	return n1 / n2;
			default:	throw new UnknownOperatorException(op);
		}
	}
	
	//handle unknown operator exception
	//and ask user to reenter data again
	public double handleUnknownOpException() throws Exception
	{
		char op;;
		double val, tempResult;
		
		//get input again
		System.out.println("Please reenter:");
		System.out.println("updated result = " + result);
		op = sc.next().charAt(0);
		
		//if user wants to off calculator
		if(Character.toLowerCase(op) == 'q')
			throw new Exception();
		else if(op != '+' && op != '-' && op != '*' && op != '/')
		{
			System.out.println("Error: System is terminating!");
			System.exit(0);
		}
		
		//after checking operator, can ask user for operand
		val = sc.nextDouble();
		
		//need a tempResult as we need to print the updated operator(op) here
		tempResult = evaluate(op, result, val);
		System.out.println("result " + Character.toString(op) + " " + val + " = " + tempResult);
		
		return tempResult;
		
	}
	
	public static void main(String[] args) {
		CalculatorEx ce1 = new CalculatorEx();
		
		System.out.println("Calculator is on");
		System.out.println("result = " + ce1.resultValue());
		
		try {
			while(true)
			{
				ce1.doCalculation();
				
				System.out.println("updated result = " + ce1.resultValue());
			}
		}
		catch(Exception e)
		{
			//when have other unhandled errors or when exiting the program
			System.out.println("Final result = " + ce1.resultValue());
			System.out.println("End of Program");
		}
	}

}
