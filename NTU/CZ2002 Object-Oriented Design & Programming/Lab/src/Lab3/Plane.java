package Lab3;

public class Plane {
	//initialization
	private PlaneSeat[] seat;
	private int numEmptySeat;
	private static final int numOfSeats = 12;
	
	//constructors
	public Plane()
	{
		//assign 12 seats to a plane
		this.seat = new PlaneSeat[numOfSeats];
		//set the number of empty seats equals to the number of seats assigned to a plane
		this.numEmptySeat = numOfSeats;
		
		//initialize each seats
		for(int i=0; i<numOfSeats; i++)
		{
			//initialize and assign seat id
			this.seat[i] = new PlaneSeat(i+1);
		}
	}
	
	//to sort the seats according to ascending order of customerID
	//a copy of the original seat array is used for sorting instead of the original
	private PlaneSeat[] sortSeats()
	{
		PlaneSeat[] tempSeat = new PlaneSeat[12];
		PlaneSeat tempSeat1;
		
		//copy the content of the original Seat to tempSeat
		for(int i=0; i<numOfSeats; i++)
		{
			//copy key (address)
			tempSeat[i] = seat[i];
		}
		
		//sort them by customer id in ascending order using insertion sort algorithm
		for(int i=1; i<numOfSeats; i++)
		{
			for(int j=i; j>0; j--)
			{
				if(tempSeat[j].getCustomerID() < tempSeat[j-1].getCustomerID())
				{
					//swap the elements to left is smaller than right
					tempSeat1 = tempSeat[j];
					tempSeat[j] = tempSeat[j-1];
					tempSeat[j-1] = tempSeat1;
				}
				else
					break;
			}
		}
		
		return tempSeat;
	}
	
	//display the number of empty seats
	public void showNumEmptySeats()
	{	
		//display result
		System.out.printf("There are %d empty seats\n", this.numEmptySeat);
	}
	
	//to display the list of empty seats
	public void showEmptySeats()
	{
		System.out.println("The following seats are empty:");
		
		for(int i=0; i<numOfSeats; i++)
		{
			//NOT the result as if is occupied, it will result true
			if(!this.seat[i].isOccupied())
				System.out.printf("SeatID %d\n", i+1);
		}
	}
	
	//to display the assigned seats with seat ID and customer ID
	public void showAssignedSeats(boolean bySeatId)
	{
		//If bySeatId is  true,  the  order  will  be  by  seatID,  else  order  is  by customerID
		PlaneSeat[] tempPlaneSeat = bySeatId ? this.seat : sortSeats();
		
		//display results
		for(int i=0; i<numOfSeats; i++)
		{
			//only print those that are occupied
			if(tempPlaneSeat[i].isOccupied())
				System.out.printf("SeatID %d assigned to CustomerID %d.\n", tempPlaneSeat[i].getSeatID(), tempPlaneSeat[i].getCustomerID());
		}
	}
	
	//assigns a customer ID to an empty seat 
	public void assignSeat(int seatId, int cust_id)
	{
		//check if it's occupied
		if(this.seat[seatId-1].isOccupied())
			System.out.println("Seat already assigned to a customer.");
		else
		{
			//assign customer to seat if seat is not occupied
			this.seat[seatId-1].assign(cust_id);
			//reduce the number of empty seats
			--this.numEmptySeat;
			
			System.out.println("Seat Assigned!");
		}
	}
	
	//unassigns a seat
	public void unAssignSeat(int seatId)
	{
		//check if the seat is already occupied before unassigning
		if(this.seat[seatId-1].isOccupied())
		{
			//unassigns a seat
			this.seat[seatId-1].unAssign();
			//increase the number of empty seats
			++this.numEmptySeat;
		}
		
		System.out.println("Seat Unassigned!");
	}

}
