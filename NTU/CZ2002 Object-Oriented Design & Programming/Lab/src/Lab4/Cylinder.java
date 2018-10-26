package Lab4;

public class Cylinder extends Circle{
	private double height;
	
	public Cylinder(double radius, double height)
	{
		super(radius);
		this.height = height;
	}
	
	public Cylinder(int num, double radius, double height)
	{
		super(radius);
		setShapeType("Cylinder" + num);
		this.height = height;
	}
	
	public double getHeight()
	{
		return this.height;
	}
	
	public double Area()
	{
		return (2 * PI * super.getRadius() * this.height) + (2 * super.Area());
	}
	
	public double Volume()
	{
		return super.Area() * this.height;
	}

}
