package tutorial_3;

public class Cylinder extends Circle{
	//initialize
	private double height;
	
	//constructors
	public Cylinder()
	{
		this(1,1);
	}
	
	public Cylinder(int x, int y)
	{
		super(x, y);
	}
	
	//accessors and mutators
	public void setHeight(double h)
	{
		this.height = h;
	}
	
	public double getHeight()
	{
		return this.height;
	}
	
	//get area of cylinder
	public double area()
	{
		return (2 * super.PI * super.getRadius() * this.height) + (2 * super.PI * Math.pow(super.getRadius(), 2));
	}
	
	//get volume of cylinder
	public double volume()
	{
		return super.area() * this.height; 
	}
	
	//return info and coordinates
	public String toString()
	{
		return "Cylinder of radius" + super.getRadius() + "and height" + height + "at point [ " + Integer.toString(super.getX()) + ", " + Integer.toString(super.getY()) + " ]";
	}

}
