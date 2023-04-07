#include <stdio.h>

int main()
{
    //declaration statements
    int a;
    double b;
    float c;

    // assignment statements
    a = 32;
    b = .5;
    c = .3;

    char ltr;

    ltr = '5';
    
    a = 2; //resign a to a new value

    double pi = 3.14;

    pi = 3.1415;

    int var = a + 5; //7

    var = var + 2; // 7 + 2 = 9

    printf("var is assigned to %d\n", var);

    printf("pi is %f\n", pi);
    printf("c is %f\n", c);

    printf("ltr is %c\n", ltr);

    printf("var is %d and pi is %f\n", var, pi);

    printf("Enter a value:");
    scanf("%d", &var);
    



    return 0;
}