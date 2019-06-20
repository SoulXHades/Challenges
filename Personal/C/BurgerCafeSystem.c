/*
*Question*

You are required to write a C program to help waiters to take food orders from customers in a restaurant.
The menu is shown in the table below:

--------------------------------------------------------------------
[Burger]
Chicken: S$5.00
Beef   : S$6.00

[Drink]
Hot : S$1.00
Cold: S$1.50
--------------------------------------------------------------------

Program requirements:
1. Declare the variables required and initialize them where necessary.
2. Use a loop to capture/display the following information for each order taken.
    a. Prompt the waiter to enter the type of burger (1-Chicken, 2-Beef). The user may enter 3 to end the entry.
    A message "Invalid entry. Try again!" will be displayed if the entry is neither 1, 2, nor 3, after which the
    waiter will be asked to enter the type of burger again.
    b. Prompt the waiter to enter whether the customer orders hot or cold drink (1-Hot, 2-Cold). The request will
    be repeated if the entry is neither 1 nor 2.
    c. Prompt the waiter to enter 'y' if necessary if is takeaway, or any other key if it is otherwise.
    d. Accumulate the necessary data for the daily report to be presented at the end.
    e. Display the price and assign the collection counter.
3. Calculate and display the daily report when the data entry ends.


Regarding the collection counter:
There are 4 collection counter. It will be assigned according to Customer number as shown below:
Customer    1 2 3 4 5 6 7 8 9 ...
    to
Counter     1 2 3 4 1 2 3 4 1 ...


Regarding the daily report:
When the waiter enters 3 when prompted for burger order, the prompt will give a daily report on the total number of
customers, amount of money collected, number of chicken and beef burgers sold, number of hot and cold drinks ordered,
and number and percentage of takeaways.
*/

#include <stdio.h>
#include <ctype.h>
#define CHICKENCOST 5.00
#define BEEFCOST 6.00
#define HOTDRINKCOST 1.00
#define COLDDRINKCOST 1.50

int main()
{
    // initialization/declaration
    int burgerChoice, drinkChoice, customerNo=1, collectionCounter=1;
    int totalChickenOrder=0, totalBeefOrder=0, totalHotDrinkOrder=0, totalColdDrinkOrder=0, noOfTakeAways=0;
    int contBurgerMenu, contDrinkMenu;
    float totalCost, totalRevenue=0, takeAwayPecent=0;
    char takeAway;

    printf("=== Meal Ordering System ===\n\n");

    //keep the program running via an infinite WHILE loop
    while(1)
    {
        // to enter the burger menu WHILE loop
        contBurgerMenu = 1;

        // prompt and get burger choice
        while(contBurgerMenu)
        {
            // display customer number and burger menu options
            printf("Customer %d\n", customerNo);
            printf("Burger [1.Chicken 2.Beef 3.Exit]? ");
            scanf("%d",&burgerChoice);

            switch(burgerChoice)
            {
                case 1:
                    ++totalChickenOrder;    // for daily report
                    contBurgerMenu = 0; // to exit burger menu due to valid input
                    break;
                case 2:
                    ++totalBeefOrder;   //for daily report
                    contBurgerMenu = 0; // to exit burger menu due to valid input
                    break;
                case 3:
                    contBurgerMenu = 0; // to exit burger menu due to valid input
                    --customerNo;   // since ++customerNo, so -1 for now to cancel out later +1 since choice 3 is not an order
                    break;
                default:
                    printf("Invalid entry. Try again!\n\n");
                    --customerNo;   // since ++customerNo, so -1 for now to cancel out later +1 since choice 3 is not an order
            }

            // increment customer number
            ++customerNo;
        }

        // exit the program if user input value of 3
        if(burgerChoice == 3)
            break;


        // to enter the burger menu WHILE loop
        contDrinkMenu = 1;

        // display drink menu and get user's input
        while(contDrinkMenu)
        {
            printf("Drink [1.Hot 2.Cold]? ");
            scanf("%d", &drinkChoice);

            switch(drinkChoice)
            {
                case 1:
                    ++totalHotDrinkOrder;    // for daily report
                    contDrinkMenu = 0; // to exit burger menu due to valid input
                    break;
                case 2:
                    ++totalColdDrinkOrder;   //for daily report
                    contDrinkMenu = 0; // to exit burger menu due to valid input
                    break;
            }
        }

        printf("Press [y] for takeaway: ");
        scanf(" %c", &takeAway);

        // convert input to lowercase in case user input is "Y"
        if(tolower(takeAway) == 'y')
            ++noOfTakeAways;

        // tabulate total cost of order by customer
        if(burgerChoice == 1)
        {
            if(drinkChoice == 1)
                totalCost = CHICKENCOST + HOTDRINKCOST;
            else
                totalCost = CHICKENCOST + COLDDRINKCOST;
        }
        else
        {
            if(drinkChoice == 1)
                totalCost = BEEFCOST + HOTDRINKCOST;
            else
                totalCost = BEEFCOST + COLDDRINKCOST;
        }

        // tabulate total earning for daily report
        totalRevenue += totalCost;

        // display result to customer
        printf("Total price: $%.2f\n", totalCost);
        printf("Collection Counter: %d\n\n", collectionCounter);


        ++collectionCounter;

        // prevent collectionCounter from exceeding value of 4
        if(collectionCounter > 4)
            collectionCounter = 1;
    }


    // display daily report
    printf("\n\n=== Daily Report ===\n");
    printf("Number of customers: %d\n", --customerNo);  // --customerNo since it started from 1, not 0
    printf("Total revenue: $%.2f\n", totalRevenue);
    printf("Chicken   : %d,  Beef       :%d\n", totalChickenOrder, totalBeefOrder);
    printf("Hot drink : %d,  Cold drink :%d\n", totalHotDrinkOrder, totalColdDrinkOrder);

    // prevent zero division error as cannot divide something by 0
    if(customerNo != 0)
        takeAwayPecent = ((float)noOfTakeAways/customerNo)*100;

    printf("Takeaway: %d or %.1f%%\n", noOfTakeAways, takeAwayPecent);    // tabulate % of takeaway based on number of orders

    return 0;
}
