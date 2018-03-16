/*
Write a C program that reads the hours an employee worked in a week,
computes the gross pay and income tax, and prints the gross pay, income tax and net pay on the
screen. Assume that the pay structure and tax rate are given as follows: (1) the basic pay rate is
$6.00 per hour; (2) the over-time pay rate (in excess of 40 hours) is one and a half time of the
basic pay rate; and (3) the tax rate is 10\% of the first $1000 of the gross pay, 20\% of the next
$500 and 30% of the rest.

Sample input and output sessions are given below:

(1) Test Case 1:
Enter hours of work:
37
Gross pay = 222.00
Tax = 22.20
Net pay = 199.80

(2) Test Case 2:
Enter hours of work:
50
Gross pay = 330.00
Tax = 33.00
Net pay = 297.00
*/

#include <stdio.h>
int main()
{
    int hours;
    float tax, grossPay, netPay;

    printf("Enter hours of work: \n");
    scanf("%d", &hours);

    if(hours < 0)
        return 0;

    //gross pay
    grossPay = 6.00 * hours;

    hours -= 40;

    if(hours > 0)
        grossPay += 3.00 * hours;

    //tax
    if(grossPay < 1000)
        tax = grossPay * 0.1;
    else if(grossPay > 1000)
    {
        tax = grossPay * 0.1;
        tax += (grossPay - 1000) * 0.2;
    }else
    {
        tax = grossPay * 0.1;
        tax += (grossPay - 1000) * 0.2;
        tax += (grossPay - 1500) * 0.3;
    }

    //net pay
    netPay = grossPay - tax;

    printf("Gross pay = %.2f\n", grossPay);
    printf("Tax = %.2f\n", tax);
    printf("Net pay = %.2f\n", netPay);
    return 0;
}
