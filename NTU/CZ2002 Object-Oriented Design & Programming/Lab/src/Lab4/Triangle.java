package Lab4;

public class Triangle extends Shape{
	private double base;
	private double height;
	
	public Triangle(double base, double height)
	{
		this.base = base;
		this.height = height;
	}
	
	public Triangle(int num, double base, double height)
	{
		setShapeType ("Triangle" + num);
		this.base = base;
		this.height = height;
	}
	
	public double getBase()
	{
		return this.base;
	}
	
	public double getHeight()
	{
		return this.height;
	}
	
	public double Area()
	{
		return 0.5 * this.base * this.height;
	}

}
