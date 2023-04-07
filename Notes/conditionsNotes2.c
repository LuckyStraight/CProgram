#include <stdio.h>

int main()
{
    int num1 = 3;
    int num2 = 3;

    char ltr = "a";
// using if and else statements normal way, but takes more lines of code
    if(num1 == 3)
    {
        printf("num1 is 3\n");

    }
    if(num1 == 4)
    {
        printf("num1 is 4\n");
    }
    else
    {
        printf("num1 is neither 3 or 4\n");
    }

    switch(num1) //function is much faster than using if and else statements
    {
        case 3:
            printf("num1 is 3\n");
            printf("this is still part of case 3\n");
            break;
        case 4:
            printf("num1 is 4\n");
            break;
        default:
            printf("num1 is neither 3 of 4\n");
            break;
    }
    switch(ltr) //char is case sensitive when using switches
    {
        case 'a':
            printf("case a\n");
        case 'b':
            printf("case b\n");
        default:
            printf("neither letter\n");
    }

    return 0;
}