/*
---------------------------------------------------------------------
INSTRUCTIONS
You should use the following definition for a BTNode as previously given in the lecture
slides:
typedef struct _
btnode{
int item;
struct _btnode *left;
struct _btnode *right;
} BTNode;
---------------------------------------------------------------------

1. Write a function insertBSTNode() that adds an item to a Binary Search
Tree.

void insertBSTNode(BTNode **node, int value);

BST nodes should be created dynamically using a malloc() call.
Hint:  The  core  of  this  function  has  been  provided  in  the  lecture  slides.  Make  sure  that  your
code is able to correctly add a node into an empty BST.

2. Write  a  function  printBSTInOrder()that  prints  a  sorted  list  of  items  stored  in  Binary  Search
Tree using an in-order traversal pattern.

void printBSTInOrder(BTNode *node);

3. Write a function isBST() that determines whether a given Binary Tree is also a Binary Search Tree.
The function should return 1 if the BT is a BST, and 0 otherwise.

4. Write  a  function  removeBSTNode()  that  removes  a  given  it
em  from  a  Binary  Search  Tree.
The function should return 0 if the item was found and successfully
removed and 1
otherwise.
*/

//////////////////////////////////////////////////////////////////////

// CE1007/CZ1007 Data Structures
// Week 13 Lab and Tutorial - Binary Search Tree

#include <stdio.h>
#include <stdlib.h>

///////////////////////////////////////////////////////////////////////

typedef struct _btnode{
int item;
struct _btnode *left;
struct _btnode *right;
} BTNode;

///////////////////////////////////////////////////////////////////////

void insertBSTNode(BTNode **node, int value);
void printBSTInOrder(BTNode *node);
int isBST(BTNode *node, int min, int max);
BTNode *removeBSTNode(BTNode *node, int value);
BTNode *findMin(BTNode *p);

///////////////////////////////////////////////////////////////////////

int main(){
	int i=0;

	BTNode *root=NULL;

	//question 1
	do{
		printf("input a value you want to insert(-1 to quit):");

		scanf("%d",&i);
		if (i!=-1)
			insertBSTNode(&root,i);
	}while(i!=-1);

	//question 2
	printf("\n");
	printBSTInOrder(root);

	//question 3
	if ( isBST(root,-1000000, 1000000)==1)
		printf("It is a BST!\n");
	else
		printf("It is not a BST!\n");

	//question 4
	do{
		printf("\ninput a value you want to remove(-1 to quit):");
		scanf("%d",&i);
		if (i!=-1)
		{
			root=removeBSTNode(root,i);
			printBSTInOrder(root);
		}
	}while(i!=-1);


	return 0;
}

//////////////////////////////////////////////////////////////////////

void insertBSTNode(BTNode **node, int value)
{
	if(*node == NULL)
    {
        *node = malloc(sizeof(BTNode));
        (*node)->item = value;
        (*node)->left = (*node)->right = NULL;

        return;
    }

    if((*node)->item == value)
        return;
    else if((*node)->item < value)
    {
        insertBSTNode(&((*node)->right), value);
        return;
    }
    else
    {
        insertBSTNode(&((*node)->left), value);
        return;
    }
}

//////////////////////////////////////////////////////////////////////

void printBSTInOrder(BTNode *node)
{
	if(node == NULL)
        return;

    printBSTInOrder(node->left);
    printf("%d, ", node->item);
    printBSTInOrder(node->right);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int isBST(BTNode *node, int min, int max) // the item stored in node has to be smaller than max and larger than min
{
    if(node == NULL)
        return 1;

    if(node->item < min || node->item > max)
        return 0;

    return isBST(node->left, min, node->item) & isBST(node->right, node->item, max);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

BTNode *removeBSTNode(BTNode *node, int value)
{
	if(node == NULL)
        return NULL;

    if(node->item == value)
    {
        //if the target node is the leaf node
        if(node->right == NULL && node->left == NULL)
        {
            free(node);
            return NULL;
        }   //if the successor is above it, we make the smaller value be the successor
        else if(node->left != NULL && node->right == NULL)
        {
            node->item = node->left->item;
            BTNode *temp = node->left;
            node->left = temp->left;
            node->right = temp->right;
            free(temp);

            return node;
        }

        BTNode *successor = findMin(node->right);

        //transfer the successor's item so that we can free the successor
        node->item = successor->item;

        //make the successor be the one we want to remove
        value = successor->item;
    }

    if(node->item > value)
        node->left = removeBSTNode(node->left, value);
    else
        node->right = removeBSTNode(node->right, value);

    //if returning a the successor, need to return the successor's address and not current node's address
    return node;
}

BTNode *findMin(BTNode *p)
{
    return p->left != NULL ? findMin(p->left) : p;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
