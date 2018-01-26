/*
The salary scheme for a company is given as follows:
Salary range for grade A: $700 - $899
Salary range for grade B: $600 - $799
Salary range for grade C: $500 - $649
In addition, a person whose salary is between $600 and $649 is in grade C if his merit points are
below 10, otherwise he is in grade B. A person whose salary is between $700 and $799 is in grade
B if his merit points are below 20, otherwise he is in grade A. Write a program to read in a
person's salary and his merit points, and displays his grade.

Sample input and output sessions are given below:

(1) Test Case 1:
Enter the salary:
700
Enter the merit:
20
The grade: A

(2) Test Case 2:
Enter the salary:
500
Enter the merit:
20
The grade: C
*/

#include <stdio.h>
int main()
{
 int salary, merit;

 printf("Enter the salary: \n");
 scanf("%d", &salary);
 printf("Enter the merit: \n");
 scanf("%d", &merit);

 if(salary < 500 || salary > 899)
    return 0;

 if(salary >= 700 && salary <= 899)
 {
     if(merit < 20 && salary <= 799)
        printf("The grade: B");
     else
        printf("The grade: A");
 }
 else if(salary >= 600 && salary <= 699)
 {
     if(merit < 20 && salary <= 649)
        printf("The grade: C");
     else
        printf("The grade: B");
 }
 else
    printf("The grade: C");

 return 0;
}
