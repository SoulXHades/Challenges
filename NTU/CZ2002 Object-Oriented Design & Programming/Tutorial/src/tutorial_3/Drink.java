package tutorial_3;

public class Drink {
	//initialize
	private String name;
	private double cost;
	
	//constructors
	public Drink() {};
	
	public Drink(String name, double cost)
	{
		this.name = name;
		this.cost = cost;
	}
	
	//accessor
	public String getDrinkName()
	{
		return this.name;
	}
	
	public double getDrinkCost()
	{
		return this.cost;
	}

}
