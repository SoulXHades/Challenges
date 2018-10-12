package tutorial_6;

//control in BoundaryControlEntity
public class Bank {
	//initialization
	private Check c = new Check();
	private CheckingAccount ca = new CheckingAccount();
	
	//method call from another class
	//cash a check control
	public float cashCheck(Object theCheck)
	{
		float amount =  c.getAmount();
		float balance = ca.getBalance();
		
		if(balance < amount)
		{
			ca.addInsuffientFundFee();
			ca.noteReturnedCheck(theCheck);
			returnCheck(theCheck);
			
			return -1;
		}
		
		int checkNumber = c.getCheckNo();
		
		ca.addDebitTransaction(checkNumber, amount);
		ca.storePhotoOfCheck(theCheck);
		
		return amount;
	}
	
	private void returnCheck(Object theCheck)
	{
		System.out.println("Returning the check");
	}

}
