//COP3223C Section 1
//Small Program 5

#include <stdio.h>

void change(double *due, double *paid);
void resturantReciept();

int main()
{
    double *paid, *due; //variable declaration

    // input the values from the user
    printf("Amount Due: ");
    scanf("%lf", &due);

    printf("Amount Paid: ");
    scanf("%lf", &paid);

    change(&paid, &due); //calls the function change to run the variables.

    return 0;

}

void change(double *paid, double *due)
{

    // declaring the coins values.
    int dollars = 0, quarters = 0, dimes = 0, nickels = 0, pennies = 0;

    double remaining = *paid - *due; //calcualting the amount remaining.

    while(remaining >= 0) // starts the loop.
    {
        if(remaining >= 1.0) // calulates the number of dollars remaining.
        {
            dollars++;
            remaining -= 1.0;
        }
        else if(remaining >= 0.25) // calculates the number of quarters needed.
        {
            quarters++;
            remaining -= 0.25;
        }
        else if(remaining >= 0.1) // calculates the number of dimes needed.
        {
            dimes++;
            remaining -= 0.1;
        }
        else if(remaining >= 0.05) // calculates the number of nickels needed.
        {
            nickels++;
            remaining -= 0.05;
        }
        else if(remaining >= 0.01) // calculates the number of pennies needed.
        {
            pennies++;
            remaining -= 0.01;
        }
        else // stops the loop when there is no more values left to be calculated.
        {
            break;
        }

        printf("%d dollars\n", dollars);
        printf("%d quarters\n", quarters);
        printf("%d dimes\n", dimes);
        printf("%d nickels\n", nickels);
        printf("%d pennies\n", pennies);

    }

}

void resturantReciept()
{
    printf("Welcome to BOb's Burgers! Our burger of the day is Cheese Burger!");

    double order = 0;
    while(order >= 0)
    {
        printf("Please enter your order by selecting the option number. Otherwise type 0 and your order reciept will be printed.\n");
        printf("-----------------------\n");
        printf("1: Regular $5.00\n");
        printf("2: Special $5.95\n");
        printf("3: Cheese $5.50\n");
        printf("4: Fries $2.00\n");
        printf("5: Salad $2.50\n");
        printf("6: Soft Drink $2.00\n");
        printf("-----------------------\n");
            
    }
}
