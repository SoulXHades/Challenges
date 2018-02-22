/*
A structure is defined to represent an arithmetic expression:

typedef struct {

        float operand1, operand2;

        char op;         // operator ‘+’,‘-’,‘*’ or ‘/’

} bexpression;

(a) Write a C function that computes the value of an expression and returns the result.
For example, the function will return the value of 4/2 if in the structure passed to it,
operand1 is 4, operator is ‘/’ and operand2 is 2. The function prototype is given as:

    float compute1(bexpression expr);

(b) Write another C function that performs the same computation with the following function prototype:

    float compute2(bexpression *expr);

Write a C program to test the functions.

Some sample input and output sessions are given below:

(1) Test Case 1:
Select one of the following options:
1: compute1()
2: compute2()
3: exit()
Enter your choice:
1
Enter expression (op1 op2 op) :
5 8 +
compute1(): 13.00

(2) Test Case 2:
Select one of the following options:
1: compute1()
2: compute2()
3: exit()
Enter your choice:
2
Enter expression (op1 op2 op) :
8 5 /
compute2(): 1.60

(3) Test Case 3:
Select one of the following options:
1: compute1()
2: compute2()
3: exit()
Enter your choice:
1
Enter expression (op1 op2 op) :
5 8 *
compute1(): 40.00

(4) Test Case 4:
Select one of the following options:
1: compute1()
2: compute2()
3: exit()
Enter your choice:
2
Enter expression (op1 op2 op) :
8 5 -
compute2(): 3.00
*/

#include <stdio.h>
typedef struct {
   float operand1, operand2;
   char op;
} bexpression;
float compute1(bexpression expr);
float compute2(bexpression *expr);
int main()
{
   bexpression e;
   int choice;

   printf("Select one of the following options: \n");
   printf("1: compute1()\n");
   printf("2: compute2()\n");
   printf("3: exit()\n");
   do {
      printf("Enter your choice: \n");
      scanf("%d", &choice);
      switch (choice) {
         case 1:
            printf("Enter expression (op1 op2 op): \n");
            scanf("%f %f %c", &e.operand1, &e.operand2, &e.op);
            printf("compute1(): %.2f\n", compute1(e));
            break;
         case 2:
            printf("Enter expression (op1 op2 op): \n");
            scanf("%f %f %c", &e.operand1, &e.operand2, &e.op);
            printf("compute2(): %.2f\n", compute2(&e));
            break;
      }
   } while (choice < 3);
   return 0;
}
float compute1(bexpression expr)
{
   switch(expr.op)
   {
    case '+':
        return expr.operand1 + expr.operand2;
    case '-':
        return expr.operand1 - expr.operand2;
    case '*':
        return expr.operand1 * expr.operand2;
    case '/':
        return expr.operand1 / expr.operand2;
    default:
        return 0;
   }
}
float compute2(bexpression *expr)
{
   switch(expr->op)
   {
    case '+':
        return expr->operand1 + expr->operand2;
    case '-':
        return expr->operand1 - expr->operand2;
    case '*':
        return expr->operand1 * expr->operand2;
    case '/':
        return expr->operand1 / expr->operand2;
    default:
        return 0;
   }
}
