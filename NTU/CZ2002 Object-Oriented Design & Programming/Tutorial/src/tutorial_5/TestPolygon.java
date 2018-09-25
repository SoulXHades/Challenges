/*
3. Figure 2 (given on the next page) lists the Java code for a Polygon class. Two
subclasses, Rectangle and Triangle, are derived from the Polygon class.

(i) Write the code for the Rectangle and Triangle subclass.

(ii) Write a TestPolygon class to have a overloaded method printArea(….)
which will calculate and printout the area of the polygon type passed as
argument, ie printArea(Rectangle r) and printArea(Triangle t). 

(iii) Write the main( ) function to demonstrate static binding of all printArea
methods.[Hints : have overloaded printArea methods for each Polygon
subclass].
What is the impact on the program when a new subclass of Polygon is
introduced?

(iv) Repeat part (ii) for dynamic binding of printArea( ).
 [Hints : have a single printArea method, regardless of which Polygon subclass].
 
(v) Modify the Polygon code so that any of its subclasses must include a
calArea() member method. Suggest reason(s) why this requirement would be
appropriate in this case.


*** SAMPLE CODE ***
(Figure 2)
public class Polygon {
	public enum KindofPolygon { POLY_PLAIN, POLY_RECT, POLY_TRIANG};
	protected String name;
	protected float width;
	protected float height;
	protected KindofPolygon polytype;
	
	public Polygon(String theName, float theWidth, float theHeight) {
		name = theName;
		width = theWidth;
		height = theHeight;
		polytype = KindofPolygon.POLY_PLAIN;
	}
	
	public KindofPolygon getPolytype() {
		return polytype;
	}
	
	public void setPolytype(KindofPolygon value) {
		polytype = value;
	}
	
	public String getName() { return name; }
	public float calArea() { return 0; }
	public void printWidthHeight( ) {
		System.out.println("Width = " + width + " Height = " + height);
	}
}
*/

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
