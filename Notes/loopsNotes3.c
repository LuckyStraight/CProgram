#include <stdio.h>

int main()
{
    for(int x = 0; x < 3; ++x)
    {
        printf("Outter Loop\n");

        for(int y = 0; y < 3; ++y)
        {
            printf("Inner Loop\n");
        }
    }

    int x = 100;

    while(x < 5)
    {
        printf("I am here\n");
    }

    int flag = 0;
    int input = 0;

    do{
        printf("Enter a value:\n");
        scanf("%d", &input);

        if(input < 0)
            flag = 1;

    }while(flag == 0);

    printf("out of the do while loop\n");



    return 0;
}