/*
Write a program that reads a character from the user and 
then uses a switch statement to achieve what the following IF statement does.

if ((choice == ‘A’) || (choice == ‘a’))
	printf(“Action movie fan\n”);
else if ((choice == ‘C’) || (choice == ‘c’))
	printf(“Comedy movie fan\n”);
else if ((choice == ‘D’) || (choice == ‘d’))
	printf(“Drama movie fan\n”);
else
	printf(“Invalid choice\n”);

Important: Remember to name the source code of this program as P1.java and 
name the compiled class code as P1.class inside the sub-directory lab1.

Test cases: ‘a’, ‘A’, ‘c’, ‘C’, ‘d’, ‘D’, ‘b’, ‘B’.
Expected outputs: ‘a’, ‘A’ – Action movie fan; ‘c’, ‘C’ – Comedy movie fan; 
‘d’, ‘D’ – Drama movie fan; ‘b’, ‘B’ – Invalid choice.
*/

package Lab1;

import java.util.Scanner;

public class P1 {

	public static void main(String[] args) {
		//Create scanner object for user input
		Scanner sc = new Scanner(System.in);
		
		//List menu
		System.out.println("A. Action movie \nC. Comedy movie \nD. Drama movie");
		System.out.print("Input your choice: ");
		//Get user's input
		char choice = sc.next().charAt(0);
		
		sc.close();
		
		//Output result depending on choice
		switch(choice)
		{
			case 'A':
			case 'a':
				System.out.printf("Action movie fan\n");
				break;
			
			case 'C':
			case 'c':
				System.out.printf("Comedy movie fan\n");
				break;
			
			case 'D':
			case 'd':
				System.out.printf("Drama movie fan\n");
				break;
			
			default:
				System.out.printf("Invalid choice\n");
		}

	}

}
