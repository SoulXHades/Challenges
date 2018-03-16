/*
Write a C program that reads and searches character strings.
In the program, it contains a function findTarget() that searches whether a target name string has been stored in the array of strings.
The function prototype is

    int findTarget(char *target, char nameptr[SIZE][80], int size);

where nameptr is the array of strings entered by the user,
size is the number of names stored in the array and target is the target string.
If the target string is found, the function will return its index location, or -1 if otherwise.

Some sample input and output sessions are given below:

(1) Test Case 1:
Select one of the following options:
1: readNames()()
2: findTarget()
3: printNames()
4: exit()
Enter your choice:
1
Enter size:
4
Enter 4 names:
Peter Paul John Mary
Enter your choice:
2
Enter target name:
John
findTarget(): 2
Enter your choice:
4

(2) Test Case 2:
Select one of the following options:
1: readNames()()
2: findTarget()
3: printNames()
4: exit()
Enter your choice:
1
Enter size:
5
Enter 5 names:
Peter Paul John Mary Vincent
Enter your choice:
2
Enter target name:
Jane
findTarget(): -1
Enter your choice:
4

(3) Test Case 3:
Select one of the following options:
1: readNames()()
2: findTarget()
3: printNames()
4: exit()
Enter your choice:
1
Enter size:
5
Enter 5 names:
Peter Paul John Mary Vincent
Enter your choice:
3
Peter Paul John Mary Vincent

(4) Test Case 4:
Select one of the following options:
1: readNames()()
2: findTarget()
3: printNames()
4: exit()
Enter your choice:
1
Enter size:
6
Enter 6 names:
Peter Paul John Mary Vincent Joe
Enter your choice:
2
Enter target name:
Joe
findTarget(): 5
Enter your choice:
4
*/

#include <stdio.h>
#include <string.h>
#define SIZE 10
#define INIT_VALUE 999
void printNames(char nameptr[][80], int size);
void readNames(char nameptr[][80], int *size);
int findTarget(char *target, char nameptr[][80], int size);
int main()
{
   char nameptr[SIZE][80], t[40];
   int size, result = INIT_VALUE;
   int choice;

   printf("Select one of the following options: \n");
   printf("1: readNames()\n");
   printf("2: findTarget()\n");
   printf("3: printNames()\n");
   printf("4: exit()\n");
   do {
      printf("Enter your choice: \n");
      scanf("%d", &choice);
      switch (choice) {
         case 1:
            readNames(nameptr, &size);
            break;
         case 2:
            printf("Enter target name: \n");
            scanf("\n");
            gets(t);
            result = findTarget(t, nameptr, size);
            printf("findTarget(): %d\n",  result);
            break;
         case 3:
            printNames(nameptr, size);
            break;
      }
   } while (choice < 4);
   return 0;
}
void printNames(char nameptr[][80], int size)
{
    int i;

    for(i=0; i<size; i++)
        printf("%s ", nameptr[i]);

    puts("");
}
void readNames(char nameptr[][80], int *size)
{
   int i;

   printf("Enter size:\n");
   scanf("%d", size);
   printf("Enter %d names:\n", *size);

   for(i=0; i<*size; i++)
   {
       scanf("%s", nameptr[i]);
   }
}
int findTarget(char *target, char nameptr[][80], int size)
{
   int i;

   for(i=0; i<size; i++)
   {
       if(strcmp(nameptr[i], target) == 0)
       {
           return i;
       }
   }

   return -1;
}
