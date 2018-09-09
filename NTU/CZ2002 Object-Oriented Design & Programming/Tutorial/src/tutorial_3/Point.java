package tutorial_3;

public class Point {
	//variables
	protected int x;
	protected int y;
	
	//constructor
	public Point()
	{
		this.x = 1;
		this.y = 1;
	}
	
	public Point(int x, int y)
	{
		this.x = x;
		this.y = y;
	}
	
	//return coordinates in string
	public String toString()
	{
		return "[ " + Integer.toString(x) + ", " + Integer.toString(y) + " ]";
	}
	
	//assign coordinates
	public void setPoint(int x, int y)
	{
		this.x = x;
		this.y = y;
	}
	
	//get x coordinate
	public int getX()
	{
		return this.x;
	}
	
	//get y coordinate
	public int getY()
	{
		return this.y;
	}

}
