#include <stdio.h>

int main()
{
    int arr[4];
    arr[0] = 4;
    arr[1] = 9;
    arr[2] = 3;
    arr[3] = -5;

    for(int x = 0; x < 4; ++x)
        printf("arr[%d] = %d\n", x, arr[x]);

    printf("&arr = %p\n", &arr);
    printf("arr = %p\n",arr);
    printf("&arr[0] = %p\n",arr[0]);
    printf("&arr[1] = %p\n",arr[1]);
    printf("&arr[2] = %p\n",arr[2]);
    printf("&arr[3] = %p\n",arr[3]);

    int *ptr = &arr[0];

    printf("*arr = %d\n", *arr);
    
    return 0;
}