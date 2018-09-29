package hashTest;

import java.util.LinkedList;

public class HashTable {
	//initialization
	public static final int ARR_SIZE = 7;
	private LinkedList<HTObject>[] arr = new LinkedList[ARR_SIZE];
	private static int numberOfKey = 0;
	private static int totalNumberOfCompare = 0;
	private static int totalNumOfSearch = 0;
	private static double totalTime = 0.0;

    public HashTable() { //constructor creates an array
        for(int i=0; i<ARR_SIZE; i++) {
            arr[i] = null;
        }
    }
    public void print() {
    	//initialization
    	LinkedList<HTObject> list;
    	HTObject node;
    	
    	//display HashTable column number and the content in the LL 
    	for(int i = 0; i < ARR_SIZE; i++) {
    		//display the HashTable column number
    		System.out.printf("Column %d: \n", i);
    		
    		//puts the address in the table into list variable
    		list = arr[i];
    		
    		//check if that section in the HashTable is empty
    		if(list == null)
    			continue;
    		
    		//print all contents in the linked list
    		for(int j = 0; j < list.size(); j++)
    		{
    			node = list.get(j);
    			System.out.println(node.value);
    		}
    		
    		//create extra new line
    		System.out.println();
    	}
    	
    	//create extra new line
		System.out.println();
    }

	public void put(int value) {
		//initialization
	    int index = value % ARR_SIZE; //hash function, choose which slot to put in
	    LinkedList<HTObject> list = arr[index];	//puts the address in the table into list variable
	    HTObject node = new HTObject(); //creating the Node
	    HTObject checkNode;
	    
	    node.value = value;	//add value
	    
	    
	    if(list == null) { //if in the slot(arr[index]), there is nothing(still null), create a new LL
	        list = new LinkedList<HTObject>();
	        list.add(node);  //add node to LL
	        numberOfKey++;
	    }
	    else {
	    	//run through the LL to search if key already exist
			for(int i = 0; i < list.size(); i++)
			{
				//get the object address in the LL node
				checkNode = list.get(i);
				
				//comparison to check for the key
				if(value == checkNode.value)
				{
					System.out.println("Key already exist!\n");
					return;
				}
			}
			
			//add value
	    	list.addLast(node);
	    	numberOfKey++;
	    }
	    
	    arr[index] = list; //update array
	    System.out.println("Successfully added a new key\n");
	    }
	
	public void search(int value)
	{
		//initialization
		LinkedList<HTObject> list;
		HTObject node;
		long startTime, endTime;
		totalNumOfSearch++;
		//position in the table after hashing
		int index = value % ARR_SIZE;
		
		//get the address of the LL from the column of the table
		list = arr[index];
		
		//check if that section in the HashTable is empty
		if(list == null)
		{
			System.out.printf("\nKey not found in HashTable column %d\n\n", index);
			return;
		}
		
		//get the starting time of CPU before searching begins
		startTime = System.nanoTime();
		
		//run through the LL to search for the key
		for(int i = 0; i < list.size(); i++)
		{
			//get the object address in the LL node
			node = list.get(i);
			
			//comparison to check for the key
			if(value == node.value)
			{
				//get the ending time of CPU after search completes
				endTime = System.nanoTime();
				
				System.out.printf("\nKey found in HashTable column %d with %d comparisons\n", index, i+1);
				totalNumberOfCompare += (i + 1);
				System.out.println("The total number of comparison is "+ totalNumberOfCompare);
				System.out.printf("CPU time taken to search = %d\n", (endTime - startTime));
				totalTime += (endTime-startTime);
				System.out.println("The total time now = " + totalTime + "\n");
				return;
			}
		}
		
		//get the ending time of CPU after search completes
		endTime = System.nanoTime();
		
		System.out.printf("\nKey not found in HashTable column %d\n", index);
		
		totalTime += (endTime-startTime);
		//no. of worst case comparison is size of LL
		totalNumberOfCompare += list.size();
		System.out.println("The total number of comparison is "+ totalNumberOfCompare);
		System.out.println("The total time now is " + totalTime);
		System.out.printf("CPU time taken to search = %d\n\n", (endTime - startTime));
		
	}
	
	public void avgCompare() {
		//if totalNumberOfCompare = 0 means no keys are yet searched
		double avg = (totalNumberOfCompare != 0) ? (totalNumberOfCompare/totalNumOfSearch) : 0;
		
		System.out.printf("The average number of key comparison for searching in hash table is %.3f for %d number of key\n\n", avg , numberOfKey);
	}
	public void avgTime() {
		//if totalTime = 0 means no keys are yet searched
		double avgCPUTime = (totalTime != 0) ? totalTime/totalNumOfSearch : 0;
		
		System.out.printf("The average CPU time to search is %.2fns for %d of searches in %d number of keys\n\n", avgCPUTime,totalNumOfSearch,numberOfKey);
	}
	
}
