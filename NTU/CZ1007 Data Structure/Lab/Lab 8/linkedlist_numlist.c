/*
Write a C program main() that requests a list of numbers from the user, terminated by a
sentinel value of ‘-1’. After the linked list is built, your program should print all numbers
stored in the linked list. Sample output:
Enter a list of numbers, terminated by the value -1:
1
2
3
4
5
-1
Current list: 1 2 3 4 5

Based on the program main() written in 2, write a function searchList() that examines
a linked list of integers to determine if a given integer value is stored within the list.
searchList() is called in main()once the linked list is built and printed.
int searchList(ListNode *head, int value);
The function should return the index of the node containing value if it is found and -1
otherwise. Sample output: (Test application uses a sentinel value of -1)
Current list: 1 2 3 5 6
Enter value to search for: 5
Value 5 found at index 3
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct _linkedint
{
    int num;
    struct _linkedint *add;
}Listint;

int searchList(Listint *head, int value);

int main()
{
    //head node
    Listint *IntList = (Listint *)malloc(sizeof(Listint));
    Listint *countList = IntList;

    //to search value
    int value, loc;

    puts("Enter a list of numbers, terminated by the value -1");
    scanf("%d", &(IntList->num));
    IntList->add = '\0';

    //input
    while(countList->num != -1)
    {
        //create new node
        countList->add = (Listint *)malloc(sizeof(Listint));
        //shift the cursor to next node
        countList = countList->add;

        //read new input
        scanf("%d", &(countList->num));
        countList->add = '\0';
    }

    countList = IntList;
    printf("Current list: ");

    //print linked list
    while(countList->add != '\0')
    {
        printf("%d ", countList->num);
        countList = countList->add;
    }
    //New line
    puts("");

    if(IntList->num != -1)
    {
        printf("Enter value to search for: ");
        scanf("%d", &value);
        //search data in linked list
        loc = searchList(IntList, value);

        if(loc != -1)
            printf("Value %d found at index %d\n", value, loc);
        else
            printf("Value %d not found!\n", value);
    }


    //To free memory used for linked list
    countList = IntList;
    while(countList->add != '\0')
    {
        //Keep track of the next node to free
        IntList = countList;
        countList = IntList->add;
        free(IntList);
    }
}

int searchList(Listint *head, int value)
{
    int i=0;

    while(head->add != '\0')
    {
        if(head->num == value)
            return i;

        //move to next node
        head = head->add;
        ++i;
    }

    return -1;
}
