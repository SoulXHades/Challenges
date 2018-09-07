/*
Write a program to generate tables of currency conversions from Singapore dollars to US dollars. 
Use title and column headings. Assume the following conversion rate:

1 US dollar(US$) = 1.82 Singapore dollars (S$)

Allow the user to enter the starting value, ending value and the increment between lines in S$. 
The starting value, ending value and the increment are all integer values. 
Generate three output tables using the following loops with the same input data from the user:

1. Use a for loop to generate the first table;
2. Use a while loop to generate the second table; and
3. Use a do/while loop to generate the third table.

Place all the codes in the main() method.

Important: Remember to name the source code of this program as P3.java and 
name the compiled class code as P3.class inside the sub-directory lab1.

Test cases: (1) starting : 1, ending : 5, increment : 1; (2) starting : 0, ending : 40, increment: 5; 
(3) starting : 40, ending : 0, increment: 5 (treat this case as an error).

Expected outputs: 
(1) starting : 1, ending : 5, increment : 1;
US$ S$
--------------
1 1.82
2 3.64
3 5.46
4 7.28
5 9.1

(2) starting : 0, ending : 40, increment: 5;
 US$ S$
 --------------
 0 0.0
 5 9.1
 10 18.2
 
(3) starting : 40, ending : 0, increment: 5 (treat this case as an error) – Error input!!
*/

package Lab1;

import java.util.*;

public class P3 {

	public static void main(String[] args) {
		//Create Scanner object
		Scanner sc = new Scanner(System.in);
		
		//Initialize
		int start = 0;
		int end = 0;
		int increment= 0;
		int i;
		String spaceNeeded = "            ";
		
		//Loop to check for correct input
		while(true)
		{
			try
			{
				//Get user's salary
				System.out.print("Input the starting US$: ");
				start = sc.nextInt();
			}
			catch(InputMismatchException e)
			{
				//Input user of wrong input
				System.out.println("Please input whole numbers only");
				//clear input buffer
				sc.nextLine();
				continue;
			}
			
			break;
		}
		
		//Loop to check for correct input
		while(true)
		{
			try
			{
				//Get starting value
				System.out.print("Input the ending US$: ");
				end = sc.nextInt();
			}
			catch(InputMismatchException e)
			{
				//Input user of wrong input
				System.out.println("Please input whole numbers only");
				//clear input buffer
				sc.nextLine();
				continue;
			}
			
			//Check if ending value is lower than starting value
			if(end < start)
			{
				System.out.println("Error input!!");
				continue;
			}
			
			break;
		}
		
		//Loop to check for correct input
		while(true)
		{
			try
			{
				//Get the ending value
				System.out.print("Input the increment: ");
				increment = sc.nextInt();
			}
			catch(InputMismatchException e)
			{
				//Input user of wrong input
				System.out.println("Please input whole numbers only");
				//clear input buffer
				sc.nextLine();
				continue;
			}
			
			sc.close();
			
			break;
		}
		
		//Print table headings
		System.out.println("US$         S$");
		System.out.println("--------------");
		
		//Using FOR loop to display result
		for(i = start; i <= end; i += increment)
		{
			//For US$
			System.out.printf("%d", i);
			
			//Displaying number of spaces before S$ depending on length of US$
			System.out.print(spaceNeeded.substring(0, spaceNeeded.length() - Integer.toString(i).length()));
			
			//For S$
			//Rounding off to 2dp and removing 0s at the back in the decimal area
			System.out.printf(Float.toString(Math.round(i*1.82f*100)/100.0f) + "\n");
		}
		
		
		//Set counter to start's value for WHILE loop
		i = start;
		
		//Print table headings
		System.out.println("\nUS$         S$");
		System.out.println("--------------");
		
		//Using WHILE loop to display result
		while(i <= end)
		{
			//For US$
			System.out.printf("%d", i);
			
			//Displaying number of spaces before S$ depending on length of US$
			System.out.print(spaceNeeded.substring(0, spaceNeeded.length() - Integer.toString(i).length()));
			
			//For S$
			//Rounding off to 2dp and removing 0s at the back in the decimal area
			System.out.printf(Float.toString(Math.round(i*1.82f*100)/100.0f) + "\n");
			
			i += increment;
		}
		
		
		//Set counter to start's value for WHILE loop
		i = start;
				
		//Print table headings
		System.out.println("\nUS$         S$");
		System.out.println("--------------");
		
		//Using DO WHILE loop to display result
		do
		{
			//For US$
			System.out.printf("%d", i);
			
			//Displaying number of spaces before S$ depending on length of US$
			System.out.print(spaceNeeded.substring(0, spaceNeeded.length() - Integer.toString(i).length()));
			
			//For S$
			//Rounding off to 2dp and removing 0s at the back in the decimal area
			System.out.printf(Float.toString(Math.round(i*1.82f*100)/100.0f) + "\n");
			
			i += increment;
		}while(i <= end);

	}

}
