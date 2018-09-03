/*
Write a class Circle that has the following instance variables and methods:

public class Circle
{
private double radius; // radius of circle
private static final double PI = 3.14159;
// constructor
public Circle(double rad) {...}
// mutator method – set radius
public void setRadius(double rad){...}
// accessor method – get radius
public double getRadius(){...}
// calculate area
public double area(){...}
// calculate circumference
public double circumference() {...}
// print area
public void printArea(){...}
// print circumference
public void printCircumference(){...}
}


The UML class diagram for the Circle class is given below:

Circle
- radius: double
+ Circle(rad: double)
+ setRadius (rad: double): void
+ getRadius(): double
+ area(): double
+ circumference(): double
+ printArea(): void
+ printCircumference(): void


Write an application class CircleApp to test the Circle class. 
The class CircleApp should display a menu. 
The user can then select an option of the following: 
(1) create a new circle; (2) print area; (3) print circumference; and (4) quit. 
Implement the operations for each option.

A sample program run is given below:

----jGRASP exec: java CircleApp

==== Circle Computation =====
|1. Create a new circle |
|2. Print Area |
|3. Print circumference |
|4. Quit |
=============================
Choose option (1-3):
1
Enter the radius to compute the area and circumference
5
A new circle is created
Choose option (1-3):
2
Area of circle
Radius: 5.0
Area: 78.53975
Choose option (1-3):
3
Circumference of circle
Radius: 5.0
Circumference: 31.4159
Choose option (1-3):
4
Thank you!!
*/

package tutorial_2;

import java.util.*;

public class CircleApp {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Circle circle1 = new Circle(0);
		
		double rad;
		int choice = 0;
		
		System.out.println("==== Circle Computation =====");
		System.out.println("|1. Create a new circle     |");
		System.out.println("|2. Print Area              |");
		System.out.println("|3. Print circumference     |");
		System.out.println("|4. Quit                    |");
		System.out.println("=============================");
		
		do
		{
			System.out.println("Choose option (1-3):");
			choice = sc.nextInt();
			
			switch(choice)
			{
				case 1: //Get radius to create a new circle
						System.out.println("Enter the radius to compute the area and circumference");
						rad = sc.nextDouble();
						circle1.setRadius(rad);
						System.out.println("A new circle is created");
						break;
				
				case 2: circle1.printArea();
						break;
				
				case 3: circle1.printCircumference();
						break;
				
				case 4: System.out.println("Thank you!!");
						break;
			}
			
		}while(choice != 4);
		
		sc.close();

	}

}
