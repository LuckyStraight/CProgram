#include <stdio.h>

int main()
{
    int arr [3][4]; //declaration of 2d array

    for(int row = 0; row < 3; ++row)
    {
        for(int column = 0; column < 4; ++column)
        {
            arr[row][column] = row * column;
            printf("%d\t", arr[row][column]);
        }

        printf("\n");
    }

    printf("The size in memory %ld\n", sizeof(arr));
    printf("The size in memory of arr[0] %ld\n", sizeof(arr[0]));

    int arr2[3][3][3]; //declaration of 3d array




    return 0;
}