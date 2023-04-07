#include <stdio.h>
#include <math.h>
#include <ctype.h>

int main()
{
    // square root function

    double value = 9.0;
    double result = sqrt(value);

    printf("The square root of 9 is: %lf\n", result);

    // power calulation

    double x = 10;
    double y = 3;

    printf("power(%.1f,%.1f) = %.1f\n", x, y, pow(x,y));

    //quadratic formula calculation

    double a;
    double b;
    double c;

    printf("Enter the values for a, b, and c:");
    scanf("%lf%lf%lf", &a, &b, &c);

    double insidesqrt = b * b - 4 * a * c;
    
    double plusresult = -b + sqrt(insidesqrt);
    double minusresult = -b - sqrt(insidesqrt);

    double result1 = plusresult / (2 *a);
    double result2 = minusresult / (2 * a);

    printf("result1 = %.slf\n", result1);
    printf("resutl2 = %.2lf\n", result2);

    // random number
    srand(0);
    int num = rand();
    printf("Random Number is %d\n", num);
    
    
    return 0;
}