/*
Assume the following structure is defined to represent a grade record of a student:

struct student{

      char name[20];    // student name

      double testScore; // test score

      double examScore; // exam score

      double total;     // total = (testScore+examScore)/2

};

Write a C function average() that creates a database of maximum 50 students using an array of structures.
The function reads in student name. For each student, it takes in the test score and exam score.
Then it computes and prints the total score of the student.
The input will end when the student name is “END”.
Then, it computes and returns the average score of all students to the calling function (i.e. main()).
The calling function then prints the average score on the display. The function prototype is given below:

    double average();

Write a C program to test the function.

Some sample input and output sessions are given below:

(1) Test Case 1:
Enter student name:
Hui S
Enter test score:
34
Enter exam score:
45
Student Hui S total = 39.50
Enter student name:
END
average(): 39.50

(2) Test Case 2:
Enter student name:
Hui S
Enter test score:
34
Enter exam score:
45
Student Hui S total = 39.50
Enter student name:
Fong A
Enter test score:
67
Enter exam score:
56
Student Fong A total = 61.50
Enter student name:
END
average(): 50.50

(3) Test Case 3:
Enter student name:
END
average(): 0.00
*/

#include <stdio.h>
#include <string.h>
struct student{
   char name[20]; /* student name */
   double testScore; /* test score */
   double examScore; /* exam score */
   double total;  /* total = (testScore+examScore)/2 */
};
double average();
int main()
{
   printf("average(): %.2f\n", average());
   return 0;
}
double average()
{
   int num=1;
   double total_a=0;
   struct student stud;

   printf("Enter student name:\n");
   gets(stud.name);

   while(strcmp(stud.name, "END") != 0)
   {
        printf("Enter test score:\n");
        scanf("%lf", &stud.testScore);
        printf("Enter exam score:\n");
        scanf("%lf", &stud.examScore);

        stud.total = (stud.testScore + stud.examScore)/2;

        printf("Student %s total = %.2lf\n", stud.name, stud.total);

        total_a += stud.total;

        if(num == 50)
            break;

        num++;

        scanf("\n");
        printf("Enter student name:\n");
        gets(stud.name);
   }

   if(num > 1)
    num -= 1;

   return total_a/num;
}
