#include <stdio.h>

void displayarray(int arr[], int size);
void fillarray(int arr[], int size);
void reversedisplay(int arr[], int size);
void copyarray(int arr[], int arr2[], int size);
void arrayhop(int arr[], int size);

int main()
{
    int arr[5];
    fillarray(arr, sizeof(arr)/ sizeof(arr[0]));
    int size = sizeof(arr)/ sizeof(arr[0]);

    int sizearray = sizeof(arr);

    printf("In the main function, the size of the array is %d bytes\n", sizearray);

    for(int x = 0; x < size; ++x)
    {
        printf("arr[%d] = %d\n", x, arr[x]);
    }

    displayarray(arr, size);

    reversedisplay(arr,size);

    int arr2[5];

    copyarray(arr, arr2);


    return 0;
}

void fillarray(int arr[], int size)
{
    for(int x = 0; x < size; ++x)
    {
        arr[x] = x;
    }
}

void reversedisplay(int arr[], int size)
{

}

void displayarray(int arr[], int size)
{
    //int size = sizeof(arr)/ sizeof(arr[0]);
    int sizearray = sizeof(arr);

    printf("In the user defined function, the size of the array is %d bytes\n", sizearray);
    for(int x = 0; x < size; ++x)
    {
        printf("arr[%d] = %d\n", x, arr[x]);

        arr = arr + 1;
    }
}

void copyarray(int arr[], int arr2[], int size)
{
    for(int x = 0; x < size; ++x)
    {
        arr2[x] = arr[x];
    }
}

void arrayhop(int arr[], int size)
{
    int halfway = size / 2;

    int temp = arr[halfway];

    arr[halfway] = arr[0];

    int temp2 = arr[size -1];

    arr[size -1] = temp;

    arr[0] =temp2;
}

