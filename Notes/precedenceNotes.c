#include <stdio.h>

int function1();
int function2();
int function3();
int function4();

int main()
{
    if(function1()|| function2() && function3() || function4()) // || is the or, && is the and operators
    {
        printf("success\n");

    }
    else
    {
        printf("not success\n");
    }
    return 0;
}
int function1()
{
    printf("function1\n");
    return 1;
}
int function2()
{
    printf("function2\n");
    return 2;
}
int function3()
{
    printf("function3\n");
    return 3;
}
int function4()
{
    printf("function4\n");
    return 4;
}