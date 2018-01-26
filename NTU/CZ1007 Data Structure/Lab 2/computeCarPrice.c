/*
Write a program to calculate the actual cost of buying a car in Singapore.
Your program should input the list price and the category of a car, and print out the actual cost.
Based on the list price, assuming that the car dealer will give a discount of 10%. You should also
consider that there is a 10% luxury tax on the amount over $100,000 (after the discount), and that
the G.S.T. tax is 3%. All taxes are computed based on the discounted price. Certificate of
Entitlement (COE) must be obtained for every car in Singapore. The amount you bid for the COE
is based on the category your car belongs to. COE is not taxed. The categories and their COE
prices are given below:
(1) Car (1600 c.c. & below) & Taxi: COE = 70,000
(2) Car (above 1600 c.c.): COE = 80,000
(3) Goods Vehicle & Bus: COE = 23,000
(4) Motorcycle - COE: 600

Sample input and output sessions are given below:

(1) Test Case 1:
Please enter the list price:
30000
Please enter the category:
1
Total price is $97810.00

(2) Test Case 2:
Please enter the list price:
50000
Please enter the category:
2
Total price is $126350.00
*/

#include <stdio.h>
int main()
{
 int list, coe = 0, cat;
 double discounted, luxury = 0, gst, total;

 printf("Please enter the list price: \n");
 scanf("%d", &list);
 printf("Please enter the category: \n");
 scanf("%d", &cat);

 //Check for valid input
 if(list < 0 || !(cat > 0 && cat < 5))
    return 0;

 //discounting
 discounted = list * 0.9;

 //luxury tax
 if(discounted > 100000)
    luxury = discounted * 0.1;

 //G.S.T. tax
 gst = discounted * 0.03;

 switch(cat)
 {
    case 1:
        total = discounted + luxury + gst + 70000;
        break;

    case 2:
        total = discounted + luxury + gst + 80000;
        break;

    case 3:
        total = discounted + luxury + gst + 23000;
        break;

    default:
        total = discounted + luxury + gst + 600;
        break;
 }

 printf("Total price is $%.2lf\n", total);
 return 0;
}
