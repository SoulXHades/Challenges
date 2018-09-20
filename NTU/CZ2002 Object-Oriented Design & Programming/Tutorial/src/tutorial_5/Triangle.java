package tutorial_5;

public class Triangle extends Polygon {
	//constructors
	public Triangle(String theName, float theWidth, float theHeight)
	{
		super(theName, theWidth, theHeight);
		
		//set the polygon type
		super.setPolytype(KindofPolygon.POLY_TRIANG);
	}
	
	public float calArea()
	{
		return 0.5f * super.width * super.height;
	}

}
