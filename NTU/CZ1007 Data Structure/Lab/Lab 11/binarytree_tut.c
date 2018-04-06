/*
1. Write a recursive function mirrorTree() that will modify a binary tree so that the resulting tree
is a mirror image of the original structure.
You should not create any intermediate or temporary trees. The function accepts a single
parameter: a pointer to the root note of the binary tree to be mirrored.

void mirrorTree(BTNode *node);


2. Write a C function printSmallerValues() that accepts a pointer to the root node of a
binary tree and prints all integers stored in the tree that are smaller than a given value m. The
function prototype is given as follows:

void printSmallerValues(BTNode *node, int m);


3. Write a function smallestValue() that returns the smallest value stored in a given tree. The
function accepts a pointer to the root of the given tree. You should determine the correct
function prototype.


4. Write a recursive function hasGreatGrandchild() that prints the values stored in all nodes of a
binary tree that have at least one great-grandchild. The function accepts a single parameter: a
pointer to the root note of the binary tree.

int hasGreatGrandchild(BTNode *node);

Hint: Determine the common property shared by nodes with great-grandchild nodes, and write
a recursive function that computes that property.
*/

// CX1007 DataStructures
// Week 12 Lab Tutorial - Binary Tree

#include <stdio.h>
#include <stdlib.h>

////////////////////////////////////////////////////////////////////
////////////

typedef struct _btnode{
	int item;
	struct _btnode *left;
	struct _btnode *right;

} BTNode;

////////////////////////////////////////////////////////////////////
////////////

void mirrorTree(BTNode *node);

void printSmallerValues(BTNode *node, int m);
int smallestValue(BTNode *node);
int hasGreatGrandchild(BTNode *node);

void printTree_InOrder(BTNode *node);

////////////////////////////////////////////////////////////////////

int main(int argc, const char * argv[]){

	int i;
	BTNode *root, *root2;
	BTNode btn[15];

	// Create the tree in Q1
	// Using manual dynamic allocation of memory for BTNodes

	root = malloc(sizeof(BTNode));
	root->item = 4;

	root->left = malloc(sizeof(BTNode));
	root->left->item = 5;

	root->right = malloc(sizeof(BTNode));
	root->right->item = 2;

	root->left->left = NULL;

	root->left->right = malloc(sizeof(BTNode));
	root->left->right->item = 6;

	root->left->right->left = NULL;
	root->left->right->right = NULL;

	root->right->left = malloc(sizeof(BTNode));
	root->right->left->item = 3;

	root->right->right = malloc(sizeof(BTNode));
	root->right->right->item = 1;

	root->right->left->left = NULL;

	root->right->left->right = NULL;

	root->right->right->left = NULL;

	root->right->right->right = NULL;

	printTree_InOrder(root);
	printf("\n");
	mirrorTree(root);
	printTree_InOrder(root);
	printf("\n\n");

	//question 2
	printf("\n input m for question 2:");
	scanf("%d", &i);
	printf("the values smaller than %d are:", i);
	printSmallerValues(root, i);
	printf("\n\n");

	//question 3
	printf("The smallest value in the tree is %d:\n", smallestValue(root));

	//question 4
	// Create a tree for Q4: Tall enough so some nodes have great-grandchildren
	// Use array of BTNodes, create tree by linking nodes together
	for (i = 0; i <= 6; i++){
		btn[i].item = i;
		btn[i].left = &(btn[i * 2 + 1]);
		btn[i].right = &(btn[i * 2 + 2]);
	}

	for (i = 7; i <= 14; i++){
		btn[i].item = i;
		btn[i].left = NULL;
		btn[i].right = NULL;
	}
	root2 = &btn[0];

	printf("The tree for question 4 visited by in-order is \n");
	printTree_InOrder(root2);
	printf("\nthe values stored in all nodes of the tree that have at least one great-grandchild are: ");

	hasGreatGrandchild(root2);

	return 0;
}

void mirrorTree(BTNode *node){

    if(node == NULL)
        return;

    BTNode *temp;

    //swap
    temp = node->left;
    node->left = node->right;
    node->right = temp;

    //recursive into branch to swap them
    mirrorTree(node->left);
    mirrorTree(node->right);
}

int hasGreatGrandchild(BTNode *node){

    int i, j;

    //return if leaf node
    if(node->left == NULL && node->right == NULL)
        return 1;

    if(node->left != NULL)
        i = hasGreatGrandchild(node->left);

    if(node->right != NULL)
        j = hasGreatGrandchild(node->right);
    else
        j = 0;

    //more than 2 means have 3 or more nodes beneath it
    if(i > 2 || j > 2)
        printf("%d, ", node->item);

    //include the current node into the count
    return i > j ? i + 1 : j + 1;

}

void printSmallerValues(BTNode *node, int m){

	if (node == NULL)
        return;

	printSmallerValues(node->left, m);

	if(node->item < m)
        printf("%d, ", node->item);

	printSmallerValues(node->right, m);

}

int smallestValue(BTNode *node) {
	int l, r;

	//true when is the leaf node
	if(node->left == NULL && node->right == NULL)
        return node->item;

	if(node->left != NULL)
        l = smallestValue(node->left);

    if(node->right != NULL)
        r = smallestValue(node->right);
    else
        r = l;  //when left have node but right do not have node

    //return the smaller value
    return l < r ? ((l < node->item) ? l : node->item) : r;

}


//////////////////////////////////////////////////////////////////

void printTree_InOrder(BTNode *node){

	if (node == NULL) return;
	printTree_InOrder(node->left);
	printf("%d, ", node->item);
	printTree_InOrder(node->right);
	return;
}
