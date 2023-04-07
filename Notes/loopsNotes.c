#include <stdio.h>

void hello();

int main()
{
    hello();

    int count = 0;

    while(count < 10)
    {
        hello();
        printf("here we go\n");
        
        count += 1;
    }

    int n;
    int ev = 0;

    scanf("%d", &n);

    while(ev < n)
    {
        printf("%3d ", ev);
        ev += 1;
    }

    printf("\n");
    
    return 0;
}

void hello()
{
    printf("Hello World!\n");
}