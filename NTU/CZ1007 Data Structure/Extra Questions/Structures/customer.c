/*
Write a C program that repeatedly reads in customer data from the user and prints the
customer data on the screen until the customer name "End Customer" (i.e., first_name last_name) is
read. Your program should include the following two functions: the function nextCustomer() reads
and returns a record for a single customer to the caller via a pointer parameter acct, and the function
printCustomer() takes a parameter acct and then prints the customer information. The prototypes
of the two functions are given below:

void nextCustomer(struct account *acct);
void printCustomer(struct account acct);

The structure definition for struct account is given below:

struct account {
 struct
 {
 char lastName[10];
 char firstName[10];
 } names;
 int accountNum;
 double balance;
};

You are required to implement the functions printCustomer() and nextCustomer(). Write a
C program to test the functions. In your code, you should follow the exact format of the required
input and output given in the following test sample sessions.

Some sample input and output sessions are given below:
(1) Test Case 1:
Enter names (firstName lastName):
SC Hui
Enter account number:
123
Enter balance:
6789.89
Customer record:
SC Hui 123 6789.89
Enter names (firstName lastName):
End Customer

(2) Test Case 2:
Enter names (firstName lastName):
SC Hui
Enter account number:
123
Enter balance:
6789.89
Customer record:
SC Hui 123 6789.89
Enter names (firstName lastName):
FY Tan
Enter account number:
13
Enter balance:
69.89
Customer record:
FY Tan 13 69.89
Enter names (firstName lastName):
End Customer

(3) Test Case 3:
Enter names (firstName lastName):
End Customer
*/

#include <stdio.h>
#include <string.h>
struct account {
 struct
 {
 char lastName[10];
 char firstName[10];
 } names;
 int accountNum;
 double balance;
};
void nextCustomer(struct account *acct);
void printCustomer(struct account acct);
int main()
{
 struct account record;
 int flag = 0;
 do {
 nextCustomer(&record);
 if ((strcmp(record.names.firstName, "End") == 0) &&
 (strcmp(record.names.lastName, "Customer") == 0))
 flag = 1;
 if (flag != 1)
 printCustomer(record);
 } while (flag != 1);
}
void nextCustomer(struct account *acct)
{
 printf("Enter names (firstName lastName): \n");
 scanf("%s %s", acct->names.firstName, acct->names.lastName);

 if((strcmp(acct->names.firstName, "End") == 0) && (strcmp(acct->names.lastName, "Customer") == 0))
    return;

 printf("Enter account number: \n");
 scanf("%d", &(acct->accountNum));

 printf("Enter balance: \n");
 scanf("%lf", &(acct->balance));
}
void printCustomer(struct account acct)
{
 printf("Customer record: \n");
 printf("%s %s %d %.2lf\n", acct.names.firstName, acct.names.lastName, acct.accountNum, acct.balance);
}
