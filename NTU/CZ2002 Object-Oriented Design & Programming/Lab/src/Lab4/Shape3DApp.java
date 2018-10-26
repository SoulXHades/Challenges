package Lab4;

import java.util.Scanner;

public class Shape3DApp {

	public static void main(String[] args) {
		int numOfShapes;
		int choice=0;
		double length;
		double breadth;
		double height;
		int sh=1;
		int sbp=1;
		int cu=1;
		int con=1;
		int cyl=1;
		Scanner sc = new Scanner(System.in);
		
		//get the number of shapes to be created
		System.out.println("Enter the total number of shapes:");
		numOfShapes = sc.nextInt();
		
		//create a list of shapes
		Shape[] shapeList = new Shape[numOfShapes];
		
		//menu of what shapes to be created
		System.out.println("1. Sphere\n"
				+ "2. Square-based pyramid\n"
				+ "3. Cubiod\n"
				+ "4. Cone\n"
				+ "5. Cylinder");
		
		//creation input parameters prompt
		for(int i=0; i<numOfShapes; i++)
		{
			System.out.println("Input a choice:");
			
			switch(sc.nextInt())
			{
				case 1:
					System.out.println("Input the radius of the sphere:");
					shapeList[i] = new Sphere(sh, sc.nextDouble());
					System.out.println("Sphere" + sh + " has been created!");
					//increment for name of the next sphere created
					++sh;
					break;
				
				case 2:
					System.out.println("Input the length of base of square-based pyramid:");
					length = sc.nextDouble();
					System.out.println("Input the height of the square-based pyramid:");
					height = sc.nextDouble();
					shapeList[i] = new Pyramid(sbp, length, height);
					System.out.println("Square-based pyramid" + sbp + " has been created!");
					//increment for name of the next square-based pyramid created
					++sbp;
					break;
				
				case 3:
					System.out.println("Input the length of the cubiod:");
					length = sc.nextDouble();
					System.out.println("Input the breadth of the cubiod:");
					breadth = sc.nextDouble();
					System.out.println("Input the height of the cubiod:");
					height = sc.nextDouble();
					shapeList[i] = new Cubiod(cu, length, breadth, height);
					System.out.println("Cubiod" + cu + " has been created!");
					//increment for name of the next cubiod created
					++cu;
					break;
				
				case 4:
					System.out.println("Input the radius of the cone:");
					length = sc.nextDouble();
					System.out.println("Input the height of the cone:");
					height = sc.nextDouble();
					shapeList[i] = new Cone(con, length, height);
					System.out.println("Cone" + con + " has been created!");
					//increment for name of the next cone created
					++con;
					break;
				
				case 5:
					System.out.println("Input the radius of the cylinder:");
					length = sc.nextDouble();
					System.out.println("Input the height of the clinder:");
					height = sc.nextDouble();
					shapeList[i] = new Cylinder(cyl, length, height);
					System.out.println("Cylinder" + cyl + " has been created!");
					//increment for name of the next cylinder created
					++cyl;
					break;
			}
		}
		
		//menu for what result should be output
		for(int i=0; i<numOfShapes; i++)
		{
			System.out.println(i + ". Print area and volume of " + shapeList[i].getShapeType());
		}
		System.out.println("-1. Exit");
		
		
		//get choice and print output 
		do
		{
			System.out.println("Input a choice:");
			choice = sc.nextInt();
			
			//get out of the menu (loop)
			if(choice == -1)
				break;
			
			if(shapeList[choice] instanceof Sphere)
			{
				Sphere sp1 = (Sphere)shapeList[choice];
				
				System.out.printf(sp1.getShapeType() + " of radius %f area is %f\n", sp1.getRadius(), sp1.Area());
				System.out.printf(sp1.getShapeType() + " of radius %f volume is %f\n", sp1.getRadius(), sp1.Volume());
			}
			else if(shapeList[choice] instanceof Pyramid)
			{
				Pyramid py1 = (Pyramid)shapeList[choice];
				
				System.out.printf(py1.getShapeType() + " of base length %f and height %f area is %f\n", py1.getBase(), py1.getHeight(), py1.Area());
				System.out.printf(py1.getShapeType() + " of base length %f and height %f area is %f\n", py1.getBase(), py1.getHeight(), py1.Volume());
			}
			else if(shapeList[choice] instanceof Cubiod)
			{
				Cubiod cu1 = (Cubiod)shapeList[choice];
				
				System.out.printf(cu1.getShapeType() + " of length %f, breadth %f and height %f area is %f\n", cu1.getLength(), cu1.getBreadth(), cu1.getHeight(), cu1.Area());
				System.out.printf(cu1.getShapeType() + " of length %f, breadth %f and height %f area is %f\n", cu1.getLength(), cu1.getBreadth(), cu1.getHeight(), cu1.Volume());
			}
			else if(shapeList[choice] instanceof Cone)
			{
				Cone con1 = (Cone)shapeList[choice];
				
				System.out.printf(con1.getShapeType() + " of radius %f and height %f area is %f\n", con1.getRadius(), con1.getHeight(), con1.Area());
				System.out.printf(con1.getShapeType() + " of radius %f and height %f area is %f\n", con1.getRadius(), con1.getHeight(), con1.Volume());
			}
			else if(shapeList[choice] instanceof Cylinder)
			{
				Cylinder cyl1 = (Cylinder)shapeList[choice];
				
				System.out.printf(cyl1.getShapeType() + " of radius %f and height %f area is %f\n", cyl1.getRadius(), cyl1.getHeight(), cyl1.Area());
				System.out.printf(cyl1.getShapeType() + " of radius %f and height %f area is %f\n", cyl1.getRadius(), cyl1.getHeight(), cyl1.Volume());
			}
		}while(true);

	}

}
