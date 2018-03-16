/*
Assume that the youngest student is 10 years old. The age of the next older student can be
computed by adding 2 years to the age of the previous younger student. The students are arranged in
ascending order according to their age with the youngest student as the first one. Write a recursive
function rAge() that takes in the rank of a student studRank and returns the age of the student to the
calling function. For example, if studRank is 4, then the age of the corresponding student 16 will be
returned. The function prototype is given as follows:

int rAge(int studRank);

Write a C program to test the function.

Some sample input and output sessions are given below:

(1) Test Case 1:
Enter student rank:
5
rAge(): 18

(2) Test Case 2:
Enter student rank:
1
rAge(): 10
*/

#include <stdio.h>
int rAge(int studRank);
int main()
{
 int studRank;
 printf("Enter student rank: \n");
 scanf("%d",&studRank);
 printf("rAge(): %d\n", rAge(studRank));
 return 0;
}
int rAge(int studRank)
{
 if(studRank == 1)
    return 10;
 else
    return 2 + rAge((studRank-1));
}
