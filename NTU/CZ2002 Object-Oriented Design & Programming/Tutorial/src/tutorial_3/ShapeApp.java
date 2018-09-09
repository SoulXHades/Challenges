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
