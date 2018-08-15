/*
The salary scheme for a company is given as follows:
Salary range for grade A: $700 - $899
Salary range for grade B: $600 - $799
Salary range for grade C: $500 - $649

A person whose salary is between $600 and $649 is in grade C if his merit points are below 10,
otherwise he is in grade B. A person whose salary is between $700 and $799 is in grade B if his merit
points are below 20, otherwise, he is in grade A. 

Write a program to read in a person’s salary and his merit points, and displays his grade.
Important: Remember to name the source code of this program as P2.java and 
name the compiled class code as P2.class inside the sub-directory lab1.

Test cases: (1) salary : $500, merit : 10; (2) salaray : $610, merit : 5; (3) salary : $610, merit : 10; 
(4) salary : $710, merit : 15; (5) salary : $710, merit : 20; (6) salary : 800, merit : 30.
Expected outputs: (1) salary : $500, merit : 10 – Grade C; (2) salaray : $610, merit : 5 – Grade C; 
(3) salary : $610, merit : 10 – Grade B; (4) salary : $710, merit : 15 – Grade B; (5) salary : $710, merit :
20 – Grade A; (6) salary : 800, merit : 30 – Grade A. 
*/

package Lab1;

import java.util.*;

public class P2 {

	public static void main(String[] args) {
		//Create scanner object
		Scanner sc = new Scanner(System.in);
		
		//Initialize
		int salary = 0;
		int meritPoints = 0;
		
		//Loop to check for correct input
		while(true)
		{
			try
			{
				//Get user's salary
				System.out.print("Input your salary without $: ");
				salary = sc.nextInt();
			}
			catch(InputMismatchException e)
			{
				//Input user of wrong input
				System.out.println("Please input whole numbers only");
				//clear input buffer
				sc.nextLine();
				continue;
			}
			
			//Check range
			if(salary < 500 || salary > 899)
			{
				System.out.println("Please input salary between $500 to $899");
				continue;
			}
			
			//Exit loop if user gives correct input
			break;
		}
		
		//Loop to check for correct input
		while(true)
		{
			try
			{
				//Get user's salary
				System.out.print("Input your merit points: ");
				meritPoints = sc.nextInt();
			}
			catch(Exception e)
			{
				//Input user of wrong input
				System.out.println("Please input whole numbers only");
				continue;
			}
			
			sc.close();
					
			//Exit loop if user gives correct input
			break;
		}
		
		//Output results
		switch(salary/100)
		{
			case 5:
				System.out.println("Your salary is in grade C");
				break;
			
			case 6:
				if(meritPoints < 10 && salary < 650)
					System.out.println("Your salary is in grade C");
				else
					System.out.println("Your salary is in grade B");
				break;
				
			default:
				if(meritPoints < 20 && salary < 800)
					System.out.println("Your salary is in grade B");
				else
					System.out.println("Your salary is in grade A");
		}

	}

}
