package Lab4;

public abstract class Shape {
	//store the shape type such as square, rectangle, etc
	private String shapeType;
	
	public String getShapeType()
	{
		return shapeType;
	}
	
	public void setShapeType(String type)
	{
		this.shapeType = type;
	}
	
	//abstract hence to be implemented by child classes
	public abstract double Area();

}
