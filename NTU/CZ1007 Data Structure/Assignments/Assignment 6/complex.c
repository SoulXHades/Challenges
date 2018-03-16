/*
A structure called complex is defined to represent a complex number.
Each complex number consists of the real and imaginary parts as follows:

typedef struct {
   double real;
   double imag;
} Complex;

Write C functions that perform addition, subtraction,
multiplication and division operations on two complex numbers.
The function prototypes are given as follows:

    Complex add(Complex c1, Complex c2);
    Complex mul(Complex c1, Complex c2);
    Complex sub(Complex *c1, Complex *c2);
    Complex div(Complex *c1, Complex *c2);

Write a C program that handles complex number arithmetic using the arithmetic functions implemented.
The program will read the choice of operation (e.g. addition, subtraction, multiplication, division and quit)
and two complex numbers, and display the result.

Some test input and output sessions are given below:

(1) Test Case 1:
Complex number operations:
1 - addition
2 - subtraction
3 - multiplication
4 - division
5 - quit
Enter your choice:
1
Enter complex number 1:
1 1
Enter complex number 2:
2 2
complex(): real 3.00 imag 3.00
Enter your choice:
5

(2) Test Case 2:
Complex number operations:
1 - addition
2 - subtraction
3 - multiplication
4 - division
5 - quit
Enter your choice:
2
Enter complex number 1:
3 3
Enter complex number 2:
2 2
complex(): real 1.00 imag 1.00
Enter your choice:
5

(3) Test Case 3:
Complex number operations:
1 - addition
2 - subtraction
3 - multiplication
4 - division
5 - quit
Enter your choice:
3
Enter complex number 1:
3 3
Enter complex number 2:
4 6
complex(): real -6.00 imag 30.00
Enter your choice:
5

(4) Test Case 4:
Complex number operations:
1 - addition
2 - subtraction
3 - multiplication
4 - division
5 - quit
Enter your choice:
4
Enter complex number 1:
1 1
Enter complex number 2:
2 2
complex(): real 0.50 imag 0.00
Enter your choice:
5
*/

#include <stdio.h>
#include <math.h>
typedef struct {
   double real;
   double imag;
} Complex;
Complex add(Complex c1, Complex c2);
Complex mul(Complex c1, Complex c2);
Complex sub(Complex *c1, Complex *c2);
Complex div(Complex *c1, Complex *c2);
int main()
{
   int choice;
   Complex input1, input2, result;

   printf("Complex number operations: \n");
   printf("1 - addition \n");
   printf("2 - subtraction \n");
   printf("3 - multiplication \n");
   printf("4 - division \n");
   printf("5 - quit \n");
   do {
      printf("Enter your choice: \n");
      scanf("%d", &choice);
      if (choice == 5)
         return 0;
      printf("Enter Complex Number 1: \n");
      scanf("%lf %lf", &input1.real, &input1.imag);
      printf("Enter Complex Number 2: \n");
      scanf("%lf %lf", &input2.real, &input2.imag);
      switch (choice) {
         case 1: result = add(input1, input2);
            break;
         case 2: result = sub(&input1, &input2);
            break;
         case 3: result = mul(input1, input2);
            break;
         case 4: result = div(&input1, &input2);
            break;
      }
      printf("complex(): real %.2f imag %.2f\n",
             result.real, result.imag);
   } while (choice<5);
   return 0;
}
Complex add(Complex c1, Complex c2)
{
    c1.real += c2.real;
    c1.imag += c2.imag;

    return c1;
}
Complex sub(Complex *c1, Complex *c2)
{
    Complex c3;

    c3.real = c1->real - c2->real;
    c3.imag = c1->imag - c2->imag;

    return c3;
}
Complex mul(Complex c1, Complex c2)
{
    Complex c3;

    c3.real = (c1.real * c2.real) - (c1.imag * c2.imag);
    c3.imag = (c1.real * c2.imag) + (c1.imag * c2.real);

    return c3;
}
Complex div(Complex *c1, Complex *c2)
{
    Complex c3;

    c3.real = ((c1->real * c2->real) + (c1->imag * c2->imag)) / (pow(c2->real, 2) + pow(c2->imag, 2));
    c3.imag = -1 * (((c1->real * c2->imag) - (c1->imag * c2->real)) / (pow(c2->real, 2) + pow(c2->imag, 2)));

    if(c3.imag == 0)
        c3.imag = 0;

    return c3;
}
