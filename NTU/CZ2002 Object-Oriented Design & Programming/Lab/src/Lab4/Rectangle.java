package Lab4;

public class Rectangle extends Shape{
	private double length;
	private double breadth;
	
	public Rectangle(double len, double bth)
	{
		this.length = len;
		this.breadth = bth;
	}
	
	public Rectangle(int num, double len, double bth)
	{
		setShapeType("Rectangle" + num);
		this.length = len;
		this.breadth = bth;
	}
	
	public double getLength()
	{
		return this.length;
	}
	
	public double getBreadth()
	{
		return this.breadth;
	}
	
	//get area
	public double Area()
	{
		return this.length * this.breadth;
	}

}
