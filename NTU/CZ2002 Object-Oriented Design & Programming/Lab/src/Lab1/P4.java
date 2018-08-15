/*
Write a program that reads the height from a user and prints a pattern with the specified height. 
For example, when the user enters height = 3, the following pattern is printed:

AA
BBAA
AABBAA

If the height is 7, then the following pattern is printed:

AA
BBAA
AABBAA
BBAABBAA
AABBAABBAA
BBAABBAABBAA
AABBAABBAABBAA

Important: Remember to name the source code of this program as P4.java and 
name the compiled class code as P4.class inside the sub-directory lab1.

Test cases: 0, 3, 7
Expected outputs: (1) height = 0 – Error input!! (2) height = 3 & (3) height = 7 – same as the sample patterns.
*/

package Lab1;

import java.util.*;

public class P4 {

	public static void main(String[] args) {
		//Create scanner object for console input
		Scanner sc = new Scanner(System.in);
		
		int height = 0;
		int i, j;
		
		//Loop to check for correct input
		while(true)
		{
			try
			{
				//Get user's salary
				System.out.print("Input the height: ");
				height = sc.nextInt();
			}
			catch(InputMismatchException e)
			{
				//Input user of wrong input
				System.out.println("Please input whole numbers only");
				//clear input buffer
				sc.nextLine();
				continue;
			}
			
			if(height < 1)
			{
				System.out.println("Error input!!");
				continue;
			}
					
			break;
		}
		
		sc.close();
		
		//Print pattern
		for(i = 0; i < height; i++)
		{
			//The max of j vector is the current position of i vector
			for(j = 0; j <= i; j++)
			{
				if(i % 2 == 0)
				{
					if(j % 2 == 0)
						System.out.print("AA");
					else
						System.out.print("BB");
				}
				else
				{
					if(j % 2 == 0)
						System.out.print("BB");
					else
						System.out.print("AA");
				}
			}
			
			//Move to next line
			System.out.println("");
		}

	}

}
