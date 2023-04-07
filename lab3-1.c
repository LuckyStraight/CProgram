#include <stdio.h>

void div();
void dollars();
void statistic();

int main(void)
{
    div();
    dollars();
    statistic();

    return 0;
}

void div() 
{
  int userNum, x;
  printf("Do your userNum and x inputs: ");
  scanf("%d %d", &userNum, &x);

/*Divides the userNum by x first time*/
  int result = userNum / x;
  printf("%d ", result);

/*Divides the userNum by x a second time*/
  result = result / x;
  printf("%d ", result);

/*Divides the userNum by x a third time*/
  result = result / x;
  printf("%d\n", result);
}

void dollars()
{
    int quarters, dimes, nickels, pennies;
    printf("Enter in number of quarters, dimes, nickels, and pennies: ");
    scanf("%d %d %d %d", &quarters, &dimes, &nickels, &pennies);

    double total = (quarters * 0.25) + (dimes * 0.10) + (nickels * 0.05) + (pennies * 0.01);
    printf("Amount: $%.2lf\n", total);
}

void statistic()
{
    /*Defined variables */
    int a, b, c, d;
    int product;
    int average;
    float fproduct;
    float favg;

/*Asks user to input integers.*/
    printf("Input 4 integers: ");
    scanf("%d%d%d%d", &a, &b, &c, &d);

    product = a * b * c * d; // calculates the product.
    average = (a + b + c + d) / 4; // Calculates the average
    fproduct = (float) a * b * c * d; // floating point product
    favg = (float) (a + b + c + d) / 4; // floating average

/*Prints the outputs.*/
    printf("%d %d\n", product, average);
    printf("%.3lf %.3lf\n", fproduct, favg);
}