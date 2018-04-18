/*
Write a C function maxHeight() that accepts a pointer to the root node of a binary tree and
return the number of links along the longest path from the root node down to the farthest leaf node.
Note that height of a given node is equal to the number of links from that node to the deepest leaf node.
(Hint: Consider that the height of an empty tree is -1).

The function prototype is given as follows:
int maxHeight(BRNode *root)



A sample input and output session is given below:



1: Create a binary tree.

2: Find the maximum height of the binary tree.

0: Quit;



Please input your choice(1/2/0): 1

Input an integer that you want to add to the binary tree. Any Alpha value will be treated as NULL.


Enter an integer value for the root: 4

Enter an integer value for the Left child of 4: 2

Enter an integer value for the Right child of 4: 6

Enter an integer value for the Left child of 2: 1

Enter an integer value for the Right child of 2: 3



Enter an integer value for the Left child of 1: a

Enter an integer value for the Right child of 1: a

Enter an integer value for the Left child of 3: a

Enter an integer value for the Right child of 3: a


Enter an integer value for the Left child of 6: 5

Enter an integer value for the Right child of 6: 7



Enter an integer value for the Left child of 5: a

Enter an integer value for the Right child of 5: a

Enter an integer value for the Left child of 7: a

Enter an integer value for the Right child of 7: a



The resulting binary tree is: 1 2 3 4 5 6 7



Please input your choice(1/2/0): 2

Max height of the binary tree is: 2

Please input your choice(1/2/0): 0
*/

/////////////////////////////////////////////////////////////////////////////////

/* CE1007/CZ1007 Data Structures
Purpose: Implementing the required functions for Question 2 */

//////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

//////////////////////////////////////////////////////////////////////////////////
typedef struct _btnode{
	int item;
	struct _btnode *left;
	struct _btnode *right;
} BTNode;   // You should not change the definition of BTNode

/////////////////////////////////////////////////////////////////////////////////

typedef struct _stackNode{
    BTNode *btnode;
    struct _stackNode *next;
}StackNode;

typedef struct _stack{
    StackNode *top;
}Stack;

///////////////////////// function prototypes ////////////////////////////////////

int maxHeight(BTNode *node);

BTNode *createBTNode(int item);

// You may use the following functions or you may write your own
BTNode *createTree();
void push( Stack *stk, BTNode *node);
BTNode* pop(Stack *stk);

void printTree(BTNode *node);
void removeAll(BTNode **node);

///////////////////////////// main() /////////////////////////////////////////////

int main()
{
    int c;
    char e;
	c = 1;

    BTNode *root;
    root = NULL;

    printf("1: Create a binary tree.\n");
    printf("2: Find the maximum height of the binary tree.\n");
    printf("0: Quit;\n");

    while(c != 0){
        printf("\nPlease input your choice(1/2/0): \n");
        if(scanf("%d", &c) > 0)
        {
            switch(c)
            {
            case 1:
                removeAll(&root);
                root = createTree();
                printf("The resulting binary tree is: ");
                printTree(root);
                printf("\n");
                break;
            case 2:
                c = maxHeight(root);
                printf("The maximum height of the binary tree is: %d\n",c);
                removeAll(&root);
                break;
            case 0:
                removeAll(&root);
                break;
            default:
                printf("Choice unknown;\n");
                break;
            }
		}
        else
        {
            scanf("%c",&e);
        }

    }

    return 0;
}

//////////////////////////////////////////////////////////////////////////////////

int maxHeight(BTNode *node)

{
    int l = 0, r = 0;

    if(node == NULL)
        return -1;

    l = maxHeight(node->left) + 1;
    r = maxHeight(node->right) + 1;

    return l > r ? l : r;
}

///////////////////////////////////////////////////////////////////////////////////

BTNode *createBTNode(int item){
    BTNode *newNode = malloc(sizeof(BTNode));
    newNode->item = item;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


//////////////////////////////////////////////////////////////////////////////////

BTNode *createTree()
{
    Stack stk;
    BTNode *root, *temp;
    char s;
    int item;

    stk.top = NULL;
    root = NULL;

    printf("Input an integer that you want to add to the binary tree. Any Alpha value will be treated as NULL.\n");
    printf("Enter an integer value for the root: \n");
    if(scanf("%d",&item) > 0)
    {
        root = createBTNode(item);
        push(&stk,root);
    }
    else
    {
        scanf("%c",&s);
    }

    while((temp =pop(&stk)) != NULL)
    {

        printf("Enter an integer value for the Left child of %d: \n", temp->item);

        if(scanf("%d",&item)> 0)
        {
            temp->left = createBTNode(item);
        }
        else
        {
            scanf("%c",&s);
        }

        printf("Enter an integer value for the Right child of %d: \n", temp->item);
        if(scanf("%d",&item)>0)
        {
            temp->right = createBTNode(item);
        }
        else
        {
            scanf("%c",&s);
        }

        if(temp->right != NULL)
            push(&stk,temp->right);
        if(temp->left != NULL)
            push(&stk,temp->left);
    }
    return root;
}

void push( Stack *stk, BTNode *node){
    StackNode *temp;

    temp = malloc(sizeof(StackNode));
    if(temp == NULL)
        return;
    temp->btnode = node;
    if(stk->top == NULL){
        stk->top = temp;
        temp->next = NULL;
    }
    else{
        temp->next = stk->top;
        stk->top = temp;
    }
}

BTNode* pop(Stack *stk){
   StackNode *temp, *top;
   BTNode *ptr;
   ptr = NULL;

   top = stk->top;
   if(top != NULL){
        temp = top->next;
        ptr = top->btnode;

        stk->top = temp;
        free(top);
        top = NULL;
   }
   return ptr;
}

void printTree(BTNode *node){
    if(node == NULL) return;

    printTree(node->left);
    printf("%d ",node->item);
    printTree(node->right);
}

void removeAll(BTNode **node){
    if(*node != NULL){
        removeAll(&((*node)->left));
        removeAll(&((*node)->right));
        free(*node);
        *node = NULL;
    }
}
