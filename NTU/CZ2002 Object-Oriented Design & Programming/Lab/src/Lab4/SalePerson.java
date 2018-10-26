package Lab4;

public class SalePerson implements Comparable<Object>{
	private String firstName;
	private String lastName;
	private int totalSales;
	
	public SalePerson(String fName, String lName, int tSales)
	{
		this.firstName = fName;
		this.lastName = lName;
		this.totalSales = tSales;
	}
	
	//return in "<lastName> , <firstName> : <totalSales>" format
	public String toString()
	{
		return lastName + " , " + firstName + " : " + totalSales;
	}
	
	//heck whether the first and last names of Object are the same as the current sale person
	public boolean equals(Object o)
	{
		//check if object can be downcasted
		if(o instanceof SalePerson)
		{
			SalePerson sp = (SalePerson) o;
			
			//return true if they have the same first name and last name
			if(firstName == sp.getFirstName() && lastName == sp.getLastName())
				return true;
		}
		
		return false;
	}
	
	//compare which totalSales is larger
	//use last name to break tie results of totalSales
	public int compareTo(Object o)
	{
		//check if object can be downcasted
		if(o instanceof SalePerson)
		{
			SalePerson sp = (SalePerson) o;
			
			//check if it's a tie
			if((totalSales - sp.getTotalSales()) == 0)
				return sp.getLastName().compareTo(lastName);	//in ascending alphabetical order using String's own compareTo()
			else
				return totalSales - sp.getTotalSales();
		}
		
		//when o is not an instance of SalePerson
		return -1;
	}
	
	public String getFirstName()
	{
		return this.firstName;
	}
	
	public String getLastName()
	{
		return this.lastName;
	}
	
	public int getTotalSales()
	{
		return this.totalSales;
	}

}
