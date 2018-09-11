package tutorial_3;

import java.util.*;

public class VendingMachine {
	//initialize
	private double drinkCost;
	private boolean run;
	Scanner sc = new Scanner(System.in);
	Drink[] drinks;
	
	//constructor
	public VendingMachine()
	{
		drinks = new Drink[3];
		drinks[0] = new Drink("Beer", 3.00);
		drinks[1] = new Drink("Coke", 1.00);
		drinks[2] = new Drink("Green Tea", 5.00);
	}
	
	//get the drink selection, and return the cost of the drink
	private double selectDrink()
	{	
		//print menu
		System.out.println("====== Vending Machine ======");
		for(int i=0; i<drinks.length; i++)
		{
			System.out.printf("|%d. Buy %s ($%.2f)\n", i+1, drinks[i].getDrinkName(), drinks[i].getDrinkCost());
		}
		System.out.println("|============================");
		
		while(true)
		{	
			//get user's choice of drink
		    System.out.println("Please enter selection:");
			
			switch(sc.nextInt())
			{
				case 1: return drinks[0].getDrinkCost();
			 
				case 2: return drinks[1].getDrinkCost();
			 
				case 3: return drinks[2].getDrinkCost();
			}
		}
	}
	
	//insert the coins and returns the amount inserted
	private double insertCoins(double drinkCost)
	{
		double amountInserted = 0.0;
		
		//print the options of coins user can insert
		System.out.println("Please insert coins:");
	    System.out.println("========== Coins Input ===========");
	    System.out.println("Enter 'Q' for ten cents input    |");
	    System.out.println("Enter 'T' for twenty cents input |");
	    System.out.println("Enter 'F' for fifty cebts input  |");
	    System.out.println("Enter 'N' for a dollar input     |");
	    System.out.println("==================================");
	    
	    while(amountInserted < drinkCost)
	    {
	    	switch(sc.next().toLowerCase().charAt(0))
	    	{
				case 'q':	amountInserted += 0.1;
							break;
			
				case 't':	amountInserted += 0.2;
							break;
			
				case 'f':	amountInserted += 0.5;
							break;
			
				case 'n':	amountInserted += 1.0;
							break;
	    	}
	    	
	    	//print the amount inserted so far
			System.out.printf("Coins inserted: %.2f\n", amountInserted);
	    }
	    
	    return amountInserted;
	}
	
	//check the change and print the change on screen
	private void checkChange(double amount, double drinkCost)
	{
		//if no change, it will be 0.00
		System.out.printf("Change: $ %.2f\n", (amount - drinkCost));
	}
	
	//print the receipt and collect the drink
	private void printReceipt()
	{
		System.out.println("Please collect your drink \nThank You !!");
	}
	
	//to execute the content
	public void start()
	{
		//set run to true
		run = true;
		
		//keep running until stop button is pressed
		while(run)
		{
			//get user choice and drink cost
			drinkCost = selectDrink();
	    
			//prints the amount inserted and the change
			checkChange(insertCoins(drinkCost), drinkCost);
	    
			//exiting message
			printReceipt();
		}
	}
	
	//stop the vending machine
	public void stop()
	{
		run = false;
	}

}
