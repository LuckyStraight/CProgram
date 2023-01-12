#include <stdio.h>

void noise();


int main()
{
    int num1;
    int num2;

    printf("Enter two values: ");
    scanf("%d%d", &num1, &num2);

    if(num1 < num2)
        printf("num1 is smaller than num2.\n");
    else
        printf("num2 is small than num1.\n");
    

    if(num1 != num2)
        printf("num1 does not equal num2\n");
    
    
    if(num1 != num2)
    {
        printf("I can keep printing\n");
        printf("multiple lines can be printed\n");
        printf("unlimited lines of code that can be entered here.\n");

    }
    else
    {
        printf("this is false\n");
        printf("another false output\n");

    }

    if(num1 != num2)
        printf("they're not the same\n");
    else if(num1 < num2)
        printf("num1 is smaller than num2\n");
    else if(num1 > num2)
        printf("num1 is greater than num2\n");
    else
        printf("they're the same\n");

    if (num1 != 0)
        if(num1 != 1)
            if(num1 != 2)
                if(num1 != 3)
                    printf("num1 is neither 0,1,2, or 3\n");

    noise();
        
    return 0;
}

void noise()
{
    int level;

    printf("Please enter the noise level..\n");
    scanf("%d", &level);

    if(level <= 50)
        printf("Quiet\n");
    else if(level <= 70)
        printf("Intrusive\n");
    else if(level <= 90)
        printf("Annoying\n");
    else if(level <= 110)
        printf("Very annoying\n");
    else
        printf("Uncomfortable\n");


}