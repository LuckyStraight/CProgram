#include <stdio.h>

void looppractice();
void update();
void difference();

int main()
{
    looppractice();
    update();
    difference();

    return 0;
}

void looppractice()
{
    for(int x = 0; x < 10; x++)
    {
        printf("x = %d\n", x);
    }
}

void update()
{
    int x = 0;
    printf("x = %d\n", x);

    x++; //post increment counter
    printf("x = %d\n", x);

    x--; //post decrement counter
    printf("x = %d\n", x);

    ++x; //pre increment counter
    printf("x = %d\n", x);

    --x; //pre decrement counter
    printf("x = %d\n", x);
}

void difference()
{
    int x = 1;
    printf("x = %d\n", ++x);

    printf("x = %d\n", x++);

    int val = 2 * ++x;
    printf("val = %d\n", val);



}