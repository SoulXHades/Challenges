package tutorial_3;

public class VendingMachineApp {

	public static void main(String[] args) {
		double drinkCost, amountInserted = 0.0;
		
		VendingMachine vm1 = new VendingMachine();
		
		//print menu
		System.out.println("====== Vending Machine ======");
		System.out.println("|1. Buy Beer ($3.00)        |");
		System.out.println("|2. Buy Coke ($1.00)        |");
		System.out.println("|3. Buy Green Tea ($5.00)   |");
		System.out.println("|============================");
		
		//get user's choice of drink and return the cost
	    System.out.println("Please enter selection:");
	    drinkCost = vm1.selectDrink();
	    
	    System.out.println("Please insert coins:");
	    System.out.println("========== Coins Input ===========");
	    System.out.println("Enter 'Q' for ten cents input    |");
	    System.out.println("Enter 'T' for twenty cents input |");
	    System.out.println("Enter 'F' for fifty cebts input  |");
	    System.out.println("Enter 'N' for a dollar input     |");
	    System.out.println("==================================");
	    
	    //loop until user fully pays the cost of the drink
	    while(amountInserted < drinkCost)
	    {
	    	//get money from user
	    	amountInserted += vm1.insertCoins(drinkCost);
	    	
	    	//prints the amount inserted and the change
		    vm1.checkChange(amountInserted, drinkCost);
	    }
	    
	    //exiting message
	    vm1.printReceipt();

	}

}
