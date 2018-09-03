package tutorial_2;

public class Dice {
	private int valueOfDice;
	
	//create constructor
	public Dice()
	{
		//simulate like actual dice where there is a number from 1 to 6
		valueOfDice = 1;
	}
	
	//simulate throwing the dice
	public void setDiceValue()
	{
		//Math.random() is from 0 to less than 1 in double
		//+ 1 as dice have no 0 and (0.9.... * 6) is between 5.0 to less than 6.0 hence integer type casting will make it 5 
		valueOfDice = (int)(Math.random() * 6) + 1;
	}
	
	//get result of dice thrown
	public int getDiceValue()
	{
		return valueOfDice;
	}
	
	//print the current dice value
	public void printDiceValue()
	{
		System.out.println("Current Value is " + valueOfDice);
	}

}
