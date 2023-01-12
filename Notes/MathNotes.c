#include <stdio.h>

int main()
{
    int x = 5;
    int y = 3;

    int sum = x + y; // addition
    int diff = x - y; // subtraction
    int mult = x * y; // multiplication
    int div = x / y; // division
    int remainder = x % y; // mod operator

    printf("%d + %d = %d\n", x, y, sum);
    printf("%d - %d = %d\n", x, y, diff);
    printf("%d * %d = %d\n", x, y, mult);
    printf("%d / %d = %d\n", x, y, div);
    printf("%d %% %d = %d\n", x, y, remainder);

    double n;
    double x = .5;

    return 0;
}