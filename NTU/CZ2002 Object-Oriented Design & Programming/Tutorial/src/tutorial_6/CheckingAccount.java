package tutorial_6;

//entity of BoundaryControlEntity
public class CheckingAccount {
	//initialization
	private float balance;
	private float totalInsufficientFund;
	private final float insufficientFundFee = 35f;
	
	//return bank account's balance 
	protected float getBalance()
	{
		return this.balance;
	}
	
	//impose penalty fee on check's owner for insufficient fund
	protected void addInsuffientFundFee()
	{
		totalInsufficientFund += insufficientFundFee;
	}
	
	protected void noteReturnedCheck(Object theCheck)
	{
		//***record returned of check***
	}
	
	protected void addDebitTransaction(int checkNumber, float amount)
	{
		this.balance -= amount;
		//***add to transaction history***
	}
	
	protected void storePhotoOfCheck(Object theCheck)
	{
		//***store a photocopy of the check***
	}

}
