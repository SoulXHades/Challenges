package Lab4;

public class Sphere extends Circle{
	public Sphere(double radius)
	{
		super(radius);
	}
	
	public Sphere(int num, double radius)
	{
		super(radius);
		setShapeType("Sphere" + num);
	}
	
	//get area of sphere
	public double Area()
	{
		return 2 * super.Area();
	}
	
	//get volume of sphere
	public double Volumne()
	{
		return (double)4/3 * PI * Math.pow(super.getRadius(), 3);
	}

}
