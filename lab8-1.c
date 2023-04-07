#include <stdio.h>

void swap(int* ptr1, int* ptr2);
void multiplyBy2(double* ptr);

int main()
 {
    // declare and initialize variables
    int a, b;
    
    // prompt user to enter values of a and b
    printf("Enter the value of a: ");
    scanf("%d", &a);

    printf("Enter the value of b: ");
    scanf("%d", &b);
    
    // declare and set pointers
    int *pA = &a, *pB = &b;
    
    // print values and memory addresses using variables
    printf("a = %d, b = %d\n", a, b);
    printf("&a = %p, &b = %p\n", &a, &b);
    
    // print values and memory addresses using pointers
    printf("pA = %p, pB = %p\n", pA, pB);
    printf("*pA = %d, *pB = %d\n", *pA, *pB);
    
    // swap values using function and pointers
    swap(pA, pB);
    
    // print new values of a and b
    printf("a = %d, b = %d\n", a, b);
    
    // declare and set double variable and pointer
    double c = 3.14;
    double *pC = &c;
    
    // print value and memory address of c using pointer
    printf("c = %.2lf\n", c);
    printf("pC = %p\n", pC);
    printf("*pC = %.2lf\n", *pC);
    
    // multiply value of c by 2 using function and pointer
    multiplyBy2(pC);
    
    // print new value of c using variable and pointer
    printf("c = %.2lf\n", c);
    printf("*pC = %.2lf\n", *pC);
    
    return 0;
}



// function to swap two integer values
void swap(int* ptr1, int* ptr2) 
{
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

// function to multiply a double value by 2
void multiplyBy2(double* ptr) 
{
    *ptr *= 2;
}

