/*
Write a class Dice that has the following instance variables and methods:

The UML class diagram for the Dice class is given below:
Dice
- valueOfDice: int
+ Dice()
+ setDiceValue(): void
+ getDiceValue(): int
+ printDiveValue (): void


Write an application class DiceApp to test the class Dice. 
The class DiceApp interacts with the user to generate the numbers randomly from rolling a pair of dices.
The generated numbers from the pair of dices and the total are then displayed on the screen.


A sample program run is given below:

----jGRASP exec: java DiceApp

Press <key> to roll the first dice
1
Current Value is 3
Press <key> to roll second dice
2
Current Value is 3
Your total number is: 6
*/

package tutorial_2;

import java.util.*;

public class DiceApp {

	public static void main(String[] args) {
		//initialize
		Scanner sc = new Scanner(System.in);
		Dice dice1 = new Dice();
		Dice dice2 = new Dice();
		
		//start on 1st dice
		System.out.println("Press 1 to roll the first dice");
		sc.next();
		dice1.setDiceValue();
		dice1.printDiceValue();
		
		//start on 2nd dice
		System.out.println("Press 2 to roll the second dice");
		sc.next();
		dice2.setDiceValue();
		dice2.printDiceValue();
		
		//print the total
		System.out.println("Your total number is: " + (dice1.getDiceValue() + dice2.getDiceValue()));
		
		sc.close();

	}

}
