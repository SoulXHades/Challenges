/*
1. Implement the removeNode() function for a linked list, using the lecture diagrams and
pseudo-code as a reference. The prototype for the removeNode() function is given below:

int removeNode(ListNode **ptrHead, int index);

The function should return 0 if the delete operation is successful and -1 otherwise. Recall that
the function requires a pointer to the head pointer in order to correctly delete the first node.
Write a program to test the removeNode() function. It should first allow the user to create a
linked list of integers by appending values to the end of the list. Next, it should allow the user
to delete nodes one by one based on their indices.

2. Re-write the function removeNode() using the LinkedList struct defined in the lecture
materials.

int removeNode2(LinkedList *ll, int index);

3. Write a function split() that copies the contents of a linked list into two other linked lists. The
function prototype is given below:

split(ListNode *head,
ListNode **ptrEvenList,
ListNode **ptrOddList);

The function copies nodes with even indices (0, 2, 4, etc) to evenList and nodes with odd
indices (1, 3, 5, etc) to oddList. The original linked list should not be modified.

Sample output:
Current list: 1 3 5 2 4 6 19 16 7
Even list: 1 5 4 19 7
Odd list: 3 2 6 16

4. Write a function duplicateReverse() that creates a duplicate of a linked list with the nodes
stored in reverse. The function prototype is given below:

int duplicateReverse(ListNode *head,
ListNode **ptrNewHead);

The function should return 0 if the operation was successful and -1 otherwise. newHeadPtr
should point to the first node of the reversed duplicate list.

Sample output:
Current list: 1 3 5 2 4 6
Reversed list: 6 4 2 5 3 1


Practice questions:

1. Write a function moveMaxToFront() that traverses a linked list of integers at most once,
then moves the node with the largest stored value to the front of the list. The function
prototype is given below:

int moveMaxToFront(ListNode **ptrHead);

The function should return the original index of the node with the largest value if
the operation was successful and -1 otherwise.

2. Write a function concatenate() that concatenates two linked lists. The function prototype
is given below:

int concatenate(ListNode **ptrHead1, ListNode *head2);

The function should return 0 if it completes successfully and -1 otherwise. The final node
of the first list should point to the first node of the second list. Your function should not
create any new nodes. Be sure to handle the cases where one or more of the lists are empty.

3. Write a function combineAlternating() that combines two linked lists into a new one.
Nodes from the two lists should be used in alternating order. The function prototype is
given below:

int combineAlternating(ListNode **ptrHead, ListNode *head1, ListNode *head2);

The function should return 0 if it completes successfully and -1 otherwise.
Given the two lists [1 3 5 7] and [2 4 6 8], the new list created should be [1 2 3 4 5 6 7 8].
If one list is shorter than the other, nodes from the longer list should be used after the
shorter list runs out. That is, given the two lists [1 3] and [2 4 6 8 10 12], the new list
created should be [1 2 3 4 6 8 10 12].

4. Write a function insertDbl() for a non-circular, doubly linked list of integers. The
function prototype is given below:

int insertDbl(DblListNode **ptrHead, int index, i nt value);

The function should return 0 if it completes successfully and -1 otherwise. Use the
doubly linked list nodes as defined in lecture.
*/

// CE1007/CZ1007 Data Structures
// Week 10 Lab Tutorial - Linked List

#include <stdio.h>
#include <stdlib.h>

////////////////////////////////////////////////////////////////////
////////////

typedef struct _listnode{
	int num;
	struct _listnode *next;
} ListNode;
typedef struct _linkedlist{
	ListNode *head;
	int size;
} LinkedList;
typedef struct _dbllistnode{
	int num;
	struct _dbllistnode *pre;
	struct _dbllistnode *next;
} DblListNode;

////////////////////////////////////////////////////////////////////
////////////
int removeNode(ListNode **ptrHead, int index);
int removeNode2(LinkedList *ll, int index);
int split(ListNode *head, ListNode **ptrEvenList, ListNode **ptrOddList);
int duplicateReverse(ListNode *head, ListNode **ptrNewHead);

void printList(ListNode *head);
ListNode * findNode(ListNode *head, int index);
int insertNode(ListNode **ptrHead, int index, int value);


// these are for the practice questions
int moveMaxToFront(ListNode **ptrHead);
int concatenate(ListNode **ptrHead1, ListNode *head2);
int combineAlternating(ListNode **ptrHead, ListNode *head1, ListNode *head2);
int insertDbl(DblListNode **ptrHead, int index, int value);
void printDblList(DblListNode *head);

////////////////////////////////////////////////////////////////////
////////////

