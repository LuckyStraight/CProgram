#include <stdio.h>

int main()
{
    int arr[5];
    
    int arr2[10] = {1,3,2,5,3,5};

    int index = 1;

    printf("before changing the values");
    for(int x = 0 ; x < 6; ++x)
        printf("arr2[%d] = %d\n", x, arr2[x]);
    
    arr2[index] = arr2[index + 1];
    printf("After Changing the Values");
    for(int x = 0 ; x < 6; ++x)
        printf("arr2[%d] = %d\n", x, arr2[x]);

    index = 4;
    arr2[index -1] = arr2[index];
    printf("Changing the Values a again");
    for(int x = 0 ; x < 6; ++x)
        printf("arr2[%d] = %d\n", x, arr2[x]);
    
    arr[index] = arr[index] - 1;
    arr[index] += 3;

    int size;

    printf("Enter the number of values");
    scanf("%d", &size);

    int result = sizeof(arr);

    printf("Result = sizeof(arr) = %d\n", result);

    int arraysize = sizeof(arr)/ sizeof(arr[0]);

    return 0;
}