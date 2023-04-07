//joshua Khooba
// Professor Ting Tang
//COP3223C Section 1 lab
//Assignment 3

#include <stdio.h>

int main(void) 
{
    double weight, charge;
    int miles;

    /*Asks user to input the weight.*/
    printf("Enter the package weight in pounds: ");
    scanf("%lf", &weight);

    /*Asks user to input the miles.*/
    printf("Enter the shipping distance in miles: ");
    scanf("%d", &miles);

    if (weight > 50) // if the weight is greater than 50 then it ends the program.
    {
        printf("Sorry, we only ship packages of 50 pounds or less.\n");
        return 0;
    }

    int segments = (miles + 499) / 500; // finds the difference in distance to charge in the segments.

    if (weight <= 10) // if the weight is less than 10 then it multiplies the segments by 3 dollars.
    {
        charge = segments * 3;
    } 
    else // if the weight is greater than 10 then it multiples the segemnts by 5 dollars.
    {
        charge = segments * 5;
    }

    if (miles > 1000) // if miles is greater than a 1000 then an extra $10 is added.
    {
        charge += 10;
    }

    printf("Your shipping charge is $%.2lf\n", charge); // prints the charge for user to see.

    return 0;
}
