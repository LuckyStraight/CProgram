#include <stdio.h>

void function1(int x);


int num = 10; // global variable DO NOT USE AT ALL


int main()
{
    int x = 1;
    printf("Hump day and x = %d\n", x);
    function1(x);

    {
        int y = 1;

        printf("y = %d\n", y);

        printf("Inside the fancy neighborhood. x = %d\n", x); // can see the outside functions to run inside the brackets

    }

    //printf("outside the fancy neighborhood. y = %d\n", y); //cant be seen because it's outiside the second layer brackets


    return 0;
}

void function1(int x)
{
    printf("which x are you? x = %d\n", x);
}