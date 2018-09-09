package tutorial_3;

public class Cylinder extends Circle{
	private double height;
	
	public Cylinder()
	{
		this(1,1);
	}
	
	public Cylinder(int x, int y)
	{
		super(x, y);
	}
	
	public void setHeight(double h)
	{
		this.height = h;
	}
	
	public double getHeight()
	{
		return this.height;
	}
	
	public double area()
	{
		return (2 * super.PI * super.getRadius() * this.height) + (2 * super.PI * Math.pow(super.getRadius(), 2));
	}
	
	public double volume()
	{
		return super.area() * this.height; 
	}

}
