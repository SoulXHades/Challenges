package tutorial_3;

public class Circle extends Point{
	//initialization
	private double radius;
	protected final double PI = 3.14159;
	
	//constructors
	public Circle()
	{
		this(1, 1);
	}
	
	public Circle(int x, int y)
	{
		super(x, y);
	}
	
	//set the circle's radius
	public void setRadius(double rad)
	{
		this.radius = rad;
	}
	
	//get the circle's radius
	public double getRadius()
	{
		return this.radius;
	}
	
	//get the area of the circle
	public double area()
	{
		return Math.pow(this.radius, 2) * PI;
	}
	
	//return info and coordinates
	public String toString()
	{
		return "Cylinder of radius" + radius + "at point [ " + Integer.toString(super.getX()) + ", " + Integer.toString(super.getY()) + " ]";
	}

}
