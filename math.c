//joshua Khooba
// Professor Ting Tang
//COP3223C Section 1 lab
//Assignment 2

#include <stdio.h>

int main(void)
{
    int num, num2;

    /*Asks the user to input a value.*/
    printf("Enter the first number: ");
    scanf("%d", &num);

    printf("You entered %d\n", num);

    /*Asks the user to input a second number*/
    printf("Enter the second number: ");
    scanf("%d", &num2);

    printf("You entered %d\n", num2);

    /*Calculates the difference between num and num2*/
    int diff = num - num2;
    printf("The difference is %d.\n", diff);

    /*Calculates the product between num and num2*/
    int prod = num * num2;
    printf("The product is %d.\n", prod);

    /*Calcualtes the square of num*/
    int squ1 = num * num;
    printf("Square of %d is %d.\n",num ,squ1);

    /*Calculates the square of num2*/
    int squ2 = num2 * num2;
    printf("Square of %d is %d.\n",num2 ,squ2);

    printf("Thank you.\n");


    return 0;
}