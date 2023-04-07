#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[5];
    int size;

    printf("Enter in a size: ");
    scanf("%d", &size);

    int *dynamicarr = (int *) malloc(sizeof(int) * size); //dynamic arry

    for(int x = 0; x < size; ++x)
    {
        dynamicarr[x] = 100 + x;
        printf("dynamicarr[%d] = %d\n", x, dynamicarr[x]);
    }

    //Now I want more memory

    size = size * 2;

    int *temp = (int *) malloc(sizeof(int) * size);
    
    for(int x = 0; x < size / 2; ++x)
    {
        temp[x] = dynamicarr[x];
        printf("temp[%d] = %d\n", x, temp[x]);
    }

    free(dynamicarr);// frees the first dynamic array

    dynamicarr = temp; // gives dynamicarr the doubled variable held in temp.

    free(dynamicarr); //frees the dynamic array that was doubled.


/*2d dynamic arrays*/
    int rows = 2;
    int columns = 3;

    int *arr2d = (int *) malloc(sizeof(int) * rows * columns); // arr2d 24 bytes of memory to hold.

    for( int x = 0; x < rows; ++x)
    {
        for(int y = 0; y < columns; ++y)
        {
            *(arr2d + x * columns + y) = x * y;
            printf("%p + %d * %d + %d = %d\n",arr2d, x, columns, y, x * y);
        }
    }

    free(arr2d);



    return 0;
}