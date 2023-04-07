//joshua Khooba
// Professor Ting Tang
//COP3223C Section 1 lab
//lab 2

#include <stdio.h>

int main(void)
{
    /*definig interger variables.*/
    int num, num2;
    
    /*Asks user to input first integer.*/
    printf("Enter integer: ");
    scanf("%d", &num);

    printf("You entered: %d\n", num); // shows what number was entered.

    int squareNum = num * num; // squares num.

    printf("%d squared is %d\n", num, squareNum); // prints the squarenum variable.

    /*Asks user to include a second integer.*/
    printf("Enter another integer: ");
    scanf("%d", &num2);

    int sum = num + num2; // shows the sum of num and num2.

    printf("%d + %d is %d\n", num, num2, sum); // prints the sum

    int product = num * num2; // shows the product of num and num2.

    printf("%d * %d is %d\n", num, num2, product); //prints the product.

    return 0;
}