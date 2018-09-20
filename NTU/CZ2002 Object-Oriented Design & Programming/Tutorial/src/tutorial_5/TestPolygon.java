package tutorial_5;

public class TestPolygon {
	//dynamic binding (polymorphism)
	public static void printArea(Polygon p)
	{
		//dynamic binding
		if(p instanceof Rectangle)
			printArea((Rectangle)p);
		else if(p instanceof Triangle)
			printArea((Triangle) p);
	}
	
	private static void printArea(Rectangle r)
	{
		System.out.println("Area = " + r.calArea());
	}
	
	private static void printArea(Triangle  t)
	{
		System.out.println("Area = " + t.calArea());
	}

	public static void main(String[] args) {
		Polygon p;
		Rectangle r = new Rectangle("rect", 10, 5);
		Triangle t = new Triangle("tri", 5, 10);
		
		System.out.println("Static binding");
		//static binding
		printArea(r);
		printArea(t);
		
		
		System.out.println("Dynamic binding");
		//dynamic binding
		p = r;
		printArea(p);
		
		p = t;
		printArea(t);

	}

}
