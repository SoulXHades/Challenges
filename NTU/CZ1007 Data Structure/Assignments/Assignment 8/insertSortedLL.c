/*
Write a C function insertSortedLL()that asks the user to input an integer,
then inserts it to the linked list in ascending order.
The function, insertSortedLL(), should not allow to insert an integer if it is already existing in the current linked list.
The function should return the index position where the new item was  added;
if  the  function  could  not  complete successfully, it should  return  a  value  of  -1.
You can assume that the linked list is either a sorted linked list or an empty list.

The function prototype is given as follows:

int insertSortedLL(LinkedList *ll, int item);


If the current linked list is: 2  3  5  7  9

Calling insertSortedLL() with a value of 8 will result the following linked list:

2  3  5  7  8  9

The function should return the index position where the new item was added as follows:

The value 8 was added at index 4


If the current linked list is: 5  7  9  11 15

Calling insertSortedLL() with a value of 7 will result the following linked list:

5  7  9  11  15

The function does not complete successfully (does not insert value of 7 to the linked list)
hence it should return a value of -1:

The value 7 was added at index -1


Your function should print the contents of the linked list after it has been created.
This function may be called multiple times for each time your program is running.
*/

////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* CE1007/CZ1007 Data Structures
2017/18 S2
Submission Deadline: March 30th, 2018 (Friday) 11.59 pm
Purpose: Implementing the required functions for Question 1 */

///////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef struct _listnode{
	int item;
	struct _listnode *next;
} ListNode;			// You should not change the definition of ListNode

typedef struct _linkedlist{
	int size;
	ListNode *head;
} LinkedList;			// You should not change the definition of LinkedList


///////////////////////// function prototypes ////////////////////////////////////////////////////////////////////////

// This is for question 1. You should not change the prototype of this function
int insertSortedLL(LinkedList *ll, int item);

// You may use the following functions or you may write your own
void printList(LinkedList *ll);
void removeAllItems(LinkedList *ll);
ListNode *findNode(LinkedList *ll, int index);
int insertNode(LinkedList *ll, int index, int value);
int removeNode(LinkedList *ll, int index);


//////////////////////////// main() /////////////////////////////////////////////////////////////////////

int main()
{
	LinkedList ll;
	int c, i, j;
	c = 1;

	//Initialize the linked list 1 as an empty linked list
	ll.head = NULL;
	ll.size = 0;

	printf("1: Insert an integer to the sorted linked list:\n");
	printf("2: Print the index of the most recent input value:\n");
	printf("3: Print sorted linked list:\n");
	printf("0: Quit:");

	while (c != 0)
	{
		printf("\nPlease input your choice(1/2/3/0): ");
		scanf("%d", &c);

		switch (c)
		{
		case 1:
			printf("Input an integer that you want to add to the linked list: ");
			scanf("%d", &i);
			j = insertSortedLL(&ll, i);
			printf("The resulting linked list is: ");
			printList(&ll);
			break;
		case 2:
			printf("The value %d was added at index %d\n", i, j);
			break;
		case 3:
			printf("The resulting sorted linked list is: ");
			printList(&ll);
			break;
		case 0:
			removeAllItems(&ll);
			break;
		default:
			printf("Choice unknown;\n");
			break;
		}


	}
	return 0;
}

//////////////////////////////////////////////////////////////////////////////////

int insertSortedLL(LinkedList *ll, int item)
{
	int i=0;
	ListNode *cur=NULL, *temp;

	if(ll->head == NULL)
    {
        ll->head = malloc(sizeof(ListNode));
        ll->head->next = NULL;
        ll->head->item = item;
        ++(ll->size);

        return 0;
    }

    //pointer to access node by node
	ListNode *LN = ll->head;

	//exit if at last node
	while(LN != NULL)
    {
        if(LN->item == item)
            return -1;
        else if(LN->item > item)
        {
            //create new node
            temp = malloc(sizeof(ListNode));

            //write to new node and insert new node into the linked list
            temp->next = LN;
            temp->item = item;

            //if is to be inserted into index 0, cur will be empty, hence point the head to the address of the new node
            if(cur != NULL)
                cur->next = temp;
            else
                ll->head = temp;

            return i;
        }

        //one before, another after
        cur = LN;
        LN = LN->next;

        //count index
        ++i;
    }

    //occur when item is bigger than all items in the linked list
    //create new node
    LN = malloc(sizeof(ListNode));
    LN->next = NULL;
    LN->item = item;
    //link last node to the latest new node
    cur->next = LN;
    ++(ll->size);

    return i;
}

///////////////////////////////////////////////////////////////////////////////////

void printList(LinkedList *ll){

	ListNode *cur;
	if (ll == NULL)
		return;
	cur = ll->head;

	if (cur == NULL)
		printf("Empty");
	while (cur != NULL)
	{
		printf("%d ", cur->item);
		cur = cur->next;
	}
	printf("\n");
}


void removeAllItems(LinkedList *ll)
{
	ListNode *cur = ll->head;
	ListNode *tmp;

	while (cur != NULL){
		tmp = cur->next;
		free(cur);
		cur = tmp;
	}
	ll->head = NULL;
	ll->size = 0;
}


ListNode *findNode(LinkedList *ll, int index){

	ListNode *temp;

	if (ll == NULL || index < 0 || index >= ll->size)
		return NULL;

	temp = ll->head;

	if (temp == NULL || index < 0)
		return NULL;

	while (index > 0){
		temp = temp->next;
		if (temp == NULL)
			return NULL;
		index--;
	}

	return temp;
}

int insertNode(LinkedList *ll, int index, int value){

	ListNode *pre, *cur;

	if (ll == NULL || index < 0 || index > ll->size + 1)
		return -1;

	// If empty list or inserting first node, need to update head pointer
	if (ll->head == NULL || index == 0){
		cur = ll->head;
		ll->head = malloc(sizeof(ListNode));
		ll->head->item = value;
		ll->head->next = cur;
		ll->size++;
		return 0;
	}


	// Find the nodes before and at the target position
	// Create a new node and reconnect the links
	if ((pre = findNode(ll, index - 1)) != NULL){
		cur = pre->next;
		pre->next = malloc(sizeof(ListNode));
		pre->next->item = value;
		pre->next->next = cur;
		ll->size++;
		return 0;
	}

	return -1;
}


int removeNode(LinkedList *ll, int index){

	ListNode *pre, *cur;

	// Highest index we can remove is size-1
	if (ll == NULL || index < 0 || index >= ll->size)
		return -1;

	// If removing first node, need to update head pointer
	if (index == 0){
		cur = ll->head->next;
		free(ll->head);
		ll->head = cur;
		ll->size--;

		return 0;
	}

	// Find the nodes before and after the target position
	// Free the target node and reconnect the links
	if ((pre = findNode(ll, index - 1)) != NULL){

		if (pre->next == NULL)
			return -1;

		cur = pre->next;
		pre->next = cur->next;
		free(cur);
		ll->size--;
		return 0;
	}

	return -1;
}
