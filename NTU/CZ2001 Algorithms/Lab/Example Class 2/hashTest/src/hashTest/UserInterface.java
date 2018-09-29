package hashTest;

import java.util.*;

public class UserInterface {
	Scanner sc = new Scanner(System.in);
	
	public int addKey()
	{
		System.out.println("Add new key (-1 to quit):");
		
		return sc.nextInt();
	}
	
	public int mainMenu()
	{
		System.out.println("1. Add key to HashTable");
		System.out.println("2. Print all keys in HashTable");
		System.out.println("3. Search for key in HashTable");
		System.out.println("4. Output average CPU time");
		System.out.println("5. Output average number of key comparison");
		System.out.println("6. Exit");
		System.out.println("Input your choice");
		
		return sc.nextInt();
	}
	
	public int searchKey()
	{
		System.out.println("Enter key to be searched:");
		
		return sc.nextInt();
	}

}
