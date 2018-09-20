package tutorial_5;

public class Rectangle extends Polygon {
	//constructors
	public Rectangle(String theName, float theWidth, float theHeight)
	{
		super(theName, theWidth, theHeight);
		
		//set the polygon type
		super.setPolytype(KindofPolygon.POLY_RECT);
	}
	
	public float calArea()
	{
		return super.width * super.height;
	}

}
