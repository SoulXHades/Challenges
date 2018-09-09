package tutorial_3;

import java.util.*;

public class VendingMachine {
	Scanner sc = new Scanner(System.in);
	
	//constructor
	public VendingMachine()	{}
	
	//get the drink selection, and return the cost of the drink
	public double selectDrink()
	{
		switch(sc.nextInt())
		{
			 case 1: return 3.00;
			 
			 case 2: return 1.00;
			 
			 case 3: return 5.00;
			 
			 default: return 0.0;
		}
	}
	
	//insert the coins and returns the amount inserted
	public double insertCoins(double drinkCost)
	{
		switch(sc.next().toLowerCase().charAt(0))
		{
			case 'q': return 0.1;
			
			case 't': return 0.2;
			
			case 'f': return 0.5;
			
			case 'n': return 1.0;
			
			default: return 0.0;
		}
	}
	
	//check the change and print the change on screen
	public void checkChange(double amount, double drinkCost)
	{
		//print the amount inserted so far
		System.out.printf("Coins inserted: %.2f\n", amount);
		
		if(amount >= drinkCost)
			System.out.printf("Change: $ %.2f\n", (amount - drinkCost));	//if no change, it will be 0.00
	}
	
	//print the receipt and collect the drink
	public void printReceipt()
	{
		System.out.println("Please collect your drink \nThank You !!");
	}

}
