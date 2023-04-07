#include <stdio.h>

void function1(int *xptr);
void fucntion2(int *xptr);

int main()
{
    int x = 4;
    printf("The value of x is &d\n", x);
    printf("x is located at %p /n", &x);

    /*int *xptr;
    printf("xptr is located at %p /n", &xptr);

    xptr = &x;
    printf("xptr is POINTING TO ADDRESS %p\n", xptr);

    *xptr = 8;
    
    xptr = 16;
    printf("xptr is Pointing to address %p\n", xptr);

    printf("*xptr = %d\n", *xptr);*/

    int *xptr;

    printf("THe address of xptr in main is %p\n", &xptr);

    xptr = &x;
    printf("The value xptr is pointing to in main is %p\n", xptr);


    function1(&x);

    printf("The value of x AFTER function1 is %d\n", x);



    return 0;
}

void function1(int *xptr)
{
    printf("THe address of xptr in function1 is %p\n", &xptr);
    printf("The value xptr is pointing to in function 1 is %p \n", xptr);

    *xptr = 8;

    function2(xptr);

}

void function2(int *xptr)
{
    printf("THe address of xptr in function1 is %p\n", &xptr);
    printf("The value xptr is pointing to in function 1 is %p \n", xptr);

    *xptr = 1111;

    xptr = NULL;
    *xptr = 1111;
    printf("The value of xptr is pointing to in function2 is %p\n", xptr);

}