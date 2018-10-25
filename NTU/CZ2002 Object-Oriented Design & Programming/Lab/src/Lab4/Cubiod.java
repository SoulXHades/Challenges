package Lab4;

public class Cubiod extends Rectangle{
	private double height;
	
	public Cubiod(double len, double bth, double height)
	{
		super(len, bth);
		this.height = height;
	}
	
	public Cubiod(int num, double len, double bth, double height)
	{
		super(len, bth);
		super.setShapeType("Cubiod" + num);
		this.height = height;
	}
	
	public double Area()
	{
		return (super.Area() * 2) + (2 * super.getLength() * this.height) + (2 * super.getBreadth() * this.height);
	}
	
	public double Volume()
	{
		//Volume = area of rectangle * height
		return super.Area() * this.height;
	}

}
