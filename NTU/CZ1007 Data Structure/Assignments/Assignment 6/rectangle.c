/*
A structure called Point is defined to represent a point in 2D which is given as follows:

typedef struct {
   double x;
   double y;
} Point;

Another structure called Rectangle is defined as follows:

typedef struct {
   Point topLeft;    // top left point of rectangle
   Point botRight;   // bottom right point of rectangle
} Rectangle;

Write a C program that reads in the top left point and bottom right point of a rectangle,
computes the area of the rectangle and prints the area of the rectangle on the screen.
Your program should include the following three functions with prototypes:

(1)     Rectangle getRect();                       // read in the two points of rectangle

(2)     void printRect(Rectangle r);  // print the coordinates of two points of rectangle

(3)     double findArea(Rectangle r);// return the area of rectangle

Some test input and output sessions are given below:

(1) Test Case 1:
Select one of the following options:
1:  getRect()
2:  findArea()
3:  printRect()
4:  exit()
Enter your choice:
1
getRect():
Enter top left point:
1 2
Enter bottom right point:
2 1
Enter your choice:
3
printRect():
Top left point: 1.00 2.00
Bottom right point: 2.00 1.00
Enter your choice:
4

(2) Test Case 2:
Select one of the following options:
1:  getRect()
2:  findArea()
3:  printRect()
4:  exit()
Enter your choice:
1
getRect():
Enter top left point:
1 2
Enter bottom right point:
2 1
Enter your choice:
2
findArea(): 1.00
Enter your choice:
4

(3) Test Case 3:
Select one of the following options:
1:  getRect()
2:  findArea()
3:  printRect()
4:  exit()
Enter your choice:
1
getRect():
Enter top left point:
1 5
Enter bottom right point:
5 5
Enter your choice:
2
findArea(): 0.00
Enter your choice:
4

(4) Test Case 4:
Select one of the following options:
1:  getRect()
2:  findArea()
3:  printRect()
4:  exit()
Enter your choice:
1
getRect():
Enter top left point:
1 5
Enter bottom right point:
2 8
Enter your choice:
3
printRect():
Top left point: 1.00 5.00
Bottom right point: 2.00 8.00
Enter your choice:
2
findArea(): 3.00
Enter your choice:
4
*/

#include <stdio.h>
#include <math.h>
typedef struct {
   double x;
   double y;
} Point;
typedef struct {
   Point topLeft;    /* top left point of rectangle */
   Point botRight;   /* bottom right point of rectangle */
} Rectangle;
Rectangle getRect();
void printRect(Rectangle r);
double findArea(Rectangle r);
int main()
{
   Rectangle r;
   int choice;

   printf("Select one of the following options:\n");
   printf("1: getRect()\n");
   printf("2: findArea()\n");
   printf("3: printRect()\n");
   printf("4: exit()\n");
   do {
      printf("Enter your choice: \n");
      scanf("%d", &choice);
      switch (choice) {
         case 1:
            printf("getRect(): \n");
            r = getRect();
            break;
         case 2:
            printf("findArea(): %.2f\n", findArea(r));
            break;
         case 3:
            printf("printRect(): \n");
            printRect(r);
            break;
         default:
            break;
      }
   } while (choice < 4);
   return 0;
}
Rectangle getRect()
{
    Rectangle r;

    printf("Enter top left point:\n");
    scanf("%lf %lf", &r.topLeft.x, &r.topLeft.y);
    printf("Enter bottom right point:\n");
    scanf("%lf %lf", &r.botRight.x, &r.botRight.y);

    return r;
}
void printRect(Rectangle r)
{
    printf("Top left point: %.2lf %.2lf\n", r.topLeft.x, r.topLeft.y);
    printf("Bottom right point: %.2lf %.2lf\n", r.botRight.x, r.botRight.y);
}
double findArea(Rectangle r)
{
    return fabs((r.botRight.x - r.topLeft.x) * (r.topLeft.y - r.botRight.y));
}
