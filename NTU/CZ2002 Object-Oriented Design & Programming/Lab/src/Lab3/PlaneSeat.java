package Lab3;

public class PlaneSeat {
	//initialization
	private int seatId;
	private boolean assigned;
	private int customerId;
	
	//constructor
	public PlaneSeat(int seat_id)
	{
		this.seatId = seat_id;
		this.assigned = false;
		this.customerId = 0;
	}
	
	//accessors
	public int getSeatID()
	{
		return this.seatId;
	}
	
	public int getCustomerID()
	{
		return this.customerId;
	}
	
	public boolean isOccupied()
	{
		return this.assigned;
	}
	
	//mutators
	public void assign(int cust_id)
	{
		this.customerId = cust_id;
		this.assigned = true;
	}
	
	public void unAssign()
	{
		this.assigned = false;
		this.customerId = 0;
	}

}
