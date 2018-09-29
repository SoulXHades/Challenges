package hashTest;

public class Hash {

	public static void main(String[] args) {
		HashTable h1 = new HashTable();
		UserInterface u1 = new UserInterface();
		int tempKey;
		
		while(true)
		{
			switch(u1.mainMenu())
			{
				//add new key into HashTable
				case 1:	while(true)
						{
							tempKey = u1.addKey();
							
							if(tempKey == -1)
								break;
							
							h1.put(tempKey);
						}
						break;
			
				//print all keys in HashTable
				case 2:	h1.print();
						break;
				
				//search for key in HashTable
				case 3:	h1.search(u1.searchKey());
						break;
				
				case 4: h1.avgTime();
						break;
		
				case 5: h1.avgCompare();
						break;
		
				//exit program
				case 6: System.exit(0);
						break;
			}
		}

	}

}
