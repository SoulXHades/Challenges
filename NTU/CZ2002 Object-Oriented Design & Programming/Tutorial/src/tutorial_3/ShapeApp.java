/*
You are given the class diagram for the Point class :

Point
#x: int
#y: int
+Point(x: int, y: int)
+toString(): String
+setpoint(x: int, y: int)
+getX(): int
+getY(): int


The toString() method will return the x and y value in the format “[ x, y ]”.

Write the code in Java.
Create a class Circle to inherit from the Point class. The Circle class is to have
the following methods: setRadius, getRadius and area. Reuse whatever
you can from the Point class.

Create a class Cylinder to inherit from the any of the classes above. The
Cylinder class is to have the following methods: setHeight, getRadius,
getHeight, area and volume.

Draw the class hierarchy. Create and use instances of a circle and a cylinder to
test classes you have created. Do you think that it was a good choice to use
Point as the base class? Suggest alternatives.
*/

package tutorial_3;

import java.util.*;

public class ShapeApp {

	public static void main(String[] args) {
		//initialization
		Circle circle1 = new Circle();
		Cylinder cylinder1 = new Cylinder();
		
		Scanner sc = new Scanner(System.in);
		
		System.out.println("Input radius of circle:");
		circle1.setRadius(sc.nextDouble());
		
		System.out.println("Radius of the circle: " + circle1.getRadius());
		System.out.println("Area of the circle: " + circle1.area());
		
		System.out.println("Input radius of cylinder:");
		cylinder1.setRadius(sc.nextDouble());
		System.out.println("Input height of cylinder:");
		cylinder1.setHeight(sc.nextDouble());
		
		System.out.println("Radius of the cylinder: " + cylinder1.getRadius());
		System.out.println("Area of the cylinder: " + cylinder1.area());
		System.out.println("Volume of the cylinder: " + cylinder1.volume());
		
		sc.close();

	}

}
