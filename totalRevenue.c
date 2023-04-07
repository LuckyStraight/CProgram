//joshua Khooba
// Professor Ting Tang
//COP3223C Section 1
//Assignment 1

#include <stdio.h>

int main(void) 
{
    // Declare variables for revenue, cost, and profit
    double revenue, cost, profit;

    // Read in values for revenue and cost
    printf("Enter revenue: ");
    scanf("%lf", &revenue);

    printf("Enter cost: ");
    scanf("%lf", &cost);

    // Calculate profit as the difference between revenue and cost
    profit = revenue - cost;

    // Print the result
    printf("Total profit: %.2lf\n", profit);


    return 0;
}
