package Lab4;

//square based
public class Pyramid extends Triangle{
	private Square s1;
	
	public Pyramid(double base, double height)
	{
		super(base, height);
		s1 = new Square(base);
	}
	
	public Pyramid(int num, double base, double height)
	{
		super(base, height);
		setShapeType("Pyramid" + num);
	}
	
	public double Area()
	{
		//area of square based pyramid is base area + all 4 surfaces of the triangles 
		return s1.Area() + (2 * (super.getBase() * Math.sqrt(Math.pow(super.getBase()/2, 2) + Math.pow(super.getHeight(), 2))));
	}
	
	public double Volume()
	{
		return (super.getBase() * super.getBase() * super.getHeight())/3;
	}

}
