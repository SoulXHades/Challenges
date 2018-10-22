package tutorial_6;

//control in BoundaryControlEntity
public class Bank {
	//declaration
	//no need to initialize as it should be in constructor
	private CheckingAccount ca;
	
	//method call from another class
	//cash a check control
	public float cashCheck(Check theCheck)
	{
		float amount =  theCheck.getAmount();
		float balance = ca.getBalance();
		
		if(balance < amount)
		{
			ca.addInsuffientFundFee();
			ca.noteReturnedCheck(theCheck);
			returnCheck(theCheck);
			
			return -1;
		}
		
		int checkNumber = theCheck.getCheckNo();
		
		ca.addDebitTransaction(checkNumber, amount);
		ca.storePhotoOfCheck(theCheck);
		
		return amount;
	}
	
	private void returnCheck(Check theCheck)
	{
		System.out.println("Returning the check");
	}

}
