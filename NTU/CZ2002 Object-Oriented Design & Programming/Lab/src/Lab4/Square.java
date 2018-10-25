package Lab4;

public class Square extends Shape{
	private double length;
	
	public Square(double len)
	{
		this.length = len;
	}
	
	public Square(int num, double len)
	{
		setShapeType("Square" + num);
		this.length = len;
	}
	
	public double getLength()
	{
		return this.length;
	}
	
	//get area of Square
	public double Area()
	{
		return this.length * this.length;
	}

}
