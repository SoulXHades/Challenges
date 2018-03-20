/*
Write a program that asks the user how many characters will be entered, and then asks for
each character. Use dynamic char array to store the characters, as taught in lecture 1. Write
function removes() to remove the first character. Write insert() to insert a character
entered by the user to the beginning of the array, and remove the last character in the array if
the number of characters is more than the size of the array. Sample output:
How many characters do you want to input: 5
Input the string:datas
The string is: datas
Do you want to 1-insert or 2-remove or 3-quit?: 1
What is the character you want to insert: a
Resulting string: adata
Do you want to 1-insert or 2-remove or 3-quit?: 2
Resulting string: data
Do you want to 1-insert or 2-remove or 3-quit?: 1
What is the character you want to insert: q
Resulting string: qdata
Do you want to 1-insert or 2-remove or 3-quit?: 3
*/

// CX1007 Data Structures
// Week 9 Lab Tutorial - DynamicData-Linked Lists

#include "stdlib.h"
#include "stdio.h"

////////////////////////////////////////////////////////////

void insert(char *s,int n);
void removes(char *s, int n);

//////////////////////////////////////////////////////////
void main ()
{
	int n;
    char *s;
	int choice;


	printf("How many characters do you want to input:");
	scanf("%d", &n);

	s=(char *)malloc((n+1)*sizeof(char));

    if (s==NULL)
	{
		printf("can't allocate the memory!");
		return;
	}

	printf("Input the string:");
	scanf("%s",s);

	printf("The string is %s\n", s);

	do
	{
		printf("Do you want to 1-insert or 2-remove or 3-quit?:");
		scanf("%d",&choice);
		//getchar(); //to clear the return carriage in the buffer

		if (choice==1)
			insert(s,n);
		else if (choice==2)
			removes(s,n);
	}while (choice!=3);


}

//////////////////////////////////////////
void removes(char *s, int n)
{
	int i;
	char temp;

	for(i=0; i<n; i++)
    {
        s[i] = s[i+1];
    }

    printf("Resulting string: %s\n", s);
}

//////////////////////////////////////////
void insert(char *s, int n)
{
	int i;
	char newchar;

	printf("What is the character you want to insert: ");
	scanf(" %c", &newchar);



	for(i=n-1; i>0; i--)
    {
        s[i] = s[i-1];
    }

    s[0] = newchar;

    printf("Resulting string: %s\n", s);
}
