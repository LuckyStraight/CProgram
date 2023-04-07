#include <stdio.h>
#include <stdlib.h>

int find_larger(int a, int b); // function finds the largest value.
int ticket_amount(int limit, int speed); // function finds the ticket amount.
void remove_gray(int red, int green, int blue, int *result); // function removes the gray.


int main(void) 
{
    int a, b;

    /*Asks user to input first value*/
    printf("Enter the first integer: ");
    scanf("%d", &a);

    /*Asks user to input second value*/
    printf("Enter the second integer: ");
    scanf("%d", &b);

    printf("The larger value is: %d\n", find_larger(a, b)); // calls the find_larger function to find the larger value.

    int limit, speed;

    /*Asks user to input a speed limit*/
    printf("Enter the speed limit: ");
    scanf("%d", &limit);

    /*Asks user to input speed the veichile going*/
    printf("Enter the driving speed: ");
    scanf("%d", &speed);

    printf("Ticket amount: $%d\n", ticket_amount(limit, speed)); //calls the ticket_amount function to get the ticket amount.

    int red, green, blue, result[3];

    /*Asks user to input a red value*/
    printf("Enter the red value: ");
    scanf("%d", &red);

    /*Asks user to input a green value*/
    printf("Enter the green value: ");
    scanf("%d", &green);

    /*Asks user to input a blue value*/
    printf("Enter the blue value: ");
    scanf("%d", &blue);

    remove_gray(red, green, blue, result); // calls the remove_gray function.

    printf("After removing the gray: %d %d %d\n", result[0], result[1], result[2]); // prints the results without the gray value.

    return 0;
}

int find_larger(int a, int b) // calls the a and b value from main.
{
    return a > b ? a : b; // returns the largest value.
}

int ticket_amount(int limit, int speed) // calls the limit and speed from main.
{
    /*If the speed is less than or equal to speed limit then no ticket is charged*/
    if (speed <= limit) 
    {
        return 0;
    }

    int over = speed - limit; // calculates the difference between speed and the speed limit.

    /*If the vechile is going over 1 to 5 then $50 charged*/
    if (over <= 5) 
    {
        return 50;
    }
    /*If the vechile is over 6 to 20 then $75 charged*/
    else if (over <= 20) 
    {
        return 75;
    }
    /*If the vechile is over 21 to 40 then $150 is charged*/
    else if (over <= 40) 
    {
        return 150;
    }
    else
    {
        return 300; // If over is over 40 then $300 is charged.
    }
}

void remove_gray(int red, int green, int blue, int *result) 
{
    int minimum = red < green ? (red < blue ? red : blue) : (green < blue ? green : blue); // defines different variations.

    result[0] = red - minimum; // subtracts the red out of the minimum.
    result[1] = green - minimum; // subtracts the green out of the minimum.
    result[2] = blue - minimum; // subtracts the blue out of the minimum.
}

