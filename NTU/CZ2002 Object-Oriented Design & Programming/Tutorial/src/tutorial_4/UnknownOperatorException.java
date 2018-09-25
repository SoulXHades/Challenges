package tutorial_4;

public class UnknownOperatorException extends Exception {
	public UnknownOperatorException()
	{
		super("Unknown Operator Exception!");
	}
	
	public UnknownOperatorException(char op)
	{
		super(op + " is an unknown operator");
	}
	
	public UnknownOperatorException(String message)
	{
		super(message);
	}

}
