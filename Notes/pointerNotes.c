#include <stdio.h>

void function1(int x);
void function2();

int main()
{
    int x = 4;
    printf("The address of variable x is %p \n", &x); //%p is the pointer operator. & is the address operator.
    
    int *ptr; // pointer must be of same data type assigned to the variable.
    printf("The address of variable x is %p \n", &ptr); // different address becasue ptr had to  be declared.

    ptr = &x; //assign pointer to the exact address of the variable.

    printf("The address of the variable x is %p \n", &x);
    printf("ptr is pointing to %p \n", ptr);

    function1(x);

    *ptr = -5;// x = -5

    printf("The value of x is %d \n", &x);
    printf("The value of *ptr is %d \n", *ptr);



    return 0;
}

void function1(int x)
{
    printf("Inside function 1, the address of  x is %p \n", &x);
    x = 101;

    printf("Inside function 1, the value of x %d \n", x);

}