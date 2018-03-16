/*
Write a C program that implements the following two functions. The function readin()
reads a number of persons’ names and their corresponding telephone numbers, passes the data to the
caller via the parameter p, and returns the number of names that have entered. The character '#' is used
to indicate the end of user input. The function search() finds the telephone number of an input name
target, and then prints the name and telephone number on the screen. If the input name cannot be
found, then it will print an appropriate error message. The prototypes of the two functions are given below:

int readin(PhoneBk *p);
void search(PhoneBk *p, int size, char *target);

The structure definition for PhoneBk is given below:

typedef struct {
 char name[20];
 char telno[20];
} PhoneBk;

You are required to implement the two functions. Write a C program to test the functions.

Some test input and output sessions are given below:
(1) Test Case 1:
 Enter name:
Hui Siu Cheung
Enter tel:
1234567
Enter name:
Philip Fu
Enter tel:
2345678
Enter name:
Chen Jing
Enter tel:
3456789
Enter name:
#
Enter search name:
Philip Fu
Name = Philip Fu, Tel = 2345678

(2) Test Case 2:
 Enter name:
Hui Siu Cheung
Enter tel:
1234567
Enter name:
Chen Jing
Enter tel:
3456789
Enter name:
#
Enter search name:
Philip Fu
Name not found!

(3) Test Case 3:
Enter name:
#
Enter search name:
Philip Fu
Name not found!
*/

#include <stdio.h>
#include <string.h>
#define MAX 100
typedef struct {
 char name[20];
 char telno[20];
} PhoneBk;
int readin(PhoneBk *p);
void search(PhoneBk *p, int size, char *target);
int main()
{
 PhoneBk s[MAX];
 char t[20];
 int size;
 size = readin(s);
 printf("Enter search name: \n");
 gets(t);
 search(s,size,t);
 return 0;
}
int readin(PhoneBk *p)
{
 int i=0;

 printf("Enter name: \n");
 gets(p[0].name);

 while(strcmp(p[i].name, "#") != 0)
 {
     printf("Enter tel: \n");
     gets(p[i].telno);

     ++i;

     printf("Enter name: \n");
     gets(p[i].name);
 }

 return (i != 0) ? i-1 : 0;
}
void search(PhoneBk *p, int size, char *target)
{
 int i;

 for(i=0; i<size; i++)
 {
     if(strcmp(p[i].name, target) == 0)
     {
         printf("Name = %s, Tel = %s\n", p[i].name, p[i].telno);
         return;
     }
 }

 printf("Name not found! \n");
}
