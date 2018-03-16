/*
Write a function findMiddleAge() that takes in an array of three persons, finds the
person whose age is the middle one of the three persons, and returns the name and age of that person to
the caller. For example, if the array is {{"Tom",18},{"John",19}, {"Jim",20}}, then the
person John and his age will be returned. The structure Person is defined below:

typedef struct {
 char name[20];
 int age;
} Person;

The function prototype is given below:

Person findMiddleAge(Person *p);

Write a C program to test the function. You are also required to write a function readData() to read
the three persons’ information. The input data are passed to the calling function via the pointer parameter
p. The function prototype is given below:

void readData(Person *p);

Some sample input and output sessions are given below:
(1) Test Case 1:
Enter person 1:
john 23
Enter person 2:
peter 56
Enter person 3:
mary 31
findMiddleAge(): mary 31

(2) Test Case 2:
Enter person 1:
vincent 11
Enter person 2:
raymond 22
Enter person 3:
alex 12
findMiddleAge(): alex 12
*/

#include <stdio.h>
typedef struct {
 char name[20];
 int age;
} Person;
void readData(Person *p);
Person findMiddleAge(Person *p);
int main()
{
 Person man[3], middle;

 readData(man);
 middle = findMiddleAge(man);
 printf("findMiddleAge(): %s %d\n", middle.name, middle.age);
 return 0;
}
void readData(Person *p)
{
 int i=1;

 printf("Enter person 1: \n");
 scanf("%s %d", p[0].name, &p[0].age);

 while(i < 3)
 {
     scanf("");
     printf("Enter person %d: \n", i+1);
     scanf("%s %d", p[i].name, &p[i].age);

     ++i;
 }
}
Person findMiddleAge(Person *p)
{
 if(p[0].age > p[1].age)
 {
     if(p[1].age > p[2].age)
        return p[1];
     else if(p[0].age > p[2].age)
        return p[2];
     else
        return p[0];
 }
 else
 {
     if(p[0].age > p[2].age)
        return p[0];
     else if(p[1].age < p[2].age)
        return p[1];
     else
        return p[2];
 }
}
