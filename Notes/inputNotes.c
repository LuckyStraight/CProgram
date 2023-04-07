#include <stdio.h>

int main()
{
    double var;
    printf("enter a double type:");
    scanf(" %lf", &var);
    
    char ltr;
    printf("enter a char type:");
    scanf(" %c", &ltr); //make sure there is white space between the %c 

    printf("var = %lf and ltr = %c\n", var, ltr);
    
    return 0;
}