int main()
{
	int i;
	ListNode *head = NULL;
	ListNode *dupRevHead = NULL;
	ListNode *oddHead = NULL;
	ListNode *evenHead = NULL;
	ListNode *list1Head = NULL, *list2Head = NULL;
	ListNode *combAltHead = NULL;
	DblListNode *dblHead = NULL;
	LinkedList llist;
	int size = 0;

	//build a linked list
	if (insertNode(&head, 0, 6) == 0) size++;
	if (insertNode(&head, 0, 4) == 0) size++;
	if (insertNode(&head, 0, 2) == 0) size++;
	printf("After inserting 3 values.");
	printList(head);


	//removeNode(): question 1
	if (removeNode(&head, 3) == 0) size--;//this one can't be removed.
	if (removeNode(&head, 1) == 0) size--;
	if (removeNode(&head, 0) == 0) size--;

	printf("\nafter remove using removeNode(), ");
	printList(head);

	//insert some nodes
	if (insertNode(&head, 2, 3) == 0) size++; // this one can't be inserted.
	if (insertNode(&head, 1, 1) == 0) size++;
	if (insertNode(&head, 0, 0) == 0) size++;

	printf("\nafter insert, ");
	printList(head);

	//removeNode2(): question 2
	llist.head = head;
	llist.size = size;
	removeNode2(&llist, 2);
	removeNode2(&llist, 0);
	removeNode2(&llist, 0);
	head = llist.head;


	printf("\nafter remove using removeNode2(), ");
	printList(llist.head);
	// empty linked list now

	//split(): question 3
	for (i = 1; i <10; i++)//build a new linked list
		insertNode(&head, 0, i);
	printf("\n\ninsert 1-9 to the linked list,");
	printList(head);
	printf("split the current list, results:\n");
	split(head, &evenHead, &oddHead);
	printf("the even list");
	printList(evenHead);
	printf("the odd list");
	printList(oddHead);

	//duplicateReverse(): question 4
	printf("\n");
	printList(head);
	duplicateReverse(head, &dupRevHead);
	printf("After duplicateReverse(),");
	printList(dupRevHead);

	////////////////////////////////////////////////////////////////////////
	//the following are for the PRACTICE QUESTIONS

	printf("\n\nNow for the practice questions");

	//1.moveMaxToFront()
	printf("\n************** moveMaxToFront *******************\n");
	printList(dupRevHead);
	moveMaxToFront(&dupRevHead);
	printf("after moveMaxToFront()");
	printList(dupRevHead);

	//2. concatenate()
	printf("\n************** concatenate() *******************\n");
	concatenate(&head, dupRevHead);
	printf("concatenate(current list, duplicate reverse list)\n  ");
	printList(head);

	//3.combineAlternating()
	printf("\n************** combineAlternating() *******************\n");
	for (i = 3; i > 0; i--)				//build linked list 1
		insertNode(&list1Head, 0, i);
	for (i = 13; i > 10; i--)			//build linked list 2
		insertNode(&list2Head, 0, i);
	printf("List 1:");
	printList(list1Head);
	printf("List 2: ");
	printList(list2Head);
	combineAlternating(&combAltHead, list1Head, list2Head);
	printf("After combineAlternating(): ");
	printList(combAltHead);

	//4. insertDbl()
	printf("\n************** insertDbl() *******************\n");
	printf("insertDbl()\nDoubly-linked list: ");
	insertDbl(&dblHead, 0, 10);
	insertDbl(&dblHead, 0, 20);
	insertDbl(&dblHead, 1, 30);
	insertDbl(&dblHead, 2, 40);
	printDblList(dblHead);
	return 0;
}

////////////////////////////////////////////////////////////////////
////////////

void printList(ListNode *head){
	ListNode *cur = head;

	if (cur == NULL)
		return;

	printf("the current linked list is:\n");
	while (cur != NULL){
		printf("%d ", cur->num);
		cur = cur->next;
	}
	printf("\n");
}

void printDblList(DblListNode *head){
	if (head == NULL) return;
	while (head != NULL){
		printf("%d ", head->num);
		head = head->next;
	}
	printf("\n");
}

ListNode * findNode(ListNode *head, int index){
	if (head == NULL || index < 0) return NULL;
	while (index > 0){
		head = head->next;
		if (head == NULL)
			return NULL;
		index--;
	}
	return head;
}


int insertNode(ListNode **ptrHead, int index, int value){
	ListNode *pre, *cur;
	// If empty list or inserting first node, need to update head pointer
	if (*ptrHead == NULL || index == 0){
		cur = *ptrHead;
		*ptrHead = malloc(sizeof(ListNode));
		(*ptrHead)->num = value;
		(*ptrHead)->next = cur;
		return 0;
	}
	// Find the nodes before and at the target position
	// Create a new node and reconnect the links
	if ((pre = findNode(*ptrHead, index - 1)) != NULL){
		cur = pre->next;
		pre->next = malloc(sizeof(ListNode));
		pre->next->num = value;
		pre->next->next = cur;
		return 0;
	}
	return -1;
}

