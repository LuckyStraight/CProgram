#include <stdio.h>

int sum(int num1, int num2);
void somefunction(int x, double a, char h);
void differnce();


int main()
{
    int x;

    int a = 3;
    int b = 8;

    x = sum(a,b);

    double val = 4.5
    char ltr = 't'
    somefunction(b, val, ltr);

    printf("Enter two integers please: ");
    scanf("%d%d", &a, &b);

    x = sum(a,b);
    printf("The sum of x is: %d", x);

    differece();



    return 0;

}

/* 
Precondition: num1 and num2 are declared and assign proper values.
Postconditon: result has a proper and
*/

int sum(int num1, int num2)
{
    int result = num1 + num2;
    return result;
}

void somefunction(int x, double a, char h)
{
    printf("Inside Some function\n ");
    printf("x = %d\na = %f\nh = %c\n", x, a, h);
    return;
}

void differnce()
{
    int x;
    int y;

    printf("Enter two values please:");
    scanf("%d%d", &x, &y);

    int result = x - y;

    return result;
}