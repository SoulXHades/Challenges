/*
Write a C program that prints the ID and grade of each student in a class. The
input contains the student IDs and their marks. The range of the marks is from 0 to 100. The
relationships of the marks and grades are given below:
Grade Mark
A 100-75
B 74-65
C 64-55
D 54-45
F 44-0
Use the sentinel value –1 for student ID to indicate the end of user input.

Sample input and output sessions are given below:

(1) Test Case 1:
Enter Student ID:
11
Enter Mark:
56
Grade = C
Enter Student ID:
21
Enter Mark:
89
Grade = A
Enter Student ID:
31
Enter Mark:
34
Grade = F
Enter Student ID:
-1

(2) Test Case 2:
Enter Student ID:
-1
*/

#include <stdio.h>
int main()
{
   int studentNumber = 0, mark;

   printf("Enter Student ID: \n");
   scanf("%d", &studentNumber);
   while (studentNumber != -1)
   {
      printf("Enter Mark:\n");
      scanf("%d", &mark);

      switch((mark+5)/10)
      {
        case 10:
        case 9:
        case 8:
            printf("Grade = A\n");
            break;
        case 7:
            printf("Grade = B\n");
            break;
        case 6:
            printf("Grade = C\n");
            break;
        case 5:
            printf("Grade = D\n");
            break;
        default:
            printf("Grade = F\n");
      }

      printf("Enter Student ID: \n");
      scanf("%d", &studentNumber);
   }
   return 0;
}