////////////////////////////////////////////////////////////////////
////////////

int removeNode(ListNode **ptrHead, int index){

	ListNode *cur=NULL, *LN=*ptrHead;

	while(LN != NULL)
    {
        if(index == 0)
        {
            if(cur != NULL)
            {
                cur->next = LN->next;
                free(LN);
            }
            else
            {
                cur = LN->next;
                free(LN);
                *ptrHead = cur;
            }

            return 0;
        }

        cur = LN;
        LN = LN->next;
        --index;
    }

    return -1;
}

////////////////////////////////////////////////////////////////////////////////

int removeNode2(LinkedList *ll, int index) {

	ListNode *LN=ll->head, *cur=NULL;

	while(LN != NULL)
    {
        if(index == 0)
        {
            if(cur != NULL)
            {
                cur->next = LN->next;
                free(LN);
            }
            else
            {
                ll->head = LN->next;
                free(LN);
            }

            return 0;
        }

        cur = LN;
        LN = LN->next;
        --index;
    }

    return -1;
}

////////////////////////////////////////////////////////////////////////////////

int split(ListNode *head, ListNode **ptrEvenList, ListNode **ptrOddList)
{
	int even=0, odd=0;

	while(head != NULL)
    {
        if(head->num % 2 == 0)
        {
            insertNode(ptrEvenList, even, head->num);
            ++even;
        }
        else
        {
            insertNode(ptrOddList, odd, head->num);
            ++odd;
        }

        head = head->next;
    }

}

////////////////////////////////////////////////////////////////////////////////

int duplicateReverse(ListNode *head, ListNode **ptrNewHead){

	if(head == NULL)
        return -1;

    while(head != NULL)
    {
        insertNode(ptrNewHead, 0, head->num);

        head = head->next;
    }

    return 0;
}

////////////////////////////////////////////////////////////////////
////////////

int moveMaxToFront(ListNode **ptrHead){

    int pos=0, max, i=1;
    ListNode *cur;

    if(*ptrHead == NULL)
        return -1;

    //set max to value in node 0
    max = (*ptrHead)->num;
    //get address of node in index 1
    cur = findNode(*ptrHead, i);

    while(cur != NULL)
    {
        if(cur->num > max)
        {
            //update max
            max = cur->num;
            pos = i;
        }

        //counter
        ++i;

        //get address of next node
        cur = findNode(*ptrHead, i);
    }


    //get the address of the node with max value
    cur = findNode(*ptrHead, pos);

    //move max to index 0
    insertNode(ptrHead, 0, cur->num);
    if(removeNode(ptrHead, pos+1) == -1)
        return -1;

    return pos;
}


int concatenate(ListNode **ptrHead1, ListNode *head2){

	ListNode *LN=*ptrHead1;

	if(LN == NULL)
        return -1;

    while(LN->next != NULL)
        LN = LN->next;

    LN->next = head2;

    return 0;
}


int combineAlternating(ListNode **ptrHead, ListNode *head1, ListNode *head2){

	int i=0;

	if(head1 == NULL && head2 == NULL)
        return -1;

	while(head1 != NULL && head2 != NULL)
    {
        //instead value to new list
        insertNode(ptrHead, i++, head1->num);
        insertNode(ptrHead, i++, head2->num);

        //move to next node
        head1 = head1->next;
        head2 = head2->next;
    }


    //check if list 2 still have nodes
    if(head1 == NULL)
    {
        while(head2 != NULL)
        {
            //instead remaining values of list 2 into new list
            insertNode(ptrHead, i++, head2->num);

            //move to next node
            head2 = head2->next;
        }
    }


    return 0;

}


int insertDbl(DblListNode **ptrHead, int index, int value){

	DblListNode *cur = *ptrHead, *pre, *temp;

	if(*ptrHead == NULL || index == 0)
    {
        *ptrHead = malloc(sizeof(DblListNode));
        (*ptrHead)->num = value;
        (*ptrHead)->pre = NULL;
        (*ptrHead)->next = cur;
        if(cur != NULL)
            cur->pre = *ptrHead;
    }
    else
    {
        while(index > 0)
        {
            if(cur == NULL)
                return -1;

            pre = cur;
            cur = cur->next;
            --index;
        }

        //create and store value in new node
        temp = cur;
        cur = malloc(sizeof(DblListNode));
        cur->num = value;
        cur->next = temp;
        if(temp != NULL)
        {
            cur->pre = pre;
            pre->next = cur;
            temp->pre = cur;
        }
        else
        {
            //useful if adding into a new index
            cur->pre = pre;
            pre->next = cur;
        }
    }

    return 0;

}


////////////////////////////////////////////////////////////////////
